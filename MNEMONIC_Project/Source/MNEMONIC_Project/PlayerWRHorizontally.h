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
	virtual void OnEnterState_Implementation(AActor* StateOwner) override;
	virtual void TickState_Implementation() override;
	virtual void OnExitState_Implementation() override;
	virtual void PressJump_Implementation() override;
};
