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
	
	//BEGINPLAY
	virtual void BeginPlay() override;


	//TICK
	virtual void Tick(float DeltaTime) override;

	//Start the airship moving the cannon so a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	
	//return an out parameter - true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
