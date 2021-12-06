// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CustomPlayerControllerInterface.generated.h"

// This class does not need to be modified.
DECLARE_MULTICAST_DELEGATE(FJumpSignature);
DECLARE_MULTICAST_DELEGATE(FSlideSignature);

DECLARE_MULTICAST_DELEGATE_OneParam(FSecondaryWeaponSignature, bool);
DECLARE_MULTICAST_DELEGATE_OneParam(FMoveForwardSignature, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FMoveRightSignature, float);

UINTERFACE(MinimalAPI)
class UCustomPlayerControllerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MNEMONIC_PROJECT_API ICustomPlayerControllerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual FJumpSignature* GetJumpDelegate() = 0;
	virtual FSlideSignature* GetSlideDelegate() = 0;
	virtual FSecondaryWeaponSignature* GetSecondaryWeaponDelegate() = 0;
	virtual FMoveForwardSignature* GetMoveForwardDelegate() = 0;
	virtual FMoveRightSignature* GetMoveRightDelegate() = 0;
};
