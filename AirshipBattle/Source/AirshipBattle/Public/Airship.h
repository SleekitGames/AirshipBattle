// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h" //must be last include - add others before

class UAirshipBarrel; //forward declaration
class UAirshipTurret; //forward declaration
class UAirshipAimingComponent; //forward declaration
class AProjectile; //forward declaration

UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BLueprintCallable, Category = Firing)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UAirshipAimingComponent* AirshipAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AAirship();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000; //100m/s TODO find sensible default speed.

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UAirshipBarrel* Barrel = nullptr; //TODO remove

	double LastFireTime = 0;

};
