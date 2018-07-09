// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	//how far ahead we can reach in cm
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//raycast and grab what is in reach
	void Grab();
	//releasing grabbed object
	void Release();
	
	void FindPhysicsHandleComponent();

	//setup assumed attached input component
	void SetUpInputComponent();

	//return hit for first hit phys body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	
	//return start of reachline
	FVector GetReachLineStart();
	
	//return current end of reach line
	FVector GetReachLineEnd();
};
