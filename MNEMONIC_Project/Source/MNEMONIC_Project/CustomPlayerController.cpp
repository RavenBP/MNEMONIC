// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressJump);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressFire);
	InputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleaseFire);
	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::PressMoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::PressMoveRight);
	
}

void ACustomPlayerController::PressJump()
{
	if(JumpDelegate.IsBound())
	{
		JumpDelegate.Broadcast();
	}
}

void ACustomPlayerController::PressFire()
{
	if(SecondaryWeaponDelegate.IsBound())
	{
		SecondaryWeaponDelegate.Broadcast(true);
	}
}

void ACustomPlayerController::ReleaseFire()
{
	if(SecondaryWeaponDelegate.IsBound())
	{
		SecondaryWeaponDelegate.Broadcast(false);
	}
}

void ACustomPlayerController::PressMoveForward(float value)
{
	if(MoveForwardDelegate.IsBound())
	{
		MoveForwardDelegate.Broadcast(value);
	}
}

void ACustomPlayerController::PressMoveRight(float value)
{
	if(MoveRightDelegate.IsBound())
	{
		MoveRightDelegate.Broadcast(value);
	}
}

FJumpSignature* ACustomPlayerController::GetJumpDelegate()
{
	return &JumpDelegate;
}

FSecondaryWeaponSignature* ACustomPlayerController::GetSecondaryWeaponDelegate()
{
	return &SecondaryWeaponDelegate;
}


FMoveForwardSignature* ACustomPlayerController::GetMoveForwardDelegate()
{
	return &MoveForwardDelegate;
}

FMoveRightSignature* ACustomPlayerController::GetMoveRightDelegate()
{
	return &MoveRightDelegate;
}
