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
	void PressSlide();
	void PressFire();
	void ReleaseFire();
	void PressMoveForward(float value);
	void PressMoveRight(float value);
	virtual FJumpSignature* GetJumpDelegate() override;
	virtual FSlideSignature* GetSlideDelegate() override;
	virtual FSecondaryWeaponSignature* GetSecondaryWeaponDelegate() override;
	virtual FMoveForwardSignature* GetMoveForwardDelegate() override;
	virtual FMoveRightSignature* GetMoveRightDelegate() override;
private:
	FJumpSignature JumpDelegate;
	FSlideSignature SlideDelegate;
	FSecondaryWeaponSignature SecondaryWeaponDelegate;
	FMoveForwardSignature MoveForwardDelegate;
	FMoveRightSignature MoveRightDelegate;
};
