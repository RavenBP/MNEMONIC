// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerIdleState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerIdleState : public UPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void OnEnterState(AActor* StateOwner) override;
	virtual void PressJump() override;
	virtual void TickState() override;
	virtual void PressMoveForward(float value) override;
	virtual void PressMoveRight(float value) override;
	
};
