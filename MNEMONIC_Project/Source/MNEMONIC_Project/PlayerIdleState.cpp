// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIdleState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerIdleState::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);
	PlayerRef->GetCharacterMovement()->MaxWalkSpeed =PlayerRef->m_pParkour->m_fWalkSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
}

void UPlayerIdleState::PressJump_Implementation()
{
	Super::PressJump_Implementation();

	PlayerRef->Jump();
}

void UPlayerIdleState::TickState_Implementation()
{
	Super::TickState_Implementation();
	//if is not moving on the ground
	if(!PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PushStateByKey("Air");
	}
}

void UPlayerIdleState::PressMoveForward_Implementation(float Value)
{
	Super::PressMoveForward_Implementation(Value);
	if(Value != 0.0f)
	{
		PlayerRef->StateManager->PushStateByKey("Running");
	}
}

void UPlayerIdleState::PressMoveRight_Implementation(float Value)
{
	Super::PressMoveRight_Implementation(Value);
	if(Value != 0.0f)
	{
		PlayerRef->StateManager->PushStateByKey("Running");
	}
	
}

