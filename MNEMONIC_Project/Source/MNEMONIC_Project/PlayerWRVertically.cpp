// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWRVertically.h"

#include "GameFramework/CharacterMovementComponent.h"

void UPlayerWRVertically::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, "Enter Vertical State");
	PlayerRef->SetCharacterGravityScale(PlayerRef->m_pParkour->GetRequiredGravity());
	PlayerRef->SetCharacterVelocity(FVector::ZeroVector);
}

void UPlayerWRVertically::TickState_Implementation()
{
	Super::TickState_Implementation();
	if(PlayerRef->m_pParkour->GetParkourType() != PARKOUR_TYPE::VERTICAL)
	{
		PlayerRef->StateManager->PopState();
	}
	PlayerRef->m_pParkour->Update();
}

void UPlayerWRVertically::OnExitState_Implementation()
{
	Super::OnExitState_Implementation();
	PlayerRef->ResetCharacterGravity();
}

void UPlayerWRVertically::PressJump_Implementation()
{
	Super::PressJump_Implementation();
	PlayerRef->m_pParkour->JumpOffWall();
}
