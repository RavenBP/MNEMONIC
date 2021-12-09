// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRHorizontally.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerWRHorizontally::OnEnterState(AActor* StateOwner)
{
	Super::OnEnterState(StateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, "Enter Horizontal State");
	PlayerRef->SetCharacterEnabledGravity(false);
	PlayerRef->SetCharacterVelocity(FVector::ZeroVector);
}

void UPlayerWRHorizontally::TickState()
{
	Super::TickState();
	PlayerRef->m_pParkour->Update();
}

void UPlayerWRHorizontally::OnExitState()
{
	Super::OnExitState();
	PlayerRef->SetCharacterEnabledGravity(true);
}

void UPlayerWRHorizontally::PressJump()
{
	Super::PressJump();
	PlayerRef->m_pParkour->JumpOffWall();
}
