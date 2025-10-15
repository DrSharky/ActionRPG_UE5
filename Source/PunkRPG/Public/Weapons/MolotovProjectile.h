#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MolotovProjectile.generated.h"

UCLASS()
class PUNKRPG_API AMolotovProjectile : public AActor
{
    GENERATED_BODY()

public:
    AMolotovProjectile();

protected:
    virtual void BeginPlay() override;

    // Collision
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class USphereComponent* Collision;

    // Mesh
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class UStaticMeshComponent* Mesh;

    // Movement
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class UProjectileMovementComponent* ProjectileMovement;

    // Fire effect actor to spawn
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TSubclassOf<AActor> FireEffectActor;

    // Damage or fire duration
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    float FireDuration;

    // Called on collision
    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit
    );
};
