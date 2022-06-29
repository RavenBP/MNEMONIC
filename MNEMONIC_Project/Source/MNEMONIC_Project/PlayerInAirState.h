// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerInAirState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerInAirState : public UPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void PressJump_Implementation() override;
	virtual void PressRun_Implementation(bool value) override;
	virtual void TickState_Implementation() override;
	
};
