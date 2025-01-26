

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS(Blueprintable)
class PANGAEA_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	AProjectile();
	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Speed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Lifespan = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Damage = 10.0f;

protected:

	virtual void BeginPlay() override;
	float _LifeCountingDown;
public:	
	
	virtual void Tick(float DeltaTime) override;

};
