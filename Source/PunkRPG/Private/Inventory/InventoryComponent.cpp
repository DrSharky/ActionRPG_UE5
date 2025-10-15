#include "Inventory/InventoryComponent.h"
#include "Weapons/BaseWeapon.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentWeapon = nullptr;
	CurrentIndex = -1;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddWeapon(TSubclassOf<ABaseWeapon> WeaponClass)
{
	if (!WeaponClass) return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	UWorld* World = GetWorld();
	if (!World) return;

	ABaseWeapon* NewWeapon = World->SpawnActor<ABaseWeapon>(WeaponClass);
	if (NewWeapon)
	{
		NewWeapon->AttachToComponent(OwnerCharacter->GetMesh(),
			FAttachmentTransformRules::KeepRelativeTransform,
			TEXT("WeaponSocket"));
		NewWeapon->SetOwner(OwnerCharacter);
		NewWeapon->SetActorHiddenInGame(true);
		Weapons.Add(NewWeapon);

		if (Weapons.Num() == 1)
		{
			EquipWeapon(0);
		}
	}
}

void UInventoryComponent::EquipNextWeapon()
{
	if (Weapons.Num() == 0) return;

	CurrentIndex = (CurrentIndex + 1) % Weapons.Num();
	EquipWeapon(CurrentIndex);
}

void UInventoryComponent::EquipWeapon(int32 Index)
{
	if (Weapons.Num() == 0 || !Weapons.IsValidIndex(Index)) return;

	if (CurrentWeapon)
	{
		CurrentWeapon->SetActorHiddenInGame(true);
	}

	CurrentWeapon = Weapons[Index];
	CurrentWeapon->SetActorHiddenInGame(false);
}