#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "MolotovPickup.generated.h"

UCLASS()
class PUNKRPG_API AMolotovPickup : public ABasePickup
{
    GENERATED_BODY()

protected:
    virtual void OnPickedUp_Implementation(AActor* PickingActor) override;
};
