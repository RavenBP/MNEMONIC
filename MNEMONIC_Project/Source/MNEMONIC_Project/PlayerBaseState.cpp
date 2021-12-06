// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBaseState.h"
#include "Kismet/GameplayStatics.h"

void UPlayerBaseState::OnEnterState(AActor* StateOwner)
{
	Super::OnEnterState(StateOwner);

	//Save player ref for later
	if(!PlayerRef)
	{
		PlayerRef = Cast<AMNEMONIC_ProjectCharacter>(StateOwner);
	}
	if(!PlayerController)
	{
		PlayerController = Cast<ICustomPlayerControllerInterface>(UGameplayStatics::GetPlayerController(this, 0));
	}
	
	//Bind delegates for input
	if(PlayerController)
	{
		PlayerController->GetJumpDelegate()->AddUObject(this, &UPlayerBaseState::PressJump);
		PlayerController->GetSlideDelegate()->AddUObject(this, &UPlayerBaseState::PressSlide);
		PlayerController->GetSecondaryWeaponDelegate()->AddUObject(this, &UPlayerBaseState::PressSecondaryWeapon);
		PlayerController->GetMoveForwardDelegate()->AddUObject(this, &UPlayerBaseState::PressMoveForward);
		PlayerController->GetMoveRightDelegate()->AddUObject(this, &UPlayerBaseState::PressMoveRight);
	}
}

void UPlayerBaseState::OnExitState()
{
	Super::OnExitState();
	
	if(PlayerController)
	{
		PlayerController->GetJumpDelegate()->RemoveAll(this);
		PlayerController->GetSlideDelegate()->RemoveAll(this);
		PlayerController->GetMoveForwardDelegate()->RemoveAll(this);
		PlayerController->GetMoveRightDelegate()->RemoveAll(this);
		PlayerController->GetSecondaryWeaponDelegate()->RemoveAll(this);
	}
}

void UPlayerBaseState::PressJump()
{
}

void UPlayerBaseState::PressSlide()
{
	
}

void UPlayerBaseState::PressMoveForward(float value)
{
	if(value != 0.0f)
	{
		PlayerRef->AddMovementInput(PlayerRef->GetActorForwardVector(),value);
	}
}

void UPlayerBaseState::PressMoveRight(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		PlayerRef->AddMovementInput(PlayerRef->GetActorRightVector(),value);
	}
}

void UPlayerBaseState::PressSecondaryWeapon(bool value)
{
	if(value == true) //pressed
	{
		if (PlayerRef->Combat.m_pWeapon)
		{
			PlayerRef->Combat.m_pWeapon->OnPressedSecondaryAttack();
		}
	}
	else //released
	{
		if (PlayerRef->Combat.m_pWeapon)
		{
			PlayerRef->Combat.m_pWeapon->OnReleasedSecondaryAttack();
		}
	}
	
}
