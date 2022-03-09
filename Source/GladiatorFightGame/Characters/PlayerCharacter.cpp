// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
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
