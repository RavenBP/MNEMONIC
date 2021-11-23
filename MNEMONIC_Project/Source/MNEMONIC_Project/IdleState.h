// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IState.h"
#include "IdleState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UIdleState : public UIState
{
	GENERATED_BODY()
public:
	UIdleState();
	~UIdleState();
	virtual void enter(AMNEMONIC_ProjectCharacter* character);
	virtual void update(AMNEMONIC_ProjectCharacter* character);
	void StartRunning(float value);
};
