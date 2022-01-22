// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowingWeapon.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"

AThrowingWeapon::AThrowingWeapon()
{
	m_bThrowingBack = false;
}

void AThrowingWeapon::BeginPlay()
{
	Super::BeginPlay();
	startPos = m_pMesh->GetRelativeLocation();
	startRot = m_pMesh->GetRelativeRotation();
}

void AThrowingWeapon::OnPressedPrimaryAttack()
{
	Super::OnPressedPrimaryAttack();
	// Melee attack her
}

void AThrowingWeapon::OnPressedSecondaryAttack()
{
	Super::OnPressedSecondaryAttack();
	// Start throw here
	/*
	 * Start throw
	 * If weapon is currently simulating physics, this means the weapon is still being thrown.
	 */
	if (!m_pMesh->IsSimulatingPhysics())
	{
		attachedComponent = GetRootComponent()->GetAttachParent();
		socketAttachedName = GetRootComponent()->GetAttachSocketName();

		m_pMesh->SetSimulatePhysics(true);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Throwing weapon!");
		m_pMesh->AddImpulse(firingOrigin->GetForwardVector() * m_fThrowForce, NAME_None, true);
	}
}

void AThrowingWeapon::OnReleasedSecondaryAttack()
{
	Super::OnReleasedSecondaryAttack();
	/*
	 * End throw
	 * Start the process of bringing the weapon back to the socket of the hand.
	 * Will have to get the socket position and start lerping the movement back to hand.
	 * Could also do this with physics
	 */
	if (m_bThrowingBack) return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Bringing weapon back!");m_bThrowingBack = true; // Everything else done on tick.
}

void AThrowingWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(m_bThrowingBack)
	{
		if (!attachedComponent) return;
		const auto socketPos = attachedComponent->GetSocketLocation(socketAttachedName);
		const auto myPos = m_pMesh->GetComponentLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Socket pos: %f, %f, %f - My pos: %f, %f, %f"), socketPos.X, socketPos.Y, socketPos.Z, myPos.X, myPos.Y, myPos.Z));

		auto dir = (socketPos - myPos);

		dir.Normalize();
		
		m_pMesh->SetPhysicsLinearVelocity(dir * m_fRetractSpeed);

		DrawDebugLine(GetWorld(), myPos, socketPos, FColor::Green);

		if(FVector::DistSquared(myPos, socketPos) <= m_fRetractDistance * m_fRetractDistance)
		{
			m_bThrowingBack = false;
			m_pMesh->SetSimulatePhysics(false);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Brought back weapon!"));
			m_pMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			m_pMesh->SetRelativeLocation(startPos);
			m_pMesh->SetRelativeRotation(startRot);
		}
	}
}

void AThrowingWeapon::PlayAnimation(UAnimMontage* montage, USkeletalMeshComponent* skelMesh)
{
	if (m_bThrowingBack) return;
	if (m_pMesh->IsSimulatingPhysics()) return;
	Super::PlayAnimation(montage, skelMesh);
}
