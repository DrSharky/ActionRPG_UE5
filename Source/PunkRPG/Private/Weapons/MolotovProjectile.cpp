#include "Weapons/MolotovProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
AMolotovProjectile::AMolotovProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Collision.
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(15.f);
	Collision->SetCollisionProfileName("Projectile");
	RootComponent = Collision;
	Collision->OnComponentHit.AddDynamic(this, &AMolotovProjectile::OnHit);

	// Mesh.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Movement.
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 1500.f;
	ProjectileMovement->MaxSpeed = 1500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	FireDuration = 5.f;
}

// Called when the game starts or when spawned
void AMolotovProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AMolotovProjectile::OnHit(
	UPrimitiveComponent* HitComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit
)
{
	if (!OtherActor || OtherActor == this) return;

	// Spawn fire effect at the hit location
	if (FireEffectActor)
	{
		GetWorld()->SpawnActor<AActor>(FireEffectActor, Hit.ImpactPoint, FRotator::ZeroRotator);
	}

	if (ACharacter* HitCharacter = Cast<ACharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Log, TEXT("Molotov hit character: %s"), *HitCharacter->GetName());
		//TODO: Apply fire effect to character, e.g., set on fire for FireDuration seconds
	}

	// Destroy the projectile
	Destroy();
}

