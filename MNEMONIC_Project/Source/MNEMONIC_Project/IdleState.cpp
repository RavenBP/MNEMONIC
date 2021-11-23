// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "RunningState.h"

UIdleState::UIdleState()
{
}

UIdleState::~UIdleState()
{
}

void UIdleState::enter(AMNEMONIC_ProjectCharacter* character)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Idle State"));
	}
	_character = character;

	_character->m_PlayerInputComponent->BindAxis("MoveForward", this, &UIdleState::StartRunning);
	_character->m_PlayerInputComponent->BindAxis("MoveRight", this, &UIdleState::StartRunning);
	
}

void UIdleState::update(AMNEMONIC_ProjectCharacter* character)
{
	
}


void UIdleState::StartRunning(float Value)
{
	if (Value != 0.0f)
	{
		_character->PushState(NewObject<URunningState>());
	}
}
