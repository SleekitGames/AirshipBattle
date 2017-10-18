// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipRotor.h"

UAirshipRotor::UAirshipRotor()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAirshipRotor::BeginPlay() 
{
	OnComponentHit.AddDynamic(this, &UAirshipRotor::OnHit);
}

void UAirshipRotor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveRotor();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UAirshipRotor::ApplySidewaysForce()
{
	// Work-out the required acceleration this frame to correct
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways (F = m a)
	auto AirshipRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (AirshipRoot->GetMass() * CorrectionAcceleration) / 4; // four rotors
	AirshipRoot->AddForce(CorrectionForce);
}

void UAirshipRotor::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UAirshipRotor::DriveRotor()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * RotorMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto AirshipRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	AirshipRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}