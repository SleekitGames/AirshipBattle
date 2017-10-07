// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAIController.h"
#include "AirshipBattle.h"


void AAirshipAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAirship = GetControlledAirship();
	if (!ControlledAirship)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController Not Possessing An Airship"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Possessing: %s"), *(ControlledAirship->GetName()));
	}
}

AAirship* AAirshipAIController::GetControlledAirship() const
{
	return Cast<AAirship>(GetPawn());
}

