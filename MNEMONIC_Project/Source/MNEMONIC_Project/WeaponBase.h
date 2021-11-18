// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponBase.generated.h"

UCLASS()
class MNEMONIC_PROJECT_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USceneComponent* emptyRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* m_pMesh;

	void SetFiringOrigin(USceneComponent* origin);

	virtual void OnPressedPrimaryAttack();
	virtual void OnReleasedPrimaryAttack();
	virtual void OnPressedSecondaryAttack();
	virtual void OnReleasedSecondaryAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* firingOrigin;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
