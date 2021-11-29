// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomPlayerControllerInterface.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API ACustomPlayerController : public APlayerController, public ICustomPlayerControllerInterface
{
	GENERATED_BODY()
public:
	
protected:
	virtual void SetupInputComponent() override;
	void PressJump();
	virtual FJumpSignature* GetJumpDelegate() override;
private:
	FJumpSignature JumpDelegate;
};

