#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "MolotovWeapon.generated.h"

UCLASS()
class PUNKRPG_API AMolotovWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	virtual void UseWeapon() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AActor> FireEffectActor;
};
