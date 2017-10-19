// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "AirshipAimingComponent.generated.h"

class UAirshipBarrel; //forward declaration
class UAirshipTurret; //forward declaration
class AProjectile; //forward declaration

//ENum for aiming state
UENUM()
enum class EFiringState : uint8
	{
		Loading,
		Aiming,
		ReadyToFire,
		OutOfAmmo
	};

//forward declaration
class UAirshipBarrel; //Holds barrel's properties and elevate method
class UAirshipTurret; //Holds turret's properties and elevate method TODO 

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UAirshipBarrel* PortBarrelToSet, UAirshipTurret* PortTurretToSet);

	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Loading;

private:

	// Sets default values for this component's properties
	UAirshipAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UAirshipBarrel* Barrel = nullptr;
	UAirshipTurret* Turret = nullptr;



	//void MoveBarrelTowards(FVector AimDirection);
	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	FVector AimDirection;

	int RoundsLeft = 3;

};
