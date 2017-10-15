// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipMovementComponent.h"
#include "AirshipRotor.h"

void UAirshipMovementComponent::Initialise(UAirshipRotor* UpperPortRotorToSet, UAirshipRotor* LowerPortRotorToSet, UAirshipRotor* UpperStarboardRotorToSet, UAirshipRotor* LowerStarboardRotorToSet)
{
	UpperPortRotor = UpperPortRotorToSet;
	LowerPortRotor = LowerPortRotorToSet;
	UpperStarboardRotor = UpperStarboardRotorToSet;
	LowerStarboardRotor = LowerStarboardRotorToSet;
}


void UAirshipMovementComponent::IntendMoveForward(float Throw)
{
	if (!UpperPortRotor || !LowerPortRotor || !UpperStarboardRotor || !LowerStarboardRotor) { return; }
	UpperPortRotor->SetThrottle(Throw);
	LowerPortRotor->SetThrottle(Throw);
	UpperStarboardRotor->SetThrottle(Throw);
	LowerStarboardRotor->SetThrottle(Throw);

	// TODO prevent double speed with dual control use
}

void UAirshipMovementComponent::IntendTurnRight(float Throw)
{
	if (!UpperPortRotor || !LowerPortRotor || !UpperStarboardRotor || !LowerStarboardRotor) { return; }
	UpperPortRotor->SetThrottle(Throw);
	LowerPortRotor->SetThrottle(Throw);
	UpperStarboardRotor->SetThrottle(-Throw);
	LowerStarboardRotor->SetThrottle(-Throw);

	// TODO prevent double speed with dual control use
}

