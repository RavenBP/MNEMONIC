// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerWRHorizontally.h"
#include "PlayerWRHorizontallyLeft.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerWRHorizontallyLeft : public UPlayerWRHorizontally
{
	GENERATED_BODY()

	virtual void TickState_Implementation() override;
};
