// Fill out your copyright notice in the Description page of Project Settings.

#include "Climbable.h"
#include "DrawDebugHelpers.h"

// Sets default values
AClimbable::AClimbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	emptyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = emptyRoot;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(emptyRoot);
	m_pMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel3);

	m_bCanClimbHorizontal = true;
	m_bCanClimbVertical = true;
	m_bCanClimbLedge = true;
	
	m_ClimbingStats.m_fHorizontalDistance = 0;
	m_ClimbingStats.m_fHorizontalGravity = 0;
	m_ClimbingStats.m_fHorizontalSpeed = 0;
	m_ClimbingStats.m_fVerticalDistance = 0;
	m_ClimbingStats.m_fVerticalGravity = 0;
	m_ClimbingStats.m_fVerticalSpeed = 0;

	m_ClimbingStats.m_fLateralJumpForce = 0;
	m_ClimbingStats.m_fVerticalJumpForce = 0;
	m_ClimbingStats.m_fForwardJumpForce = 0;
	m_ClimbingStats.m_fBackwardJumpForce = 0;
}

// Called when the game starts or when spawned
void AClimbable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClimbable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

