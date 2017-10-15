// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipRotor.h"

void UAirshipRotor::SetThrottle(float Throttle)
{


	//TODO clamp actual throttle value so player can't overdrive

	auto ForceApplied = GetForwardVector() * Throttle * RotorMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto AirshipRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	AirshipRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

