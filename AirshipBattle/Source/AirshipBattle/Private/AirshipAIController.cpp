// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAIController.h"
#include "AirshipAimingComponent.h"
#include "AirshipBattle.h"
#include "Engine/World.h"
#include "Airship.h"
//depends on movement component via pathfinding system


void AAirshipAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AAirshipAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) 
	{
		auto PossessedAirship = Cast<AAirship>(InPawn);
		if (!ensure(PossessedAirship)) { return; }

		//subscribe our local method to airship death event
		PossessedAirship->OnDeath.AddUniqueDynamic(this, &AAirshipAIController::OnPossessedAirshipDeath);
	}
}

void AAirshipAIController::OnPossessedAirshipDeath() 
{
	if(!(GetPawn())){return;}
	GetPawn()->DetachFromControllerPendingDestroy();
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
