// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowingWeapon.h"

void AThrowingWeapon::PrimaryAttack()
{
	Super::PrimaryAttack();
}

void AThrowingWeapon::SecondaryAttack()
{
	Super::SecondaryAttack();
	m_pMesh->SetSimulatePhysics(true);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Throwing weapon!");
	m_pMesh->AddImpulse(firingOrigin->GetForwardVector() * 500);
}
