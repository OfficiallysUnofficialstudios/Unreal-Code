// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionControllerPawn.h"

#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "DrawDebugHelpers.h"

#include "InteractInterface.h" // literally dont know why this wouldnt work without the extra directories but ok
#include "Interactable.h"

// Sets default values
AMotionControllerPawn::AMotionControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMotionControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotionControllerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// we're looking for stuff to interact with constantly (always tracing lines forward)
	// there might be a better way to go about this, but this works for now
	LineCast();

}

// Called to bind functionality to input
void AMotionControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("OnInteract", IE_Pressed, this, &AMotionControllerPawn::InteractPressed);

}



// LINE CAST & INTERACT ---------------------------------------------------------------------------------------------------------------- //

void AMotionControllerPawn::LineCast_Implementation() {

	FVector Location;
	FRotator Rotation;
	FHitResult Hit;

	// this function updates Location and Rotation based on the player's POV in the world
	GetController()->GetPlayerViewPoint(Location, Rotation);

	// we start at our current position in the world (Location)
	// we take the vector of our rotation (the direction we're looking in)
	// we multiply it by TraceDistance to essentially create a line of vision where we can detect objects in front of us at desired distance
	FVector End = Location + (Rotation.Vector() * TraceDistance);

	FCollisionQueryParams TraceParams; 	// these are some default parameters to use when casting line forward for now

	// built-in basic line tracing function, returns a hit result (i.e. did we hit something?)
	// ECC_Visibility is a line trace channel, see different trace channels (what you want to hit) in capsule collision settings
	// https://docs.unrealengine.com/en-US/Engine/Physics/Tracing/Overview/index.html ,,, we may need to change it from line to other shape
	bool HitResult = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_Visibility, TraceParams); 
	//DrawDebugLine(GetWorld(), Location, End, FColor::Blue, false, 2.0f);

	if (HitResult == true) {

		// drawing a box to see the hit for now
		//DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(5, 5, 5), FColor::Emerald, false, 2.0f);

		AActor* Interacting = Hit.GetActor(); // get the Actor we hit with our line


		if (Interacting) { // if we've hit an interactable actor...

			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Interacting"));


			if (Interacting != FocusedActor) { // if the hit isn't already our FocusedActor ...

				if (FocusedActor) { // if we have a FocusedActor ...

					// stop focusing on the focused actor (cast to interface so it can use EndFocus)
					IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor);
					if (Interface) {
						Interface->Execute_EndFocus(FocusedActor);
					}
				}

				// start focusing on the actor we just hit (Interacting) 
				IInteractInterface* Interface = Cast<IInteractInterface>(Interacting);
				if (Interface) {
					Interface->Execute_StartFocus(Interacting);
				}

				// the focused actor is now the actor we just hit
				FocusedActor = Interacting;
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("focusedactor set"));


			}

		}

		else { // if we haven't hit an interactable actor...

			if (FocusedActor) { // if we have a focused actor...

				// stop focusing on the focused actor
				IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor);
				if (Interface) {
					Interface->Execute_EndFocus(FocusedActor);
				}
			}

			// remove the value for FocusedActor ("reset" it by setting it to null)
			FocusedActor = nullptr;
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("focusedactor null"));
		}
	}

}


// Currently bound to mouse click (click to interact with an object you focus on)
void AMotionControllerPawn::InteractPressed()
{

	LineCast(); // call LineCast to make a line forward and set the variables we want

	//DrawDebugSphere(GetWorld(), End, 10.0f, 200.0f, FColor::Red, false, 2.0f);


	if (FocusedActor) { // if we have something set for our FocusedActor...
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("something normal"));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf( TEXT("actor: %s"), *GetActorLocation().ToString()));

		// Use InteractInterface to execute OnInteract (do whatever we wanna do to interact with it)
		IInteractInterface* Interface = Cast<IInteractInterface>(FocusedActor);
		if (Interface) {
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, TEXT("poopy"));
			//DrawDebugSphere(GetWorld(), End, 10.0f, 200.0f, FColor::Yellow, false, 2.0f);
			Interface->Execute_OnInteract(FocusedActor);
		}
	}

}

