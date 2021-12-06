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
	virtual void OnEnterState(AActor* StateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void PressJump() override;
	virtual void PressMoveRight(float value) override;
	virtual void PressMoveForward(float value) override;

private:
	float fTimer = 0.0f;
	float fSlidingTime = 1.0f;
	FVector vInitialVelocity;
	
};
