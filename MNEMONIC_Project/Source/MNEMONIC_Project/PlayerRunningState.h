// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerRunningState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerRunningState : public UPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void OnEnterState_Implementation(AActor* StateOwner) override;
	virtual void PressJump_Implementation() override;
	virtual void PressSlide_Implementation() override;
	virtual void TickState_Implementation() override;
	virtual void PressMoveForward_Implementation(float value) override;
	virtual void PressMoveRight_Implementation(float value) override;
	virtual void PressSecondaryWeapon_Implementation(bool value) override;
};
