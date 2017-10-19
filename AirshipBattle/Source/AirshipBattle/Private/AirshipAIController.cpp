// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAIController.h"
#include "AirshipAimingComponent.h"
#include "AirshipBattle.h"
#include "Engine/World.h"
//depends on movement component via pathfinding system


void AAirshipAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UAirshipAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void AAirshipAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerAirship = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledAirship = GetPawn();

	if (!ensure(PlayerAirship && ControlledAirship)) { return; }
	
	//Move towards the player
	MoveToActor(PlayerAirship, AcceptanceRadius); //TODO check radius is in cm

	//Aim at the player
	auto AimingComponent = ControlledAirship->FindComponentByClass<UAirshipAimingComponent>();
	AimingComponent->AimAt(PlayerAirship->GetActorLocation());

	// if locked
	if (AimingComponent->GetFiringState() == EFiringState::ReadyToFire)
	{
		AimingComponent->Fire();
	}
}
