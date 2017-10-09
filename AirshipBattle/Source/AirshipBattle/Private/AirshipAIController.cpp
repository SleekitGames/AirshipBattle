// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAIController.h"
#include "AirshipBattle.h"
#include "Engine/World.h"


void AAirshipAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerAirship = GetPlayerAirship();
	if (!PlayerAirship)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player Airship"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found: %s"), *(PlayerAirship->GetName()));
	}
}

AAirship* AAirshipAIController::GetControlledAirship() const
{
	return Cast<AAirship>(GetPawn());
}

AAirship* AAirshipAIController::GetPlayerAirship() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<AAirship>(PlayerPawn);
}

void AAirshipAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerAirship())
	{
		//TODO Move towards the player
		//Aim at the player
		GetControlledAirship()->AimAt(GetPlayerAirship()->GetActorLocation());
		//Fire if ready
	}

}