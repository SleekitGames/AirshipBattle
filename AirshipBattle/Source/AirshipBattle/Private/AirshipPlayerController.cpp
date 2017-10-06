// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipPlayerController.h"



AAirship* AAirshipPlayerController::GetControlledAirship() const 
{
	return Cast<AAirship>(GetPawn());
}
