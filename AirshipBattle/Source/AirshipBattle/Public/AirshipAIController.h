// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Airship.h"
#include "AIController.h"
#include "AirshipAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIRSHIPBATTLE_API AAirshipAIController : public AAIController
{
	GENERATED_BODY()

public:
	AAirship* GetControlledAirship() const;

	virtual void BeginPlay() override;
};
