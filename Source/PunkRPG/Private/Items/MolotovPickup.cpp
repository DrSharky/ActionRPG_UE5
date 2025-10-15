#include "Items/MolotovPickup.h"
#include "Inventory/InventoryComponent.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.h"

void AMolotovPickup::OnPickedUp_Implementation(AActor* PickingActor)
{
    if (ARPGCharacterBase* Character = Cast<ARPGCharacterBase>(PickingActor))
    {
        if (UInventoryComponent* Inventory = Character->InventoryComponent)
        {
            Inventory->AddWeapon(AMolotovWeapon::StaticClass());
            UE_LOG(LogTemp, Log, TEXT("Molotov added to inventory."));
		}
    }
}