// Fill out your copyright notice in the Description page of Project Settings.

#include "Combat.h"
#include "MNEMONIC_ProjectCharacter.h"

FCombat::FCombat()
{
}

void FCombat::SetCharacter(AMNEMONIC_ProjectCharacter* character)
{
	m_pCharacter = character;
}

void FCombat::CreateWeapon()
{
	if (m_Weapon != nullptr)
	{
		UWorld* const World = m_pCharacter->GetWorld();
		if (World != nullptr)
		{
			m_pWeapon = World->SpawnActor<AWeaponBase>(m_Weapon, m_pCharacter->GetActorLocation(), m_pCharacter->GetActorRotation());
		}
	}
}

void FCombat::AttachWeapon(FName SocketName, const FAttachmentTransformRules rules)
{
	m_pWeapon->AttachToComponent(m_pCharacter->GetMesh1P(), rules, SocketName);
}
