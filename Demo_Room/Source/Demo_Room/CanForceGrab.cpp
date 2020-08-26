// Fill out your copyright notice in the Description page of Project Settings.


#include "CanForceGrab.h"

// Sets default values
ACanForceGrab::ACanForceGrab()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACanForceGrab::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACanForceGrab::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// What to do when we interact (call force grab)
void ACanForceGrab::OnInteract_Implementation()
{
}

// What to do when we look at this object
void ACanForceGrab::StartFocus_Implementation()
{
}

// What to do when we stop looking at this object
void ACanForceGrab::EndFocus_Implementation()
{
}

// Bring the object towards the player
void ACanForceGrab::Grab(FVector Location)
{
}

// Push the object forward
void ACanForceGrab::Push(FVector Direction)
{
}
