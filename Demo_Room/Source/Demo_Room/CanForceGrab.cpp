// Fill out your copyright notice in the Description page of Project Settings.

#include "CanForceGrab.h"

#include "DrawDebugHelpers.h"
#include "Math/Vector.h"


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

// What to do when we interact with this object
void ACanForceGrab::OnInteract_Implementation(FHitResult HitResult, AActor* Caller)
{


	// just random debug drawing stuff from earlier
	//FVector HitLocation = HitResult.ImpactPoint;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Hit Location: %s"), *HitLocation.ToString()));

	//FVector ActorLocation = Caller->GetActorLocation();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor Location: %s"), *ActorLocation.ToString()));

	//DrawDebugLine(GetWorld(), HitLocation, ActorLocation, FColor::Magenta, false, 2.0f);

	//FVector PullDirection = HitLocation.operator-(ActorLocation);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Difference: %s"), *PullDirection.ToString()));

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
void ACanForceGrab::Drop_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Cyan, TEXT("Drop"));
}

// Push the object forward
void ACanForceGrab::Push_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Orange, TEXT("Push"));
}
