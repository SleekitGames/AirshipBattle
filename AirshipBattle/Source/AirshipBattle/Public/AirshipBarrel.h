// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "AirshipBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 = max downward movement. +1 = max upward movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxRotateDegrees = 60;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinRotateDegrees = -60;
};