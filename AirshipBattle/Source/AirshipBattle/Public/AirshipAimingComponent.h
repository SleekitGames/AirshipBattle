// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AirshipAimingComponent.generated.h"

class UAirshipBarrel; //forward declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIRSHIPBATTLE_API UAirshipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirshipAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

//TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UAirshipBarrel* Barrel = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
