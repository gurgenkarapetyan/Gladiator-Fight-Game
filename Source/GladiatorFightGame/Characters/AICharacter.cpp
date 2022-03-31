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

		WeaponCollider = NewWeapon->GetDamageBox();
		if (WeaponCollider)
		{
			WeaponCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			WeaponCollider->OnComponentBeginOverlap.AddDynamic(this, &AAICharacter::OnWeaponBeginOverlap);
		}
	}
}

void AAICharacter::OnWeaponBeginOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		if (bCanDetectCollision)
		{
			bCanDetectCollision = false;
			UE_LOG(LogTemp, Warning, TEXT("Collided with player"));
		}
	}
}

void AAICharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (bIsAttacking)
	{
		if (WeaponCollider)
		{
			WeaponCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
	}
	else
	{
		if (WeaponCollider)
		{
			WeaponCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		
		if (bCanDetectCollision)
		{
			bCanDetectCollision = false;
		}
	}
}

void AAICharacter::TriggerAttack()
{
	bCanDetectCollision = true;
	Attack();
}
