#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UCLASS()
class PUNKRPG_API ABasePickup : public AActor
{
    GENERATED_BODY()

public:
    ABasePickup();

protected:
    // Collision component for overlap detection
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    class USphereComponent* CollisionComponent;

    // Visual mesh
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    class UStaticMeshComponent* MeshComponent;

    // Called when something overlaps with the pickup
    UFUNCTION()
    virtual void OnOverlapBegin(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );

    // Event that child pickups override to give effect
    UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
    void OnPickedUp(AActor* PickingActor);
    virtual void OnPickedUp_Implementation(AActor* PickingActor);

};
