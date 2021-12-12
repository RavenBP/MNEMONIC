// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
#include "ClimbingStats.generated.h"

USTRUCT(BlueprintType)
struct FClimbingStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float m_fVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fLateralJumpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalJumpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fForwardJumpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fBackwardJumpForce;
};
