// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBaseState.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void UPlayerBaseState::OnEnterState_Implementation(AActor* StateOwner)
{
	Super::OnEnterState_Implementation(StateOwner);

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
		PlayerController->GetTurnDelegate()->AddUObject(this, &UPlayerBaseState::PressTurn);
		PlayerController->GetTurnRateDelegate()->AddUObject(this, &UPlayerBaseState::PressTurnRate);
		PlayerController->GetLookUpDelegate()->AddUObject(this, &UPlayerBaseState::PressLookUp);
		PlayerController->GetLookUpRateDelegate()->AddUObject(this, &UPlayerBaseState::PressLookUpRate);
	}
}

void UPlayerBaseState::OnExitState_Implementation()
{
	Super::OnExitState_Implementation();
	
	
	if(PlayerController)
	{
		PlayerController->GetJumpDelegate()->RemoveAll(this);
		PlayerController->GetSlideDelegate()->RemoveAll(this);
		PlayerController->GetRunDelegate()->RemoveAll(this);
		PlayerController->GetMoveForwardDelegate()->RemoveAll(this);
		PlayerController->GetMoveRightDelegate()->RemoveAll(this);
		PlayerController->GetPrimaryWeaponDelegate()->RemoveAll(this);
		PlayerController->GetSecondaryWeaponDelegate()->RemoveAll(this);
		PlayerController->GetTurnDelegate()->RemoveAll(this);
		PlayerController->GetTurnRateDelegate()->RemoveAll(this);
		PlayerController->GetLookUpDelegate()->RemoveAll(this);
		PlayerController->GetLookUpRateDelegate()->RemoveAll(this);
	}
}

void UPlayerBaseState::PressJump_Implementation()
{
}

void UPlayerBaseState::PressSlide_Implementation()
{
}

void UPlayerBaseState::PressRun_Implementation(bool value)
{
	///Commenting this stuff out for now since we are going to remove sprint...

	//if(value)
	//{
	//	isRunning = true;
	//	PlayerRef->GetCharacterMovement()->MaxWalkSpeed = PlayerRef->m_pParkour->m_fRunSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
	//}
	//else
	//{
	//	isRunning = false;
	//	PlayerRef->GetCharacterMovement()->MaxWalkSpeed = PlayerRef->m_pParkour->m_fWalkSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed;
	//}

	//GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, FString::Printf(TEXT("value = %f"), PlayerRef->GetCharacterMovement()->MaxWalkSpeed = PlayerRef->m_pParkour->m_fRunSpeed * PlayerRef->m_PlayerStats.m_fMoveSpeed));
}


void UPlayerBaseState::PressMoveForward_Implementation(float value)
{
	if(value != 0.0f)
	{
		//just another way of getting the forward vector
		FRotator rotator = FRotator(0.0f, PlayerRef->GetControlRotation().Yaw, 0.0f);
		FVector forwardVector = UKismetMathLibrary::GetForwardVector(rotator);
		PlayerRef->AddMovementInput(forwardVector,value);
	}
}

void UPlayerBaseState::PressMoveRight_Implementation(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		PlayerRef->AddMovementInput(PlayerRef->GetActorRightVector(),value);
	}
}

void UPlayerBaseState::PressPrimaryWeapon_Implementation(bool value)
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

void UPlayerBaseState::PressSecondaryWeapon_Implementation(bool value)
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

void UPlayerBaseState::PressTurn_Implementation(float value)
{
	if(value != 0.0f)
	{
		PlayerRef->AddControllerYawInput(value);
	}
}

void UPlayerBaseState::PressTurnRate_Implementation(float value)
{
	if(value == 0.0f) return;
	// calculate delta for this frame from the rate information
	PlayerRef->AddControllerYawInput(value * PlayerRef->BaseTurnRate
		* GetWorld()->GetDeltaSeconds());
}

void UPlayerBaseState::PressLookUp_Implementation(float value)
{
	if(value == 0.0f) return;
	PlayerRef->AddControllerPitchInput(value);
}

void UPlayerBaseState::PressLookUpRate_Implementation(float value)
{
	if(value == 0.0f) return;
	PlayerRef->AddControllerPitchInput(value * PlayerRef->BaseLookUpRate
		* GetWorld()->GetDeltaSeconds());
}
