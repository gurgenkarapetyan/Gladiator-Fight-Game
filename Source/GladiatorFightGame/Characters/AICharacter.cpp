// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

#include "GladiatorFightGame/Items/PickableItemBase.h"
#include "GladiatorFightGame/Items/PickableWeapon.h"

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	CreateAndAttachWeapons();
}

void AAICharacter::CreateAndAttachWeapons()
{
	FVector Position = GetActorLocation();
	FRotator Rotation = GetActorRotation();

	if (Shield)
	{
		APickableItemBase* NewShield = Cast<APickableItemBase>(GetWorld()->SpawnActor(Shield, &Position, &Rotation));
		NewShield->AttachItemTo(GetMesh(), TEXT("DualWeaponPoint"));
	}

	
	if (Weapon)
	{
		APickableWeapon* NewWeapon = Cast<APickableWeapon>(GetWorld()->SpawnActor(Weapon, &Position, &Rotation));
		NewWeapon->AttachItemTo(GetMesh(), TEXT("WeaponPoint"));
	}
}

void AAICharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAICharacter::TriggerAttack()
{
	Attack();
}
