// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleEntity.h"

// Sets default values
ADestructibleEntity::ADestructibleEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestructibleEntity::BeginPlay()
{
	Super::BeginPlay();

	OnTakeAnyDamage.AddDynamic(this, &ADestructibleEntity::TakeDamage);
	
}

// Called every frame
void ADestructibleEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADestructibleEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADestructibleEntity::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

	if (Health == 0) {
		OnDeath();
	}
}

void ADestructibleEntity::OnDeath_Implementation()
{

}