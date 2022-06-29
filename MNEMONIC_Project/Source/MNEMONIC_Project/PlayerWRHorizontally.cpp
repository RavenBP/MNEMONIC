// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRHorizontally.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerWRHorizontally::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, "Enter Horizontal State");
	PlayerRef->SetCharacterGravityScale(PlayerRef->m_pParkour->GetRequiredGravity());
	PlayerRef->SetCharacterVelocity(FVector::ZeroVector);
}

void UPlayerWRHorizontally::TickState_Implementation()
{
	Super::TickState_Implementation();
	PlayerRef->m_pParkour->Update();
}

void UPlayerWRHorizontally::OnExitState_Implementation()
{
	Super::OnExitState_Implementation();
	PlayerRef->ResetCharacterGravity();
}

void UPlayerWRHorizontally::PressJump_Implementation()
{
	Super::PressJump_Implementation();
	PlayerRef->m_pParkour->JumpOffWall();
}
