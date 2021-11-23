// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "IState.generated.h"

class AMNEMONIC_ProjectCharacter;
/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UIState : public UObject
{
public:

	GENERATED_BODY()

		UIState() {}
	virtual ~UIState() {}
	virtual void enter(AMNEMONIC_ProjectCharacter* character) {}
	virtual void update(AMNEMONIC_ProjectCharacter* character) {}
	virtual void exit();

protected:
	AMNEMONIC_ProjectCharacter* _character;
	std::vector<FInputAxisBinding> _listOfInputs;

};
