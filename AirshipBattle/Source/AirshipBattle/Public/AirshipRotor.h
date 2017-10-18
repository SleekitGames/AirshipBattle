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
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
		float RotorMaxDrivingForce = 10000000; // Assume 100 tonne airship, and 1g accelleration

private:
	UAirshipRotor();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveRotor();

	float CurrentThrottle = 0;
};