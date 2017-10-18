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
		float RotorMaxDrivingForce = 10000000;
	
private:
	UAirshipRotor();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};
