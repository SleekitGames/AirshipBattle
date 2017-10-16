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

	UE_LOG(LogTemp, Warning, TEXT("Donkey Airship C++ Construct"));

}

// Called when the game starts or when spawned
void AAirship::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Donkey Airship C++ Begin Play"));
	
}

void AAirship::AimAt(FVector HitLocation)
{
	if (!ensure(AirshipAimingComponent)) { return; }
	AirshipAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void AAirship::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
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