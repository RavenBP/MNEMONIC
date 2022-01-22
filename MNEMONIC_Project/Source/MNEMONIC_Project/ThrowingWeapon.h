// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "ThrowingWeapon.generated.h"

class UAnimMontage;
/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API AThrowingWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	AThrowingWeapon();
	virtual void BeginPlay() override;
	virtual void OnPressedPrimaryAttack() override;
	virtual void OnPressedSecondaryAttack() override;
	virtual void OnReleasedSecondaryAttack() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void PlayAnimation(UAnimMontage* montage, USkeletalMeshComponent* skelMesh) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fRetractSpeed = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fRetractDistance = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
		float m_fThrowForce = 500;

private:
	FName socketAttachedName;
	USceneComponent* attachedComponent;
	bool m_bThrowingBack;
	FVector startPos;
	FRotator startRot;
};
