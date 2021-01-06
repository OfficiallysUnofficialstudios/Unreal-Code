// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DestructibleEntity.h"

class UStaticMeshComponent;
class AInteractable;
class ACanForceGrab;

#include "PhysicsCharacter.generated.h"

UCLASS()
class DEMO_ROOM_API APhysicsCharacter : public ADestructibleEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APhysicsCharacter();

	// Variable for the player's Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
		UStaticMeshComponent* MeshComp;

	// Location and Rotation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector SpawnPoint;

	// Casts a line forward in the world look for objects to interact with
	UFUNCTION(BlueprintNativeEvent) // blueprint native because apparently it might actually be easier to edit in blueprints as things get more complicated
		void LineCast();
	void LineCast_Implementation();

	// Called when we want to interact with an object
	void InteractPressed();

	// The distance we should trace forward by when looking for objects
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact")
		float TraceDistance;

	// Hit result when we interact with something
	FHitResult Hit;

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
