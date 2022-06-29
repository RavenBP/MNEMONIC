// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomPlayerControllerInterface.h"
#include "IState.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "PlayerBaseState.generated.h"

/**
 * 
 */
UCLASS()
class MNEMONIC_PROJECT_API UPlayerBaseState : public UIState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	AMNEMONIC_ProjectCharacter* PlayerRef = nullptr;
	ICustomPlayerControllerInterface* PlayerController = nullptr;
	bool isRunning = false;
	virtual void OnEnterState_Implementation(AActor* StateOwner) override;
	virtual void OnExitState_Implementation() override;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressJump();
	virtual void PressJump_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressSlide();
	virtual void PressSlide_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressRun(bool value);
	virtual void PressRun_Implementation(bool value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressMoveForward(float value);
	virtual void PressMoveForward_Implementation(float value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressMoveRight(float value);
	virtual void PressMoveRight_Implementation(float value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressPrimaryWeapon(bool value);
	virtual void PressPrimaryWeapon_Implementation(bool value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressSecondaryWeapon(bool value);
	virtual void PressSecondaryWeapon_Implementation(bool value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressTurn(float value);
	virtual void PressTurn_Implementation(float value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressTurnRate(float value);
	virtual void PressTurnRate_Implementation(float value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressLookUp(float value);
	virtual void PressLookUp_Implementation(float value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PressLookUpRate(float value);
	virtual void PressLookUpRate_Implementation(float value);
	
};
