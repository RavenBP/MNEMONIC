// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
#include "Parkour.generated.h"

class AMNEMONIC_ProjectCharacter;

/**
 *
 */
USTRUCT(BlueprintType) struct FParkour
{
	GENERATED_BODY()

	FParkour();

public:
	void SetCharacter(AMNEMONIC_ProjectCharacter* character);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fDistanceToWall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalDistance;

private:
	AMNEMONIC_ProjectCharacter* m_pCharacter;
};
