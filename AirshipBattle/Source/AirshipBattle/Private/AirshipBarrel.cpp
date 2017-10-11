// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipBarrel.h"

void AirshipBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called at speed %f"), *DegreesPerSecond);
}


