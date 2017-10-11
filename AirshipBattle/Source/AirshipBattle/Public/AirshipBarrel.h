// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "AirshipBarrel.generated.h"

/**
 * 
 */
UCLASS()
class AIRSHIPBATTLE_API UAirshipBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
	
};
