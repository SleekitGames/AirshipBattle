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
	PrimaryComponentTick.bCanEverTick = true; //TODO should this really tick??

	// ...
}

void UAirshipAimingComponent::SetBarrelReference(UAirshipBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UAirshipAimingComponent::SetTurretReference(UAirshipTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UAirshipAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (!Turret) { return; }
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
		MoveTurretTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: aim solution found"), Time);

	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: no solution found"), Time);
	}
}

void UAirshipAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference between current barrel roation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Turn(DeltaRotator.Pitch); //TODO - work out pitch/yaw/roll
}

void UAirshipAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	// Work-out difference between current barrel roation, and AimDirection
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->Elevate(DeltaRotator.Pitch); //TODO - work out pitch/yaw/roll
}
