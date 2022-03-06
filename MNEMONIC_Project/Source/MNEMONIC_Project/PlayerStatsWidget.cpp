// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetMathLibrary.h"

void UPlayerStatsWidget::NativeOnInitialized()
{
	PlayerCharacter = Cast<AMNEMONIC_ProjectCharacter>(GetOwningPlayerPawn());

	if (PlayerCharacter)
	{
		playerStats = &(PlayerCharacter->m_PlayerStats);
	}
	
	LevelTime = TimeTillStrike * 3;
	nextStrike = TimeTillStrike;
	
	//PlayerCharacter->GetWorldTimerManager().
	//SetTimer(TimerHandle, this, &UPlayerStatsWidget::UpdateTimer, 1.0f, true, 0.0);
    FTimerHandle TimerHandle;
    //PlayerCharacter->GetWorldTimerManager().SetTimer(TimerHandle, this, &UPlayerStatsWidget::UpdateTimer, 1.0f, true, 0.0);
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UPlayerStatsWidget::UpdateTimer, 1.0f, true, 0.0);
}

void UPlayerStatsWidget::UpdateTimer()
{
    if(PlayerCharacter->currentLevelStrikes >= 3)
    {
        if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("GAME OVER"));
    	return;
    }
    
    Seconds++;
    if(progressBarCounter <= LevelTime) progressBarCounter++;
    
    if(Seconds >= 60)
    {
        Seconds = 0;
        Minutes++;
    }
    
    
    if((Seconds + Minutes * 60) >= nextStrike)
    {
        PlayerCharacter->currentLevelStrikes++;
        nextStrike += TimeTillStrike;
        if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NEW STRIKE"));
    }
    
    if(playerStats)
    {
    	FNumberFormattingOptions Opts;
    	Opts.SetMaximumFractionalDigits(0);
    	CorruptionBarLabel->SetText(FText::AsNumber(progressBarCounter, &Opts));
    	CorruptionBar->SetPercent(progressBarCounter / static_cast<float>(LevelTime));
    }
}

void UPlayerStatsWidget::UpdateHealth()
{
	if (playerStats)
	{
		HealthBar->SetPercent(playerStats->m_fCurrentHealth / playerStats->m_fMaxHealth);
		FNumberFormattingOptions Opts;
		Opts.SetMaximumFractionalDigits(0);
		HealthBarLabel->SetText(FText::AsNumber(playerStats->m_fCurrentHealth, &Opts));
	}
}
