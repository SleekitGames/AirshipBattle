// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipMovementComponent.h"
#include "AirshipRotor.h"

void UAirshipMovementComponent::Initialise(UAirshipRotor* UpperPortRotorToSet, UAirshipRotor* LowerPortRotorToSet, UAirshipRotor* UpperStarboardRotorToSet, UAirshipRotor* LowerStarboardRotorToSet)
{
	if (!UpperPortRotorToSet || !LowerPortRotorToSet || !UpperStarboardRotorToSet || !LowerStarboardRotorToSet) { return; }
	UpperPortRotor = UpperPortRotorToSet;
	LowerPortRotor = LowerPortRotorToSet;
	UpperStarboardRotor = UpperStarboardRotorToSet;
	LowerStarboardRotor = LowerStarboardRotorToSet;
}


void UAirshipMovementComponent::IntendMoveForward(float Throw)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"),Throw);

	UpperPortRotor->SetThrottle(Throw);
	LowerPortRotor->SetThrottle(Throw);
	UpperStarboardRotor->SetThrottle(Throw);
	LowerStarboardRotor->SetThrottle(Throw);
}


