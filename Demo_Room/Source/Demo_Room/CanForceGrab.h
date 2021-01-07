// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "CanForceGrab.generated.h"

UCLASS()
class DEMO_ROOM_API ACanForceGrab : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACanForceGrab();

	// Functions inherited from the interact interface

	// What to do when we interact with this object
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract(FHitResult HitResult, AActor* Caller);
	virtual void OnInteract_Implementation(FHitResult HitResult, AActor* Caller);

	// What to do when we look at this object
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void StartFocus();
	virtual void StartFocus_Implementation();

	// What to do when we stop looking at this object
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EndFocus();
	virtual void EndFocus_Implementation();


	// Functions that will handle the stages of force grabbing

	// Drop the object
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void DropForceGrabbable();
	virtual void DropForceGrabbable_Implementation();

	// Push the object forward
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Push();
	virtual void Push_Implementation();

	// Return unit vector given a vector
	UFUNCTION(BlueprintCallable)
	FVector CalculateForceVectorInPlayerDirection(FVector Location, FVector ForwardVector, int Scope, int Magnitude);

	// LATER INCLUDE FUNCTIONS FROM THE PICK UP ACTOR INTERFACE

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
