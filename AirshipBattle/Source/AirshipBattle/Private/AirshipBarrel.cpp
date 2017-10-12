// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipBarrel.h"

void UAirshipBarrel::Turn(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto TurnChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewTurn = RelativeRotation.Yaw + TurnChange;
	auto Turn = FMath::Clamp<float>(RawNewTurn, MinTurnDegrees, MaxTurnDegrees);

	SetRelativeRotation(FRotator(0, Turn, Turn));
}


