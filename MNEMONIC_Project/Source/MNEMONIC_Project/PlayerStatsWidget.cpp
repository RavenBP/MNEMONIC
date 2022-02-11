// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerStatsWidget::NativeOnInitialized()
{
	PlayerCharacter = Cast<AMNEMONIC_ProjectCharacter>(GetOwningPlayerPawn());

	if (PlayerCharacter)
	{
		playerStats = &(PlayerCharacter->m_PlayerStats);
	}

	//FTimerHandle TimerHandle;
	//PlayerCharacter->GetWorldTimerManager().
	//SetTimer(TimerHandle, this, &UPlayerStatsWidget::UpdateTimer, 1.0f, true, 0.0);
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

void UPlayerStatsWidget::UpdateTimer(float deltaTime)
{
	if(counter >= 1)
	{
		Seconds++;
		if(Seconds >= 60)
		{
			Seconds = 0;
			Minutes++;
			if(Minutes >= MaxTimer_Minutes)
			{
				if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GAME OVER"));
			}
		}
		counter = 0;
	}
	else
	{
		counter += deltaTime;
		if(progressBarCounter <= (MaxTimer_Minutes * 60.0f)) progressBarCounter += deltaTime;

		if(playerStats)
		{
			FNumberFormattingOptions Opts;
			Opts.SetMaximumFractionalDigits(0);
			CorruptionBarLabel->SetText(FText::AsNumber(progressBarCounter, &Opts));
			CorruptionBar->SetPercent(progressBarCounter / (float)(MaxTimer_Minutes * 60.0f));
		}
	}
}
