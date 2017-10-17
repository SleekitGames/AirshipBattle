// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AirshipAimingComponent.generated.h"

//ENum for aiming state
UENUM()
enum class EFiringState : uint8
	{
		Loading,
		Aiming,
		ReadyToFire
	};

//forward declaration
class UAirshipBarrel; //Holds barrel's properties and elevate method
class UAirshipTurret; //Holds turret's properties and elevate method TODO 

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UAirshipBarrel* PortBarrelToSet, UAirshipTurret* PortTurretToSet);

	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Loading;

private:
	// Sets default values for this component's properties
	UAirshipAimingComponent();

	UAirshipBarrel* Barrel = nullptr;
	UAirshipTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000;
};
