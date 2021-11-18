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
	AThrowingWeapon();
	virtual void OnPressedPrimaryAttack() override;
	virtual void OnPressedSecondaryAttack() override;
	virtual void OnReleasedSecondaryAttack() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fRetractSpeed = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fRetractDistance = 2;

private:
	FName socketAttachedName;
	USceneComponent* attachedComponent;
	bool m_bThrowingBack;
};
