// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArenaCharacter.h"
#include "AICharacter.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORFIGHTGAME_API AAICharacter : public AArenaCharacter
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

	void CreateAndAttachWeapons();

	UFUNCTION(BlueprintCallable)
	void TriggerAttack();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	TSubclassOf<APickableItemBase> Shield;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	TSubclassOf<APickableWeapon> Weapon;
};
