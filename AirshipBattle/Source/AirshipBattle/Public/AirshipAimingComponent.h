// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AirshipAimingComponent.generated.h"

//forward declaration
class UAirshipBarrel; //Holds barrel's properties and elevate method

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAirshipAimingComponent();

	void SetBarrelReference(UAirshipBarrel* BarrelToSet);

	// TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UAirshipBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};
