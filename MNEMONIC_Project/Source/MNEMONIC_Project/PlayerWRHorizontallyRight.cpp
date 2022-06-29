// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRHorizontallyRight.h"

void UPlayerWRHorizontallyRight::TickState_Implementation()
{
	Super::TickState_Implementation();
	
	if(PlayerRef->m_pParkour->GetParkourType() != PARKOUR_TYPE::HRIGHT)
	{
		PlayerRef->StateManager->PopState();
	}
}
