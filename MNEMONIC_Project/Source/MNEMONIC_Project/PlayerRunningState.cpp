// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerRunningState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerRunningState::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);

	PlayerRef->m_pParkour->SetCanDash();
}

void UPlayerRunningState::PressJump_Implementation()
{
	Super::PressJump_Implementation();

	PlayerRef->Jump();
}

void UPlayerRunningState::PressSlide_Implementation()
{
	Super::PressSlide_Implementation();

	PlayerRef->StateManager->PushStateByKey("Slide");
}

void UPlayerRunningState::TickState_Implementation()
{
	Super::TickState_Implementation();
	if(PlayerRef->GetCharacterMovement()->Velocity.IsZero())
	{
		PlayerRef->StateManager->PopState();
	}
	if(!PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->PushStateByKey("Air");
	}
}

void UPlayerRunningState::PressMoveForward_Implementation(float Value)
{
	Super::PressMoveForward_Implementation(Value);
}

void UPlayerRunningState::PressMoveRight_Implementation(float Value)
{
	Super::PressMoveRight_Implementation(Value);
}

void UPlayerRunningState::PressSecondaryWeapon_Implementation(bool bValue)
{
	if(isRunning) return;
	Super::PressSecondaryWeapon_Implementation(bValue);
}
