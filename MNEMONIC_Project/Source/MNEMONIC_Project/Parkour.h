// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"

/**
 * 
 */
#include "Parkour.generated.h"

class AMNEMONIC_ProjectCharacter;

/**
 *
 */
UCLASS(ClassGroup = Movement, meta = (BlueprintSpawnableComponent), ShowCategories = (Velocity))
class MNEMONIC_PROJECT_API UParkourMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:
	void SetCharacter(AMNEMONIC_ProjectCharacter* character);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fDistanceToWall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fVerticalDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fHorizontalDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float MaxSpeed;

	//Begin UActorComponent Interface
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void PostLoad() override;
	//End UActorComponent Interface

	//Begin UMovementComponent Interface
	virtual float GetMaxSpeed() const override { return MaxSpeed; }
	virtual void InitializeComponent() override;
	virtual void UpdateTickRegistration() override;
	//End UMovementComponent Interface

private:
	AMNEMONIC_ProjectCharacter* m_pCharacter;
};
