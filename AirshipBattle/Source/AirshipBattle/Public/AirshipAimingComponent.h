// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AirshipAimingComponent.generated.h"

//forward declaration
class UAirshipBarrel; //Holds barrel's properties and elevate method
class UAirshipTurret; //Holds turret's properties and elevate method TODO 

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAirshipAimingComponent();

	void SetBarrelReference(UAirshipBarrel* BarrelToSet);
	void SetTurretReference(UAirshipTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UAirshipBarrel* Barrel = nullptr;
	UAirshipTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
