// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRVertically.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerWRVertically::OnEnterState(AActor* StateOwner)
{
	Super::OnEnterState(StateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, "Enter Vertical State");
	PlayerRef->SetCharacterGravityScale(PlayerRef->m_pParkour->GetRequiredGravity());
}

void UPlayerWRVertically::TickState()
{
	Super::TickState();
	if(PlayerRef->m_pParkour->GetParkourType() != PARKOUR_TYPE::VERTICAL)
	{
		PlayerRef->StateManager->PopState();
	}
	PlayerRef->m_pParkour->Update();
}

void UPlayerWRVertically::OnExitState()
{
	Super::OnExitState();
	PlayerRef->SetCharacterGravityScale(1);
}

void UPlayerWRVertically::PressJump()
{
	Super::PressJump();
	PlayerRef->m_pParkour->JumpOffWall();
}
