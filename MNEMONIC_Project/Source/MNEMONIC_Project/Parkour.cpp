// Fill out your copyright notice in the Description page of Project Settings.

#include "Parkour.h"
#include "MNEMONIC_ProjectCharacter.h"

void UParkourMovementComponent::SetCharacter(AMNEMONIC_ProjectCharacter* character)
{
	m_pCharacter = character;
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
