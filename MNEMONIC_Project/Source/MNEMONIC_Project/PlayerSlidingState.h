// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerSlidingState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerSlidingState : public UPlayerBaseState
{
	GENERATED_BODY()
protected:
	virtual void OnEnterState_Implementation(AActor* StateOwner) override;
	virtual void OnExitState_Implementation() override;
	virtual void TickState_Implementation() override;
	virtual void PressJump_Implementation() override;
	virtual void PressMoveRight_Implementation(float value) override;
	virtual void PressMoveForward_Implementation(float value) override;

private:
	float fTimer = 0.0f;
	float fSlidingTime = 1.0f;
	FVector vInitialVelocity;
	
};
