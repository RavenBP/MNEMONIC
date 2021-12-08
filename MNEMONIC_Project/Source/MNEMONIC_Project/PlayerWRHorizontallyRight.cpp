// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRHorizontallyRight.h"

void UPlayerWRHorizontallyRight::TickState()
{
	Super::TickState();
	
	if(PlayerRef->m_pParkour->GetParkourType() != PARKOUR_TYPE::HRIGHT)
	{
		PlayerRef->StateManager->PopState();
	}
}
