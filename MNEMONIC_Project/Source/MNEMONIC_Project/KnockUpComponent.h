// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "KnockUpComponent.generated.h"


class AEnemy;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MNEMONIC_PROJECT_API UKnockUpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKnockUpComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = KnockUp)
	float m_fForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = KnockUp)
	float m_fGravityAtTheTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = KnockUp)
	float m_fVelocityThreshold;

	UFUNCTION(BlueprintCallable, Category = KnockUp)
		void KnockUp(float horizontalSpeed, FVector direction);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY()
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY()
	AEnemy* ownerCharacter;
	
	
};
