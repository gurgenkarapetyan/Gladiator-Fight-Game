// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableWeapon.h"

APickableWeapon::APickableWeapon()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Hammer"));
	SkeletalMeshComponent->AttachToComponent(SphereComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	DamageBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Box Component"));
	DamageBoxComponent->AttachToComponent(SphereComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

void APickableWeapon::BeginPlay()
{
	Super::BeginPlay();
}

UBoxComponent* APickableWeapon::GetDamageBox() const
{
	return DamageBoxComponent;
}
