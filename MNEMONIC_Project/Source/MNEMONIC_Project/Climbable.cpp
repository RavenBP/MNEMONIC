// Fill out your copyright notice in the Description page of Project Settings.


#include "Climbable.h"

// Sets default values
AClimbable::AClimbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	emptyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = emptyRoot;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(emptyRoot);

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

