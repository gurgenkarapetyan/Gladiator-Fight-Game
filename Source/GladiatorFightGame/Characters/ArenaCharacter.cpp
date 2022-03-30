// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaCharacter.h"

#include "GladiatorFightGame/Items/PickableItemBase.h"
#include "GladiatorFightGame/Items/PickableWeapon.h"

AArenaCharacter::AArenaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AArenaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArenaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AArenaCharacter::PickShield(APickableItemBase* PickedShield)
{
	if (!PickedShield)
	{
		return false;
	}

	if (!ShieldActor)
	{
		const bool bItemPicked = PickedShield->AttachItemTo(GetMesh(), TEXT("DualWeaponPoint"));
		if (bItemPicked)
		{
			ShieldActor = PickedShield;
			return true;
		}
	}

	return false;
}

bool AArenaCharacter::PickHammer(APickableWeapon* PickedWeapon)
{
	if (!PickedWeapon)
	{
		return false;
	}

	if (!WeaponActor)
	{
		const bool bItemPicked = PickedWeapon->AttachItemTo(GetMesh(), TEXT("WeaponPoint"));
		if (bItemPicked)
		{
			WeaponActor = PickedWeapon;
			WeaponCollider = WeaponActor->GetDamageBox();
			WeaponCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
			return true;
		}
	}

	return false;
}

void AArenaCharacter::Attack()
{
	bIsAttacking = true;
}
