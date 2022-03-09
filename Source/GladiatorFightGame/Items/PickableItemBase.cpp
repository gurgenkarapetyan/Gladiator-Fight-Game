// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableItemBase.h"

APickableItemBase::APickableItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APickableItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickableItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickableItemBase::AttachItemTo(USkeletalMeshComponent* MeshRoot, FName socket)
{
	return false;
}

