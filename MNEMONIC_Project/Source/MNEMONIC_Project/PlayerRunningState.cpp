// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerRunningState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerRunningState::PressJump()
{
	Super::PressJump();

	PlayerRef->Jump();
}

void UPlayerRunningState::TickState()
{
	Super::TickState();
	if(PlayerRef->GetCharacterMovement()->Velocity.IsZero())
	{
		PlayerRef->StateManager->PopState();
	}
	if(!PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PushStateByKey("Air");
	}
}

void UPlayerRunningState::PressMoveForward(float Value)
{
	Super::PressMoveForward(Value);
}

void UPlayerRunningState::PressMoveRight(float Value)
{
	Super::PressMoveRight(Value);
}
