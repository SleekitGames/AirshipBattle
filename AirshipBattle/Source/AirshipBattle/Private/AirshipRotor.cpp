// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipRotor.h"

UAirshipRotor::UAirshipRotor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAirshipRotor::BeginPlay() 
{
	OnComponentHit.AddDynamic(this, &UAirshipRotor::OnHit);
}

void UAirshipRotor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I'm hit, I'm hit!"))
}

void UAirshipRotor::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//Super::TickComponent();

	//calculate slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//work out required accelleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calculate and apply sideways force (F=ma)
	auto AirshipRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = AirshipRoot->GetMass() * CorrectionAcceleration / 4; //4 rotors
	AirshipRoot->AddForce(CorrectionForce);
}

void UAirshipRotor::SetThrottle(float Throttle)
{
	//TODO clamp actual throttle value so player can't overdrive

	auto ForceApplied = GetForwardVector() * Throttle * RotorMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto AirshipRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	AirshipRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

