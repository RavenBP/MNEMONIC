// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBaseState.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

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
		PlayerController->GetRunDelegate()->AddUObject(this, &UPlayerBaseState::PressRun);
		PlayerController->GetPrimaryWeaponDelegate()->AddUObject(this, &UPlayerBaseState::PressPrimaryWeapon);
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
		PlayerController->GetRunDelegate()->RemoveAll(this);
		PlayerController->GetMoveForwardDelegate()->RemoveAll(this);
		PlayerController->GetMoveRightDelegate()->RemoveAll(this);
		PlayerController->GetPrimaryWeaponDelegate()->RemoveAll(this);
		PlayerController->GetSecondaryWeaponDelegate()->RemoveAll(this);
	}
}

void UPlayerBaseState::PressJump()
{
}

void UPlayerBaseState::PressSlide()
{
	
}

void UPlayerBaseState::PressRun(bool value)
{
	if(value)
	{
		PlayerRef->GetCharacterMovement()->MaxWalkSpeed = PlayerRef->m_pParkour->m_fRunSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
	}
	else
	{
		PlayerRef->GetCharacterMovement()->MaxWalkSpeed = PlayerRef->m_pParkour->m_fWalkSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
	}
}

void UPlayerBaseState::PressMoveForward(float value)
{
	if(value != 0.0f)
	{
		//just another way of getting the forward vector
		FRotator rotator = FRotator(0.0f, PlayerRef->GetControlRotation().Yaw, 0.0f);
		FVector forwardVector = UKismetMathLibrary::GetForwardVector(rotator);
		PlayerRef->AddMovementInput(forwardVector,value);
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

void UPlayerBaseState::PressPrimaryWeapon(bool value)
{
	if (value == true) //pressed
	{
		if (PlayerRef->Combat.m_pWeapon)
		{
			PlayerRef->Combat.m_pWeapon->OnPressedPrimaryAttack();
			PlayerRef->Combat.m_pWeapon->PlayAnimation(PlayerRef->Combat.m_pWeapon->primaryAnimation, PlayerRef->GetMesh1P());
		}
	}
	else //released
	{
		if (PlayerRef->Combat.m_pWeapon)
		{
			PlayerRef->Combat.m_pWeapon->OnReleasedPrimaryAttack();
		}
	}
}

void UPlayerBaseState::PressSecondaryWeapon(bool value)
{
	if(value == true) //pressed
	{
		if (PlayerRef->Combat.m_pWeapon)
		{
			PlayerRef->Combat.m_pWeapon->OnPressedSecondaryAttack();
			PlayerRef->Combat.m_pWeapon->PlayAnimation(PlayerRef->Combat.m_pWeapon->secondaryAnimation, PlayerRef->GetMesh1P());
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
