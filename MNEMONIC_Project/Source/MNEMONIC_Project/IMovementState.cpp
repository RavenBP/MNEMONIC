// Fill out your copyright notice in the Description page of Project Settings.


#include "IMovementState.h"
#include "MNEMONIC_ProjectCharacter.h"

UIMovementState::UIMovementState()
{
}

UIMovementState::~UIMovementState()
{
}

void UIMovementState::enter(AMNEMONIC_ProjectCharacter* character)
{
	_character = character;

	_character->m_PlayerInputComponent->BindAxis("MoveForward", this, &UIMovementState::MoveForward);
	_character->m_PlayerInputComponent->BindAxis("MoveRight", this, &UIMovementState::MoveRight);
}

void UIMovementState::update(AMNEMONIC_ProjectCharacter* character)
{
	
}


void UIMovementState::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		_character->AddMovementInput(_character->GetActorForwardVector(), Value);
		_movingForwardOrBackwards = true;
	}
	else
	{
		_movingForwardOrBackwards = false;
	}
}

void UIMovementState::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		_character->AddMovementInput(_character->GetActorRightVector(), Value);
		_movingRightOrLeft = true;
	}
	else {
		_movingRightOrLeft = false;
	}
}
