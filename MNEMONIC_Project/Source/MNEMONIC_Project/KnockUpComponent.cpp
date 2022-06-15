// Fill out your copyright notice in the Description page of Project Settings.


#include "KnockUpComponent.h"
#include "Enemy.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UKnockUpComponent::UKnockUpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ownerCharacter = Cast<AEnemy>(GetOwner());
	
	// ...
}

void UKnockUpComponent::KnockUp(float horizontalSpeed, FVector direction)
{
	if(!ownerCharacter)
		ownerCharacter = Cast<AEnemy>(GetOwner());
	
	ownerCharacter->Jump();
}


// Called when the game starts
void UKnockUpComponent::BeginPlay()
{
	Super::BeginPlay();

	
	CapsuleComponent = Cast<UCapsuleComponent>(GetOwner()->GetRootComponent());
	
}


// Called every frame
void UKnockUpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
}

