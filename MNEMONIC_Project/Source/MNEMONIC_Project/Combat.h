// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Combat.generated.h"

class AMNEMONIC_ProjectCharacter;

/**
 * 
 */
USTRUCT(BlueprintType) struct FCombat
{
	GENERATED_BODY()

		FCombat();
		
public:

	void SetCharacter(AMNEMONIC_ProjectCharacter* _character);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fAttackSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Weapon)
		TSubclassOf<class AWeaponBase> m_Weapon;

	void CreateWeapon();

	void AttachWeapon(FName SocketName, const FAttachmentTransformRules rules = FAttachmentTransformRules::KeepRelativeTransform);

	AWeaponBase* m_pWeapon;

private:
	AMNEMONIC_ProjectCharacter* m_pCharacter;
};
