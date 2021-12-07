// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Climbable.generated.h"

UCLASS()
class MNEMONIC_PROJECT_API AClimbable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClimbable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		USceneComponent* emptyRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* m_pMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Climb settings")
		bool m_bCanClimbLedge;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Climb settings")
		bool m_bCanClimbHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Climb settings")
		bool m_bCanClimbVertical;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Climb settings")
		float m_fHorizontalClimbDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Climb settings")
		float m_fVerticalClimbDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetMesh();

};
