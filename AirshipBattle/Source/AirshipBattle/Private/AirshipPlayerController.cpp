// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipPlayerController.h"
#include "Airship.h"
#include "AirshipAimingComponent.h"
#include "AirshipBattle.h"


void AAirshipPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedAirship = Cast<AAirship>(InPawn);
		if (!ensure(PossessedAirship)) { return; }

		//subscribe our local method to airship death event
		PossessedAirship->OnDeath.AddUniqueDynamic(this, &AAirshipPlayerController::OnPossessedAirshipDeath);
	}
}

void AAirshipPlayerController::OnPossessedAirshipDeath()
{
	if (!(GetPawn())) { return; }
	StartSpectatingOnly();
}

void AAirshipPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UAirshipAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void AAirshipPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void AAirshipPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } //eg if not possessing
	auto AimingComponent = GetPawn()->FindComponentByClass<UAirshipAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; // Out parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);

	if (bGotHitLocation) // Has "side-effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool AAirshipPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	//find crosshair position on screen (pixels)
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	//deproject screen position of crosshair to world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//linetrace along look direction - see what we hit.
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
		
	return false;
}

bool AAirshipPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //for discarding
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	
}


bool AAirshipPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if(GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Camera)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false; // Line trace didn't succeed
}