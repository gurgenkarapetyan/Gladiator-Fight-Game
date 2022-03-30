// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GladiatorFightGame/Items/PickableItemBase.h"
#include "GladiatorFightGame/Items/PickableWeapon.h"

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnBeginOverlap);
}

void APlayerCharacter::OnBeginOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	if (OtherActor->ActorHasTag("Shield"))
	{
		APickableItemBase* PickedShield = Cast<APickableItemBase>(OtherActor);
		PickShield(PickedShield);
	}
	
	if (OtherActor->ActorHasTag("Hammer"))
	{
		APickableWeapon* PickedWeapon = Cast<APickableWeapon>(OtherActor);
		PickHammer(PickedWeapon);
	}
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

	PlayerInputComponent->BindAction("Attack", IE_Pressed,this, &APlayerCharacter::TriggerAttack);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (!bIsAlive)
	{
		return;
	}

	if (!bIsAttacking)
	{
		FRotator CameraRotation = GetControlRotation();
		CameraRotation.Pitch = 0.f;
		const FVector MoveDirection = CameraRotation.Vector();
		GetCharacterMovement()->AddInputVector(MoveDirection * Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (!bIsAlive)
	{
		return;
	}

	if (!bIsAttacking)
	{
		FRotator CameraRotation = GetControlRotation();
		CameraRotation.Pitch = 0.f;
		const FVector MoveDirection = CameraRotation.RotateVector(FVector::RightVector);
		GetCharacterMovement()->AddInputVector(MoveDirection * Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	const float Input = Value * 100.f * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(Input);
}

void APlayerCharacter::LookUp(float Value)
{
	const float Input = Value * 100.f * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(Input);
}

void APlayerCharacter::TriggerAttack()
{
	if (WeaponActor)
	{
		Attack();
	}
}
