// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipAimingComponent.h"


// Sets default values for this component's properties
UAirshipAimingComponent::UAirshipAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirshipAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAirshipAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAirshipAimingComponent::AimAt(FVector HitLocation)
{
	auto OurAirshipName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *OurAirshipName, *HitLocation.ToString());

}