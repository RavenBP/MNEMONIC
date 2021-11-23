// Fill out your copyright notice in the Description page of Project Settings.

#include "MNEMONIC_ProjectCharacter.h"
#include "RunningState.h"

void URunningState::enter(AMNEMONIC_ProjectCharacter* character)
{
	UIMovementState::enter(character);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Running State"));
	}
	_movingRightOrLeft = true;
	_movingForwardOrBackwards = true;
}

void URunningState::update(AMNEMONIC_ProjectCharacter* character)
{
	if (character->GetVelocity().IsZero() && !_movingRightOrLeft && !_movingForwardOrBackwards)
	{
		character->PopState();
	}
}

