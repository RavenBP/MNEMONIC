// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	healthBar = CreateDefaultSubobject<UWidgetComponent>("Health bar");

}

void AEnemy::AddHealth(float hp)
{
	stats.m_fCurrentHealth = FMath::Clamp(stats.m_fCurrentHealth + hp, 0.0f, stats.m_fMaxHealth);

	if(healthEvent.IsBound())
		healthEvent.Broadcast(stats.m_fCurrentHealth, hp);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

