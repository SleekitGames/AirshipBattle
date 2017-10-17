// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAimingComponent.h"
#include "AirshipBarrel.h"
#include "AirshipTurret.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UAirshipAimingComponent::UAirshipAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 

	// ...
}

void UAirshipAimingComponent::Initialise(UAirshipBarrel* PortBarrelToSet, UAirshipTurret* PortTurretToSet)
{
	Barrel = PortBarrelToSet;
	Turret = PortTurretToSet;
}

void UAirshipAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!ensure(Barrel)) { return; }
	if (!ensure(Turret)) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace //parameter must be present to prevent bug
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

}

void UAirshipAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	// Work-out difference between current barrel roation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Rotate(DeltaRotator.Yaw);
	Turret->Elevate(DeltaRotator.Pitch);
}
