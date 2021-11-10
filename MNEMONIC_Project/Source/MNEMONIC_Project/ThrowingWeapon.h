// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "ThrowingWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API AThrowingWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	virtual void PrimaryAttack() override;
	virtual void SecondaryAttack() override;
	
};
