// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DestructibleEntity.generated.h"

UCLASS()
class DEMO_ROOM_API ADestructibleEntity : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADestructibleEntity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health = 1;

	UFUNCTION(BlueprintNativeEvent)
		void OnDeath();
	void OnDeath_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
