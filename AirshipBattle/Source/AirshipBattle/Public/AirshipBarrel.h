// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "AirshipBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class AIRSHIPBATTLE_API UAirshipBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 = max downward movement. +1 = max upward movement
	void Turn(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxTurnDegrees = 60;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinTurnDegrees = -60;
};