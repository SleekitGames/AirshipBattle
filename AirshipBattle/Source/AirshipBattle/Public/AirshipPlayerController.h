// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Airship.h"
#include "GameFramework/PlayerController.h"
#include "AirshipPlayerController.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class AIRSHIPBATTLE_API AAirshipPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAirship* GetControlledAirship() const;
	
	
};
