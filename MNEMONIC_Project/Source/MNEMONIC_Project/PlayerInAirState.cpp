// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInAirState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerInAirState::PressJump()
{
	Super::PressJump();
	GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Purple, "I am in the air");
}

void UPlayerInAirState::TickState()
{
	Super::TickState();
	if(PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PopState();
	}
}

void UPlayerInAirState::PressMoveRight(float Value)
{
	
}
