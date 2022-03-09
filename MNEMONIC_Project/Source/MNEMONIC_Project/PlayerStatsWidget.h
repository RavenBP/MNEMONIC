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
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CorruptionBarLabel;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HealthBarLabel;
	
	UPROPERTY(meta = (BindWidget))
	UProgressBar* CorruptionBar;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Corruption Timer")
	AMNEMONIC_ProjectCharacter* PlayerCharacter;

	FStatistics* playerStats;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth();
	
	UFUNCTION(BlueprintCallable, Category = "Corruption Timer")
    void UpdateTimer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Corruption Timer")
	int TimeTillStrike = 60; // in seconds

	int nextStrike;
	int LevelTime; // in seconds
	int Minutes = 0;
	int Seconds = 0;
	float counter = 0;
	float progressBarCounter = 0;

protected:
	void NativeOnInitialized() override;
};
