// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	emptyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = emptyRoot;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(emptyRoot);

}

void AWeaponBase::SetFiringOrigin(USceneComponent* origin)
{
	firingOrigin = origin;
}

void AWeaponBase::OnPressedPrimaryAttack()
{
}

void AWeaponBase::OnReleasedPrimaryAttack()
{
}

void AWeaponBase::OnPressedSecondaryAttack()
{
}

void AWeaponBase::OnReleasedSecondaryAttack()
{
}

void AWeaponBase::OnWeaponAttached()
{
}

void AWeaponBase::PlayAnimation(UAnimMontage* montage, USkeletalMeshComponent* skelMesh)
{
	if (montage != nullptr)
	{
		UAnimInstance* AnimInstance = skelMesh->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			if (AnimInstance->IsAnyMontagePlaying()) return;
			AnimInstance->Montage_Play(montage, 1.f);
		}
	}
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

