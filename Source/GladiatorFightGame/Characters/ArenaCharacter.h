// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaCharacter.generated.h"

class APickableItemBase;
class APickableWeapon;
class UBoxComponent;

UCLASS()
class GLADIATORFIGHTGAME_API AArenaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArenaCharacter();
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool PickShield(APickableItemBase* PickedShield);
	bool PickHammer(APickableWeapon* PickedWeapon);

	void Attack();
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bIsAttacking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bIsAlive= true;

	APickableItemBase* ShieldActor;
	APickableWeapon* WeaponActor;

	UBoxComponent* WeaponCollider;
};
