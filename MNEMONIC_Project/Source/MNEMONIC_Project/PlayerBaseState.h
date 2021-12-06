// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomPlayerControllerInterface.h"
#include "IState.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "PlayerBaseState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerBaseState : public UIState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	AMNEMONIC_ProjectCharacter* PlayerRef = nullptr;
	ICustomPlayerControllerInterface* PlayerController = nullptr;

	virtual void OnEnterState(AActor* StateOwner) override;
	virtual void OnExitState() override;

protected:
	virtual void PressJump();
	virtual void PressSlide();
	virtual void PressMoveForward(float value);
	virtual void PressMoveRight(float value);
	virtual void PressSecondaryWeapon(bool value);
	
};
