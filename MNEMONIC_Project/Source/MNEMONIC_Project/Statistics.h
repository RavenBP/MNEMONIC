// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
#include "Statistics.generated.h"

USTRUCT(BlueprintType)
struct FStatistics
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fMaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fCurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		int m_fNumberOfJumps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fDashCoolDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fAttackValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fAttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fGravityScale;
};
