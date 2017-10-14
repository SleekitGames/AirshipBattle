// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipBarrel.h"

void UAirshipBarrel::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotateChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotate = RelativeRotation.Yaw + RotateChange;
	//auto Rotate = FMath::Clamp<float>(RawNewRotate, MinRotateDegrees, MaxRotateDegrees);
	auto Rotate = RawNewRotate;
	SetRelativeRotation(FRotator(0, Rotate, 0));
}


