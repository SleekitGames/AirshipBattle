// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipRotor.h"

void UAirshipRotor::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: throttle: %f"), *Name, Throttle);

	//TODO clamp actual throttle value so player can't overdrive
}
