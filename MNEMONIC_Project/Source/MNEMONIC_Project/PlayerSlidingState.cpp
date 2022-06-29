// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSlidingState.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

void UPlayerSlidingState::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);
	fTimer = 0.0f;

	//Get last velocity and keep it for the rest of the slide.
	vInitialVelocity = StateOwner->GetVelocity();

	//duck
	PlayerRef->GetCapsuleComponent()->SetCapsuleHalfHeight(48.0f);
}

void UPlayerSlidingState::OnExitState_Implementation()
{
	Super::OnExitState_Implementation();
	//unduck
	PlayerRef->GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
}

void UPlayerSlidingState::TickState_Implementation()
{
	Super::TickState_Implementation();
	PlayerRef->GetMovementComponent()->Velocity = vInitialVelocity;
	//if for some reason we are in the air after sliding we want to cancel the sliding
	if(fTimer > 0.2f && !PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PopState();
	}
	if(fTimer > fSlidingTime)
	{
		PlayerRef->StateManager->PopState();
	}
	fTimer += GetWorld()->GetDeltaSeconds();
}

void UPlayerSlidingState::PressJump_Implementation()
{
}

void UPlayerSlidingState::PressMoveRight_Implementation(float Value)
{
}

void UPlayerSlidingState::PressMoveForward_Implementation(float Value)
{
}
