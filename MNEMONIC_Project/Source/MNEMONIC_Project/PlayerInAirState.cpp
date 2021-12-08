// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInAirState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerInAirState::PressJump()
{
	Super::PressJump();
	if(PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::HLEFT)
	{
		PlayerRef->StateManager->PushStateByKey("HLeft");
	}
	else if(PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::HRIGHT)
	{
		PlayerRef->StateManager->PushStateByKey("HRight");
	}
	else if(PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::VERTICAL)
	{
		PlayerRef->StateManager->PushStateByKey("Vertical");
	}
}

void UPlayerInAirState::TickState()
{
	Super::TickState();
	if(PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PopState();
	}
	PlayerRef->m_pParkour->Update();
}

