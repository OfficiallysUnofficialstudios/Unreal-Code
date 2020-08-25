// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

class UStaticMeshComponent;
class AInteractable;

#include "MotionControllerPawn.generated.h"

UCLASS()
class DEMO_ROOM_API AMotionControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Constructor
	AMotionControllerPawn();

	// Variable for the player's Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* MeshComp;

	// Function that casts a line forward to look for objects to interact with
	// blueprint native because apparently it might actually be easier to edit in blueprints as things get more complicated
	UFUNCTION(BlueprintNativeEvent)
	void LineCast();
	void LineCast_Implementation();

	// called when we see something and want to do something to it (interact with it after line cast)
	void InteractPressed();

	// Variable - the distance we should trace forward by when looking for objects
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact")
	float TraceDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	// Actor we're looking at in the world when we line cast
	AActor* FocusedActor;

};
