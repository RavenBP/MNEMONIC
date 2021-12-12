// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "Climbable.h"
#include "ClimbingStats.h"

/**
 * 
 */
#include "Parkour.generated.h"

enum class PARKOUR_TYPE
{
	NONE,
	HLEFT,
	HRIGHT,
	VERTICAL,
	LEDGE
};

class AMNEMONIC_ProjectCharacter;
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FDashEvent, UParkourMovementComponent, OnDashed);

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
		float m_fDashForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fRunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fDistanceToWall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fTimeBetweenClimb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float m_fTimeBetweenDashes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		FClimbingStats m_ClimbingStats;

	UPROPERTY(BlueprintAssignable, Category = "Dash Event")
		FDashEvent OnDashed;

	//Begin UActorComponent Interface
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void PostLoad() override;
	//End UActorComponent Interface
	
	//Begin UMovementComponent Interface
	virtual float GetMaxSpeed() const override { return MaxSpeed; }
	virtual void InitializeComponent() override;
	virtual void UpdateTickRegistration() override;
	//End UMovementComponent Interface

	//Custom Function
	void Update();
	PARKOUR_TYPE GetParkourType();

	/// <summary>
	/// Stop any active parkour movement if necessary. Removes climbable and sets gravity of character back.
	/// </summary>
	void StopParkourMovement();

	/// <summary>
	/// Force player to jump off the wall they're currently on.
	/// </summary>
	void JumpOffWall();

	/// <summary>
	/// Force player to dash forward.
	/// </summary>
	void Dash();

	/// <summary>
	/// Set the player to be able to dash
	/// </summary>
	/// <param name="enable">Yes/No</param>
	void SetCanDash(bool enable = true);

	float GetRequiredGravity();

private:
	AMNEMONIC_ProjectCharacter* m_pCharacter;

	AClimbable* m_pClimbable;
	FVector startPos;
	FVector climbDir;
	FVector wallNormal;
	float m_fDistance;
	float m_fTimeForEnabledClimb;
	float m_fTimeForEnabledDash;
	float m_fRequiredGravity;
	float m_fRequiredSpeed;
	bool m_bCanDash;
	

	PARKOUR_TYPE type;
};
