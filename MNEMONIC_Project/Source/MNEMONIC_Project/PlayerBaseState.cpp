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
	}
}

void UPlayerBaseState::OnExitState()
{
	Super::OnExitState();
	
	if(PlayerController)
	{
		PlayerController->GetJumpDelegate()->RemoveAll(this);
	}
}

void UPlayerBaseState::PressJump()
{
	
}
