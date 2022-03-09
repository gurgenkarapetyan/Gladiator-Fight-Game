// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickableItemBase.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "PickableWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORFIGHTGAME_API APickableWeapon : public APickableItemBase
{
	GENERATED_BODY()

public:
	APickableWeapon();

	virtual void BeginPlay() override;
	
	UBoxComponent* GetDamageBox() const;

protected:
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* DamageBoxComponent;
};
