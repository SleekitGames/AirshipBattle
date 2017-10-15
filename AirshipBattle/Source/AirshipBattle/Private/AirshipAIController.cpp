// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAIController.h"
#include "AirshipBattle.h"
#include "Airship.h"
#include "Engine/World.h"


void AAirshipAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AAirshipAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerAirship = Cast<AAirship>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledAirship = Cast<AAirship>(GetPawn());

	if (PlayerAirship)
	{
		//Move towards the player
		MoveToActor(PlayerAirship, AcceptanceRadius); //TODO check radius is in cm


		//Aim at the player
		ControlledAirship->AimAt(PlayerAirship->GetActorLocation());
		ControlledAirship->Fire(); // TODO - don't fire at time 0
	}
}
