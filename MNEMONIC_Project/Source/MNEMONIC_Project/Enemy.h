// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Statistics.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthEvent, float, health, float, addedHealth);

UCLASS()
class MNEMONIC_PROJECT_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		FStatistics stats;
	
	UPROPERTY(BlueprintAssignable, EditAnywhere, Category = Stats)
		FOnHealthEvent healthEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Widget)
		class UWidgetComponent* healthBar;

	UFUNCTION(BlueprintCallable, Category = Stats)
		void AddHealth(float hp);

	UFUNCTION(BlueprintCallable, Category = Stats)
		float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = Stats)
		float GetMaxHealth();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
