// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipPlayerController.h"
#include "AirshipBattle.h"


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

AAirship* AAirshipPlayerController::GetControlledAirship() const 
{
	return Cast<AAirship>(GetPawn());
}
