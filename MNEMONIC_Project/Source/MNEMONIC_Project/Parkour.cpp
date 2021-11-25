// Fill out your copyright notice in the Description page of Project Settings.

#include "Parkour.h"

#include "Climbable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "Camera/CameraComponent.h"

void UParkourMovementComponent::SetCharacter(AMNEMONIC_ProjectCharacter* character)
{
	m_pCharacter = character;
}

void UParkourMovementComponent::TickComponent(float DeltaTime, ELevelTick Tick,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);

	// Start wall check for Parkour using UpdatedComponent (Mesh of Character)

	auto camera = m_pCharacter->GetFirstPersonCameraComponent();

	FVector startPos = camera->GetComponentLocation();
	FVector forward = camera->GetForwardVector();
	FVector right = camera->GetRightVector();

	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(UpdatedComponent->GetAttachmentRootActor());
	TArray<AActor*> outActors;
	FHitResult hitResult;

	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Camera));

	UClass* seekClass = AClimbable::StaticClass();

	/* Sphere overlap, may be useful.
	if(UKismetSystemLibrary::SphereOverlapActors(GetWorld(), startPos, m_fDistanceToWall,
		traceObjectTypes, seekClass, actorsToIgnore, outActors))
	{
		auto actor = outActors[0]; // Closest actor to sphere cast.
		FVector actorRelativePos = actor->GetActorTransform().InverseTransformPosition(startPos);
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Sphere overlap found: %s - Relative pos: %f, %f, %f"), *actor->GetFName().ToString(), actorRelativePos.X, actorRelativePos.Y, actorRelativePos.Z));
	}*/
	
	/*if (UKismetSystemLibrary::SphereTraceSingle(m_pCharacter->GetWorld(), startPos, startPos + forward * m_fDistanceToWall, 20.0f,
		UEngineTypes::ConvertToTraceType(ECC_Camera), true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Red, FLinearColor::Green, 0.2f))
	{
		auto climbable = Cast<AClimbable>(hitResult.Actor);
		if (climbable)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Sphere forward trace found: %s"), *hitResult.Actor->GetFName().ToString()));
		}
	}*/
	
	
	if (UKismetSystemLibrary::LineTraceSingle(m_pCharacter->GetWorld(), startPos, startPos + forward * m_fDistanceToWall,
		UEngineTypes::ConvertToTraceType(ECC_Camera), true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Red, FLinearColor::Green, 0.2f))
	{
		auto climbable = Cast<AClimbable>(hitResult.Actor);
		if(climbable)
		{
			auto bounds = climbable->GetComponentsBoundingBox();
			auto charBounds = m_pCharacter->GetComponentsBoundingBox();
			if (hitResult.ImpactPoint.Z > bounds.Max.Z - 50.0f)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, TEXT("Climbing on top of object."));
				m_pCharacter->SetActorLocation(FVector(startPos.X, startPos.Y, bounds.Max.Z + charBounds.GetSize().Z * 0.5f) + m_pCharacter->GetActorForwardVector() * 2);
				m_pCharacter->GetMesh1P()->ResetAllBodiesSimulatePhysics();
			}
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable on forward: %s"), *hitResult.Actor->GetFName().ToString()));
		}
	}
	else if (UKismetSystemLibrary::LineTraceSingle(m_pCharacter->GetWorld(), startPos, startPos + right * m_fDistanceToWall,
		UEngineTypes::ConvertToTraceType(ECC_Camera), true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Red, FLinearColor::Green, 0.2f))
	{
		auto climbable = Cast<AClimbable>(hitResult.Actor);
		if (climbable)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable on right: %s"), *hitResult.Actor->GetFName().ToString()));
		}
	}
	else if (UKismetSystemLibrary::LineTraceSingle(m_pCharacter->GetWorld(), startPos, startPos - right * m_fDistanceToWall,
		UEngineTypes::ConvertToTraceType(ECC_Camera), true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Red, FLinearColor::Green, 0.2f))
	{
		auto climbable = Cast<AClimbable>(hitResult.Actor);
		if (climbable)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Found climbable on left: %s"), *hitResult.Actor->GetFName().ToString()));
		}
	}
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
