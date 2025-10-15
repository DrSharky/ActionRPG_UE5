#include "Items/BasePickup.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

ABasePickup::ABasePickup()
{
    PrimaryActorTick.bCanEverTick = false;

    // Collision
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(50.f);
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    RootComponent = CollisionComponent;

    // Mesh
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // Bind overlap
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnOverlapBegin);
}

void ABasePickup::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult
)
{
    if (OtherActor && OtherActor != this)
    {
        OnPickedUp(OtherActor);
        Destroy(); // remove pickup after collection
    }
}

void ABasePickup::OnPickedUp_Implementation(AActor* PickingActor)
{
    // Default does nothing — subclasses override
}
