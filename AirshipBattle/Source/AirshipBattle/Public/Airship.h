// Copyright 2017 Richard Passe

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h" //must be last include - add others before

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAirshipDelegate);

UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	//returns current health as a percentage of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category ="Health")
	float GetHealthPercent() const;

	FAirshipDelegate OnDeath;

private:
	// Sets default values for this pawn's properties
	AAirship();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth = StartingHealth;

};
