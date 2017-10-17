// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "AirshipRotor.generated.h"

/**
 * AirshipRotor is used to set maximum driving force and to move the airship
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class AIRSHIPBATTLE_API UAirshipRotor : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category = Input)
	void SetThrottle(float Throttle);

	//Max force per rotor in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Input)
		float RotorMaxDrivingForce = 20000000;
	
};
