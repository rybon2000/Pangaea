

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefenseTower.generated.h"

UCLASS(Blueprintable)
class PANGAEA_API ADefenseTower : public AActor
{
	GENERATED_BODY()
	
public:	

	ADefenseTower();

	UPROPERTY(EditAnywhere, Category = "Tower Params")
	int HealthPoints = 500;

	UPROPERTY(EditAnywhere, Category = "Tower Params")
	int ShellDefense = 3;

	UPROPERTY(EditAnywhere, Category = "Tower Params")
	float AttackRange = 6.0f;

	UPROPERTY(EditAnywhere, Category = "Tower Params")
	float ReloadInterval = 1.0f;

protected:

	virtual void BeginPlay() override;
	int _HealthPoints;
	float _ReloadCountingDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pangaea|Defense Tower", meta = (DisplayName = "GetHP"))
	int GetHealthPoints() { return _HealthPoints; }

	UFUNCTION(BlueprintPure, Category = "Pangaea|Defense Tower")
	bool IsDestroyed() { return _HealthPoints <= 0; }

	UFUNCTION(BlueprintPure, Category = "Pangaea|Defense Tower")
	bool CanFire() { return _ReloadCountingDown <= 0.0f; }

	void Fire();
	void Hit(int damage);
protected:
	void DestroyProcess();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Component", meta = (AllowPrivateAccess = "true"))
	//UBoxComponent* _BoxComponent;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;

};
