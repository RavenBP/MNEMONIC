// Fill out your copyright notice in the Description page of Project Settings.

#include "Parkour.h"

#include "Kismet/KismetSystemLibrary.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

void UParkourMovementComponent::SetCharacter(AMNEMONIC_ProjectCharacter* character)
{
	m_pCharacter = character;

	m_fTimeBetweenClimb = 0.2f;
	m_fTimeForEnabledClimb = 0;
}

void UParkourMovementComponent::TickComponent(float DeltaTime, ELevelTick Tick,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);
}

void UParkourMovementComponent::PostLoad()
{
	Super::PostLoad();
}

void UParkourMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UParkourMovementComponent::UpdateTickRegistration()
{
	Super::UpdateTickRegistration();
}

void UParkourMovementComponent::Update()
{
	if(m_pClimbable)
	{
		// Has climbable surface

		GEngine->AddOnScreenDebugMessage(8, 0.1f, FColor::Green, FString::Printf(TEXT("Climb dir: %s."), *climbDir.ToString()));
		if(type == PARKOUR_TYPE::HLEFT || type == PARKOUR_TYPE::HRIGHT)
		{
			GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Horizontally climbing."));
			m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fRequiredSpeed * m_pCharacter->m_PlayerStats.m_fMoveSpeed * GetWorld()->GetDeltaSeconds());
		}
		else if(type == PARKOUR_TYPE::VERTICAL)
		{
			GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Vertically climbing."));
			m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fRequiredSpeed * GetWorld()->GetDeltaSeconds());

			// Ledge climb when at the top of the climbable surface. Feels better without it atm, too fast/teleport-like.
			// It also just uses Z axis which is not good considering the climbable could be any axis. Needs local-to-world Z axis of climbable.
			
			/*FVector origin, box, charOrigin, charBox;
			m_pClimbable->GetActorBounds(true, origin, box);
			m_pCharacter->GetActorBounds(true, charOrigin, charBox);
			GEngine->AddOnScreenDebugMessage(100, 0.1f, FColor::Green, FString::Printf(TEXT("Pos: %s - Box: %s."), *m_pCharacter->GetActorLocation().ToString(), *(origin + box).ToString()));
			if(m_pCharacter->GetActorLocation().Z >= origin.Z + box.Z - charBox.Z)
			{
				GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Hit top, climbing ledge."));
				m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + (m_pCharacter->GetActorUpVector() * charBox.Z * 2));
				m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + m_pCharacter->GetActorForwardVector() * charBox.X * 2);
			}*/
		}
		else if(type == PARKOUR_TYPE::LEDGE)
		{
			return;
		}
		
		const TArray<AActor*> actorsToIgnore = { UpdatedComponent->GetAttachmentRootActor() };
		TArray<AActor*> outActors;
		const TArray<TEnumAsByte<EObjectTypeQuery>> traceObjects = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel3) };
		FHitResult hitResult;

		if(!UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), m_pCharacter->GetActorLocation(), m_pCharacter->GetActorLocation(), 
			m_fDistanceToWall, traceObjects, false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
		{
			GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance. (1)"));
			StopParkourMovement();
		}

		if(FVector::DistSquared(startPos, m_pCharacter->GetActorLocation()) > m_fDistance * m_fDistance)
		{
			GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance. (2)"));
			StopParkourMovement();
		}
	}
	else if(FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() >= m_fTimeForEnabledClimb)
	{
		// Does not have climbable surface, find one depending on state.

		type = PARKOUR_TYPE::NONE;
		const auto camera = m_pCharacter->GetFirstPersonCameraComponent();

		startPos = camera->GetComponentLocation();

		const TArray<AActor*> actorsToIgnore = { UpdatedComponent->GetAttachmentRootActor() };
		TArray<AActor*> outActors;

		FHitResult hitResult;
		const FVector forward = m_pCharacter->GetActorForwardVector();
		const FVector right = m_pCharacter->GetActorRightVector();

		const TArray<TEnumAsByte<EObjectTypeQuery>> traceObjects = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel3) };

		if(UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos + forward * m_fDistanceToWall, traceObjects,
			false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
		{
			// Hit forward
			AClimbable* climbable = Cast<AClimbable>(hitResult.Actor);

			if (climbable)
			{
				if (!climbable->m_bCanClimbVertical) return;
				wallNormal = hitResult.Normal;
				GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in front: %s"), *climbable->GetFName().ToString()));
				type = PARKOUR_TYPE::VERTICAL;
				m_pClimbable = climbable;
				m_fDistance = m_pClimbable->m_ClimbingStats.m_fVerticalDistance > 0 ? m_pClimbable->m_ClimbingStats.m_fVerticalDistance : m_ClimbingStats.m_fVerticalDistance;
				m_fRequiredSpeed = m_pClimbable->m_ClimbingStats.m_fVerticalSpeed > 0 ? m_pClimbable->m_ClimbingStats.m_fVerticalSpeed : m_ClimbingStats.m_fVerticalSpeed;
				m_fRequiredGravity = m_pClimbable->m_ClimbingStats.m_fVerticalGravity > 0 ? m_pClimbable->m_ClimbingStats.m_fVerticalGravity : m_ClimbingStats.m_fVerticalGravity;
				climbDir = m_pClimbable->GetActorUpVector();
			}
		}
		else if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos + right * m_fDistanceToWall, traceObjects,
			false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
		{
			// Hit right

			AClimbable* climbable = Cast<AClimbable/**/>(hitResult.Actor);

			if (climbable)
			{
				if (!climbable->m_bCanClimbHorizontal) return;
				wallNormal = hitResult.Normal;
				const FVector cross = FVector::CrossProduct(-wallNormal, climbable->GetActorUpVector());
				m_pClimbable = climbable;
				climbDir = cross;
				type = PARKOUR_TYPE::HRIGHT;
				m_fDistance = m_pClimbable->m_ClimbingStats.m_fHorizontalDistance > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalDistance : m_ClimbingStats.m_fHorizontalDistance;
				m_fRequiredSpeed = m_pClimbable->m_ClimbingStats.m_fHorizontalSpeed > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalSpeed : m_ClimbingStats.m_fHorizontalSpeed;
				m_fRequiredGravity = m_pClimbable->m_ClimbingStats.m_fHorizontalGravity > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalGravity : m_ClimbingStats.m_fHorizontalGravity;
				GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in right: %s"), *climbable->GetFName().ToString()));
			}
		}
		else if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos - right * m_fDistanceToWall, traceObjects,
			false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
		{
			// Hit left

			AClimbable* climbable = Cast<AClimbable>(hitResult.Actor);

			if (climbable)
			{
				if (!climbable->m_bCanClimbHorizontal) return;
				wallNormal = hitResult.Normal;
				const FVector cross = FVector::CrossProduct(-wallNormal, climbable->GetActorUpVector());
				m_pClimbable = climbable;
				climbDir = -cross;
				type = PARKOUR_TYPE::HLEFT;
				m_fDistance = m_pClimbable->m_ClimbingStats.m_fHorizontalDistance > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalDistance : m_ClimbingStats.m_fHorizontalDistance;
				m_fRequiredSpeed = m_pClimbable->m_ClimbingStats.m_fHorizontalSpeed > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalSpeed : m_ClimbingStats.m_fHorizontalSpeed;
				m_fRequiredGravity = m_pClimbable->m_ClimbingStats.m_fHorizontalGravity > 0 ? m_pClimbable->m_ClimbingStats.m_fHorizontalGravity : m_ClimbingStats.m_fHorizontalGravity;
				GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in left: %s"), *climbable->GetFName().ToString()));
			}
		}
	}
}

PARKOUR_TYPE UParkourMovementComponent::GetParkourType()
{
	return type;
}

void UParkourMovementComponent::StopParkourMovement()
{
	m_pClimbable = nullptr;
	m_fTimeForEnabledClimb = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenClimb;
}

void UParkourMovementComponent::JumpOffWall()
{
	if(m_pClimbable)
	{
		m_bCanDash = true;
		const float lateralJump = m_pClimbable->m_ClimbingStats.m_fLateralJumpForce > 0 ? m_pClimbable->m_ClimbingStats.m_fLateralJumpForce : m_ClimbingStats.m_fLateralJumpForce;
		const float verticalJump = m_pClimbable->m_ClimbingStats.m_fVerticalJumpForce > 0 ? m_pClimbable->m_ClimbingStats.m_fVerticalJumpForce : m_ClimbingStats.m_fVerticalJumpForce;
		//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, FString::Printf(TEXT("Wall normal: %s"), *wallNormal.ToString()));
		m_pCharacter->ResetCharacterGravity();
		if(type == PARKOUR_TYPE::VERTICAL)
		{
			const float backwardJump = m_pClimbable->m_ClimbingStats.m_fBackwardJumpForce > 0 ? m_pClimbable->m_ClimbingStats.m_fBackwardJumpForce : m_ClimbingStats.m_fBackwardJumpForce;
			m_pCharacter->SetCharacterVelocity(climbDir * verticalJump + wallNormal * backwardJump);
		}
		else
		{
			const float forwardJump = m_pClimbable->m_ClimbingStats.m_fForwardJumpForce > 0 ? m_pClimbable->m_ClimbingStats.m_fForwardJumpForce : m_ClimbingStats.m_fForwardJumpForce;
			m_pCharacter->SetCharacterVelocity(climbDir * forwardJump + wallNormal * lateralJump + m_pClimbable->GetActorUpVector() * verticalJump);
		}
		StopParkourMovement();
	}
}

void UParkourMovementComponent::Dash()
{
	if (!m_bCanDash) return;
	if (FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() >= m_fTimeForEnabledDash)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("Dashing!"));
		//m_pCharacter->SetCharacterVelocity(FVector::ZeroVector);
		m_pCharacter->GetCharacterMovement()->AddImpulse(m_pCharacter->GetActorForwardVector() * m_fDashForce);
		m_fTimeForEnabledDash = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenDashes;
		//m_bCanDash = false; // Will be enabled after landing or jumping off wall run.
		OnDashed.Broadcast();
	}
}

void UParkourMovementComponent::SetCanDash(bool enable)
{
	m_bCanDash = enable;
}

float UParkourMovementComponent::GetRequiredGravity()
{
	return m_fRequiredGravity;
}
