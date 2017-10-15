// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "AirshipMovementComponent.generated.h"

/**
 * responsible for driving the airship rotors
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class AIRSHIPBATTLE_API UAirshipMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UAirshipRotor* UpperPortRotorToSet, UAirshipRotor* LowerPortRotorToSet, UAirshipRotor* UpperStarboardRotorToSet, UAirshipRotor* LowerStarboardRotorToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float Throw);

	//TODO check best protection method
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;


private:
	UAirshipRotor* UpperPortRotor = nullptr;
	UAirshipRotor* LowerPortRotor = nullptr;
	UAirshipRotor* UpperStarboardRotor = nullptr;
	UAirshipRotor* LowerStarboardRotor = nullptr;
};
