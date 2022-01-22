// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/ProgressBar.h"

void UPlayerStatsWidget::NativeOnInitialized()
{
	PlayerCharacter = Cast<AMNEMONIC_ProjectCharacter>(GetOwningPlayerPawn());

	if (PlayerCharacter)
	{
		playerStats = &(PlayerCharacter->m_PlayerStats);
	}
}

void UPlayerStatsWidget::UpdateHealth()
{
	if (playerStats)
	{
		HealthBar->SetPercent(playerStats->m_fCurrentHealth / playerStats->m_fMaxHealth);

		//FNumberFormattingOptions Opts;
		//Opts.SetMaximumFractionalDigits(0);
		//HealthBarLabel->SetText(FText::ToString(TEXT("Hello")));
	}
}