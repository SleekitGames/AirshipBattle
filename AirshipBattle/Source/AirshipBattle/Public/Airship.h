// Copyright 2017 Richard Passe

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h" //must be last include - add others before



UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Sets default values for this pawn's properties
	AAirship();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth = StartingHealth;

};
