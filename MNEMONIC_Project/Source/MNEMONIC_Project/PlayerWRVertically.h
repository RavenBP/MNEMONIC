// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerWRVertically.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerWRVertically : public UPlayerBaseState
{
	GENERATED_BODY()
	virtual void OnEnterState(AActor* StateOwner) override;
	virtual void TickState() override;
	virtual void OnExitState() override;
	virtual void PressJump() override;
};
