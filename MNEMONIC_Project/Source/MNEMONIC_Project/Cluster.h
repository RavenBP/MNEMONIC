// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cluster.generated.h"

UCLASS()
class MNEMONIC_PROJECT_API ACluster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACluster();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cluster Settings")
		float clusterActivationRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cluster settings")
	bool isActivated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cluster settings")
	bool displayText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
