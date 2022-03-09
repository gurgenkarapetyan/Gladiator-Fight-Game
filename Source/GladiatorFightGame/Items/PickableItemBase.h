// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableItemBase.generated.h"

UCLASS()
class GLADIATORFIGHTGAME_API APickableItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	APickableItemBase();

	virtual void Tick(float DeltaTime) override;

	bool AttachItemTo(USkeletalMeshComponent* MeshRoot, FName socket);
	
protected:
	virtual void BeginPlay() override;

protected:
	bool IsUsed;
};
