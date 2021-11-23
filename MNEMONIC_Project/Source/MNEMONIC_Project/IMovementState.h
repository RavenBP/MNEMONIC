// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
/**
 * 
 */
#include "IState.h"
#include "IMovementState.generated.h"
UCLASS()
class MNEMONIC_PROJECT_API UIMovementState : public UIState
{
public:

	GENERATED_BODY()

	UIMovementState();
	~UIMovementState();

	virtual void enter(AMNEMONIC_ProjectCharacter* character);
	virtual void update(AMNEMONIC_ProjectCharacter* character);

private:
	void MoveForward(float);
	void MoveRight(float);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MovementState)
	float _movementSpeed = 0;
	bool _movingForwardOrBackwards = false;
	bool _movingRightOrLeft = false;
};
