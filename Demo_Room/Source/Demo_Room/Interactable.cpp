// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInteractable::OnInteract_Implementation()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, TEXT("pooopoo"));
	Destroy(); // just for now. intending to add force grab mechanic next.
}

void AInteractable::StartFocus_Implementation()
{
	// this function is filled out in blueprints (colour will change when focused on for now)
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Start Focus"));

}

void AInteractable::EndFocus_Implementation()
{
	// this function is filled out in blueprints (colour will change when focused on for now)
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("End Focus"));

}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



