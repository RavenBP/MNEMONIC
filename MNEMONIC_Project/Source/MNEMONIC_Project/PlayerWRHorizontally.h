// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerWRHorizontally.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerWRHorizontally : public UPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void OnEnterState(AActor* StateOwner) override;
	virtual void TickState() override;
	virtual void OnExitState() override;
	virtual void PressJump() override;
};
