// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIdleState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerIdleState::OnEnterState(AActor* StateOwner)
{
	Super::OnEnterState(StateOwner);
	PlayerRef->GetCharacterMovement()->MaxWalkSpeed =PlayerRef->m_pParkour->m_fWalkSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
}

void UPlayerIdleState::PressJump()
{
	Super::PressJump();

	PlayerRef->Jump();
}

void UPlayerIdleState::TickState()
{
	Super::TickState();
	//if is not moving on the ground
	if(!PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PushStateByKey("Air");
	}
}

void UPlayerIdleState::PressMoveForward(float Value)
{
	Super::PressMoveForward(Value);
	if(Value != 0.0f)
	{
		PlayerRef->StateManager->PushStateByKey("Running");
	}
}

void UPlayerIdleState::PressMoveRight(float Value)
{
	Super::PressMoveRight(Value);
	if(Value != 0.0f)
	{
		PlayerRef->StateManager->PushStateByKey("Running");
	}
	
}
