// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "IState.generated.h"

class AMNEMONIC_ProjectCharacter;
/**
 * 
 */
UCLASS(Blueprintable)
class MNEMONIC_PROJECT_API UIState : public UObject
{
public:

	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanTickState = false;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	bool bCanRepeat = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateDisplayName;
		

public:
	virtual void OnEnterState(AActor* StateOwner);
	virtual void TickState();
	virtual void OnExitState();
protected:

};
