// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressJump);
	InputComponent->BindAction("Slide", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressSlide);
	InputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressRun);
	InputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleaseRun);
	InputComponent->BindAction("PrimaryFire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressPrimaryFire);
	InputComponent->BindAction("PrimaryFire", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleasePrimaryFire);
	InputComponent->BindAction("SecondaryFire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressSecondaryFire);
	InputComponent->BindAction("SecondaryFire", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleaseSecondaryFire);
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

void ACustomPlayerController::PressSlide()
{
	if(SlideDelegate.IsBound())
	{
		SlideDelegate.Broadcast();
	}
}

void ACustomPlayerController::PressRun()
{
	if(RunDelegate.IsBound())
	{
		RunDelegate.Broadcast(true);
	}
}

void ACustomPlayerController::ReleaseRun()
{
	if (RunDelegate.IsBound())
	{
		RunDelegate.Broadcast(false);
	}
}

void ACustomPlayerController::PressSecondaryFire()
{
	if(SecondaryWeaponDelegate.IsBound())
	{
		SecondaryWeaponDelegate.Broadcast(true);
	}
}

void ACustomPlayerController::ReleaseSecondaryFire()
{
	if(SecondaryWeaponDelegate.IsBound())
	{
		SecondaryWeaponDelegate.Broadcast(false);
	}
}


void ACustomPlayerController::PressPrimaryFire()
{
	if (PrimaryWeaponDelegate.IsBound())
	{
		PrimaryWeaponDelegate.Broadcast(true);
	}
}

void ACustomPlayerController::ReleasePrimaryFire()
{
	if (PrimaryWeaponDelegate.IsBound())
	{
		PrimaryWeaponDelegate.Broadcast(false);
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

FSlideSignature* ACustomPlayerController::GetSlideDelegate()
{
	return &SlideDelegate;
}

FRunSignature* ACustomPlayerController::GetRunDelegate()
{
	return &RunDelegate;
}

FPrimaryWeaponSignature* ACustomPlayerController::GetPrimaryWeaponDelegate()
{
	return &PrimaryWeaponDelegate;
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
