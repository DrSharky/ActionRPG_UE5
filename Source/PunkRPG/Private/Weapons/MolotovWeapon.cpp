// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/MolotovWeapon.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Weapons/MolotovProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

void AMolotovWeapon::UseWeapon()
{
	if (!GetOwner()) return;

	FVector SpawnLocation = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 100.f;
	FRotator SpawnRotation = GetOwner()->GetActorRotation();

	if (UWorld* World = GetWorld())
	{
		World->SpawnActor<AMolotovProjectile>(AMolotovProjectile::StaticClass(), SpawnLocation, SpawnRotation);
	}

	UE_LOG(LogTemp, Log, TEXT("Molotov thrown!"));
}