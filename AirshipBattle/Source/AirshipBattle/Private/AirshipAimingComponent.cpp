// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAimingComponent.h"
#include "AirshipBarrel.h"
#include "AirshipTurret.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UAirshipAimingComponent::UAirshipAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UAirshipAimingComponent::BeginPlay()
{
	// so can't fire at time = 0
	LastFireTime = FPlatformTime::Seconds();
	RoundsLeft = 3;
}

void UAirshipAimingComponent::Initialise(UAirshipBarrel* PortBarrelToSet, UAirshipTurret* PortTurretToSet)
{
	Barrel = PortBarrelToSet;
	Turret = PortTurretToSet;
}

void UAirshipAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (RoundsLeft <= 0)
	{
		FiringState = EFiringState::OutOfAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Loading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else 
	{
		FiringState = EFiringState::ReadyToFire;
	}
}

EFiringState UAirshipAimingComponent::GetFiringState() const
{
	return FiringState;
}

int32 UAirshipAimingComponent::GetRoundsLeft() const
{
	return RoundsLeft;
}

bool UAirshipAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01);
}

void UAirshipAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }
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
		AimDirection = OutLaunchVelocity.GetSafeNormal();
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

	//Always yaw shortest way for 360° cannons
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Barrel->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Barrel->Rotate(-DeltaRotator.Yaw);
	}

	Turret->Elevate(DeltaRotator.Pitch);
}

void UAirshipAimingComponent::Fire()
{

	if (FiringState == EFiringState::ReadyToFire || FiringState == EFiringState::Aiming)
	{
		//spawn a projectile at the socket location on the barrel
		if (!ensure(ProjectileBlueprint)) { return; }
		if (!ensure(Barrel)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		RoundsLeft--; //takes 1 off ammo count
	}
}