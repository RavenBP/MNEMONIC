// Fill out your copyright notice in the Description page of Project Settings.

#include "Parkour.h"

#include "Kismet/KismetSystemLibrary.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

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

	// if(m_pClimbable)
	// {
	// 	// Has climbable surfac
	//
	// 	if(type == HORIZONTAL)
	// 	{
	// 		GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Horizontally climbing."));
	// 		m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fHorizontalSpeed * DeltaTime);
	// 	}
	// 	else if(type == VERTICAL)
	// 	{
	// 		GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Vertically climbing."));
	// 		m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fVerticalSpeed * DeltaTime);
	// 	}
	// 	else if(type == LEDGE)
	// 	{
	// 		return;
	// 	}
	// 	
	// 	const TArray<AActor*> actorsToIgnore = { UpdatedComponent->GetAttachmentRootActor() };
	// 	TArray<AActor*> outActors;
	// 	const TArray<TEnumAsByte<EObjectTypeQuery>> traceObjects = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel3) };
	// 	FHitResult hitResult;
	//
	// 	if(!UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), m_pCharacter->GetActorLocation(), m_pCharacter->GetActorLocation(), 
	// 		m_fDistanceToWall, traceObjects, false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
	// 	{
	// 		GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance 1."));
	// 		m_pClimbable = nullptr;
	// 		m_fTimeForEnabledClimb = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenClimb;
	// 	}
	//
	// 	if(FVector::DistSquared(startPos, m_pCharacter->GetActorLocation()) > m_fDistance * m_fDistance)
	// 	{
	// 		GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance 2."));
	// 		m_pClimbable = nullptr;
	// 		m_fTimeForEnabledClimb = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenClimb;
	// 	}
	// }
	// else if(FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() >= m_fTimeForEnabledClimb)
	// {
	// 	// Does not have climbable surface, find one depending on state.
	//
	// 	const auto camera = m_pCharacter->GetFirstPersonCameraComponent();
	//
	// 	startPos = camera->GetComponentLocation();
	//
	// 	const TArray<AActor*> actorsToIgnore = { UpdatedComponent->GetAttachmentRootActor() };
	// 	TArray<AActor*> outActors;
	//
	// 	FHitResult hitResult;
	// 	const FVector forward = m_pCharacter->GetActorForwardVector();
	// 	const FVector right = m_pCharacter->GetActorRightVector();
	//
	// 	const TArray<TEnumAsByte<EObjectTypeQuery>> traceObjects = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel3) };
	//
	// 	if(UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos + forward * m_fDistanceToWall, traceObjects,
	// 		false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
	// 	{
	// 		// Hit forward
	// 		AClimbable* climbable = Cast<AClimbable>(hitResult.Actor);
	//
	// 		if (climbable)
	// 		{
	// 			if (!climbable->m_bCanClimbVertical) return;
	// 			GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in front: %s"), *climbable->GetFName().ToString()));
	// 			type = VERTICAL;
	// 			//m_fDistance = m_pClimbable->m_fVerticalClimbDistance > m_fVerticalDistance ? m_pClimbable->m_fVerticalClimbDistance : m_fVerticalDistance;
	// 			m_pClimbable = climbable;
	// 		}
	// 	}
	// 	else if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos + right * m_fDistanceToWall, traceObjects,
	// 		false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
	// 	{
	// 		// Hit right
	//
	// 		AClimbable* climbable = Cast<AClimbable/**/>(hitResult.Actor);
	//
	// 		if (climbable)
	// 		{
	// 			if (!climbable->m_bCanClimbHorizontal) return;
	// 			const FVector cross = FVector::CrossProduct(-hitResult.Normal, climbable->GetActorUpVector());
	// 			m_pClimbable = climbable;
	// 			climbDir = cross;
	// 			type = HORIZONTAL;
	// 			m_fDistance = m_pClimbable->m_fHorizontalClimbDistance > m_fHorizontalDistance ? m_pClimbable->m_fHorizontalClimbDistance : m_fHorizontalDistance;
	// 			GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in right: %s"), *climbable->GetFName().ToString()));
	// 		}
	// 	}
	// 	else if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), startPos, startPos - right * m_fDistanceToWall, traceObjects,
	// 		false, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true))
	// 	{
	// 		// Hit left
	//
	// 		AClimbable* climbable = Cast<AClimbable>(hitResult.Actor);
	//
	// 		if (climbable)
	// 		{
	// 			if (!climbable->m_bCanClimbHorizontal) return;
	// 			const FVector cross = FVector::CrossProduct(-hitResult.Normal, climbable->GetActorUpVector());
	// 			m_pClimbable = climbable;
	// 			climbDir = -cross;
	// 			type = HORIZONTAL;
	// 			m_fDistance = m_pClimbable->m_fHorizontalClimbDistance > m_fHorizontalDistance ? m_pClimbable->m_fHorizontalClimbDistance : m_fHorizontalDistance;
	// 			GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in left: %s"), *climbable->GetFName().ToString()));
	// 		}
	// 	}
	// }
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
		// Has climbable surfac

		if(type == PARKOUR_TYPE::HLEFT)
		{
			GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Horizontally climbing."));
			m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fHorizontalSpeed * GetWorld()->GetDeltaSeconds());
		}
		else if(type == PARKOUR_TYPE::VERTICAL)
		{
			GEngine->AddOnScreenDebugMessage(5, 0.1f, FColor::Green, TEXT("Vertically climbing."));
			m_pCharacter->SetActorLocation(m_pCharacter->GetActorLocation() + climbDir * m_fVerticalSpeed * GetWorld()->GetDeltaSeconds());
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
			GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance 1."));
			m_pClimbable = nullptr;
			m_fTimeForEnabledClimb = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenClimb;
		}

		if(FVector::DistSquared(startPos, m_pCharacter->GetActorLocation()) > m_fDistance * m_fDistance)
		{
			GEngine->AddOnScreenDebugMessage(6, 0.1f, FColor::Green, TEXT("Out of climb distance 2."));
			m_pClimbable = nullptr;
			m_fTimeForEnabledClimb = FTimespan::FromSeconds(GetWorld()->GetTimeSeconds()).GetTotalMilliseconds() + m_fTimeBetweenClimb;
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
				GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in front: %s"), *climbable->GetFName().ToString()));
				type = PARKOUR_TYPE::VERTICAL;
				//m_fDistance = m_pClimbable->m_fVerticalClimbDistance > m_fVerticalDistance ? m_pClimbable->m_fVerticalClimbDistance : m_fVerticalDistance;
				m_pClimbable = climbable;
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
				const FVector cross = FVector::CrossProduct(-hitResult.Normal, climbable->GetActorUpVector());
				m_pClimbable = climbable;
				climbDir = cross;
				type = PARKOUR_TYPE::HRIGHT;
				m_fDistance = m_pClimbable->m_fHorizontalClimbDistance > m_fHorizontalDistance ? m_pClimbable->m_fHorizontalClimbDistance : m_fHorizontalDistance;
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
				const FVector cross = FVector::CrossProduct(-hitResult.Normal, climbable->GetActorUpVector());
				m_pClimbable = climbable;
				climbDir = -cross;
				type = PARKOUR_TYPE::HLEFT;
				m_fDistance = m_pClimbable->m_fHorizontalClimbDistance > m_fHorizontalDistance ? m_pClimbable->m_fHorizontalClimbDistance : m_fHorizontalDistance;
				GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable in left: %s"), *climbable->GetFName().ToString()));
			}
		}
	}
}

PARKOUR_TYPE UParkourMovementComponent::GetParkourType()
{
	return type;
}
