// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h"

UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

private:
	// Sets default values for this pawn's properties
	AAirship();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
