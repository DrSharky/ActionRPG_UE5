// Copyright Dystopia Games 

#include "Effects/FireEffectActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

AFireEffectActor::AFireEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	RootComponent = FireParticles;
	Lifetime = 5.f;
}

// Called when the game starts or when spawned
void AFireEffectActor::BeginPlay()
{
	Super::BeginPlay();

	// Destroy after lifetime.
	GetWorldTimerManager().SetTimer(
		LifeTimerHandle,
		this,
		&AFireEffectActor::DestroyFire,
		Lifetime,
		false
	);
}

void AFireEffectActor::DestroyFire()
{
	Destroy();
}
