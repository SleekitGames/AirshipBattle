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

	//Get world location through crosshair
	//if it hits the landscape
	//tell the cannon to aim at the location 
}