// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIdleState.h"

#include "GameFramework/CharacterMovementComponent.h"

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
		PlayerRef->StateManager->SwitchStateByKey("Air");
	}
}
