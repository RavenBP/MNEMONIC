// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRHorizontallyLeft.h"

void UPlayerWRHorizontallyLeft::TickState()
{
	Super::TickState();
	
	if(PlayerRef->m_pParkour->GetParkourType() != PARKOUR_TYPE::HLEFT)
	{
		PlayerRef->StateManager->PopState();
	}
}
