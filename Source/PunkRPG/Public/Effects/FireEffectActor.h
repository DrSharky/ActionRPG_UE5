// Copyright Dystopia Games 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireEffectActor.generated.h"

UCLASS()
class PUNKRPG_API AFireEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* FireParticles;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float Lifetime;

	UFUNCTION()
	void DestroyFire();

	FTimerHandle LifeTimerHandle;
};
