// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h" //must be last include - add others before

class UAirshipBarrel; //forward declaration
class UAirshipTurret; //forward declaration
class UAirshipAimingComponent; //forward declaration

UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BLueprintCallable, Category = Setup)
	void SetBarrelReference(UAirshipBarrel* BarrelToSet);

	UFUNCTION(BLueprintCallable, Category = Setup)
	void SetTurretReference(UAirshipTurret* TurretToSet);

protected:
	UAirshipAimingComponent* AirshipAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AAirship();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000; //100m/s TODO find sensible default speed.
	
};
