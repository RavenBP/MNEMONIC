// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IMovementState.h"
#include "RunningState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API URunningState : public UIMovementState
{
	GENERATED_BODY()

	virtual void enter(AMNEMONIC_ProjectCharacter* character);
	virtual void update(AMNEMONIC_ProjectCharacter* character);
};
