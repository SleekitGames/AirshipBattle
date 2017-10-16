// Fill out your copyright notice in the Description page of Project Settings.

#include "Airship.h"
#include "AirshipBarrel.h"
#include "Projectile.h"
#include "AirshipAimingComponent.h"
#include "AirshipMovementComponent.h"

// Sets default values
AAirship::AAirship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAirship::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAirship::AimAt(FVector HitLocation)
{
	AirshipAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void AAirship::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded)
	{
		//spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}