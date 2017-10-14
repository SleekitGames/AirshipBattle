// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "AirshipTurret.generated.h"

/**
*
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	//-1 = max downward movement. +1 = max upward movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 45;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = -45;
};