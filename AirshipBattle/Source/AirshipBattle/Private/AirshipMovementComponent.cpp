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

void UAirshipMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//no need to call Super as we're replacing functionality
	auto AirshipForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(AirshipForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(AirshipForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);

	//UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *AirshipName, *MoveVelocityString)
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

