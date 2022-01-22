// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "PlayerStatsWidget.generated.h"

/**
 * 
 */

//class UTextBlock;
class UProgressBar;

UCLASS()
class MNEMONIC_PROJECT_API UPlayerStatsWidget : public UUserWidget
{
	GENERATED_BODY()

	

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthBarLabel;
	
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	AMNEMONIC_ProjectCharacter* PlayerCharacter;

	FStatistics* playerStats;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth();

protected:
	void NativeOnInitialized() override;
};
