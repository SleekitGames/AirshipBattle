// Fill out your copyright notice in the Description page of Project Settings.

#include "Airship.h"
#include "AirshipAimingComponent.h"

// Sets default values
AAirship::AAirship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction
	AirshipAimingComponent = CreateDefaultSubobject<UAirshipAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void AAirship::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void AAirship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAirship::AimAt(FVector HitLocation)
{
	AirshipAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void AAirship::SetBarrelReference(UAirshipBarrel* BarrelToSet)
{
	AirshipAimingComponent->SetBarrelReference(BarrelToSet);
}

void AAirship::SetTurretReference(UAirshipTurret* TurretToSet)
{
	AirshipAimingComponent->SetTurretReference(TurretToSet);
}

void AAirship::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Airship fires"), Time);
}