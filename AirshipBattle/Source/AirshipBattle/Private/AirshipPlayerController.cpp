// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipPlayerController.h"
#include "AirshipBattle.h"


//Tick
//Super
//AimTowardsCrosshair



void AAirshipPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledAirship = GetControlledAirship();
	if (!ControlledAirship)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController Not Possessing An Airship"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing: %s"), *(ControlledAirship->GetName()));
	}
}

void AAirshipPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AAirship* AAirshipPlayerController::GetControlledAirship() const 
{
	return Cast<AAirship>(GetPawn());
}

void AAirshipPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledAirship()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLoaction: %s"), *HitLocation.ToString());
		// TODO Tell controlled airship to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool AAirshipPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
