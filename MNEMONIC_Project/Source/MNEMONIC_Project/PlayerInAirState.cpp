// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInAirState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerInAirState::PressJump_Implementation()
{
	Super::PressJump_Implementation();
}

void UPlayerInAirState::PressRun_Implementation(bool value)
{
	Super::PressRun_Implementation(value);

	if(value)
		PlayerRef->m_pParkour->Dash();
}

void UPlayerInAirState::TickState_Implementation()
{
	Super::TickState_Implementation();
	if(PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PopState();
	}

	PlayerRef->m_pParkour->Update();

	if (PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::HLEFT)
	{
		PlayerRef->StateManager->PushStateByKey("HLeft");
	}
	else if (PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::HRIGHT)
	{
		PlayerRef->StateManager->PushStateByKey("HRight");
	}
	else if (PlayerRef->m_pParkour->GetParkourType() == PARKOUR_TYPE::VERTICAL)
	{
		PlayerRef->StateManager->PushStateByKey("Vertical");
	}
}

