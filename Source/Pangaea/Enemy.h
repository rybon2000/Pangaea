#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class PANGAEA_API AEnemy : public ACharacter
{
    GENERATED_BODY()

public:

    AEnemy();


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Params")
    int HealthPoints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Params")
    float Strength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Params")
    float AttackRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Params")
    float AttackInterval;

protected:
  
    virtual void BeginPlay() override;

public:
   
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    bool CanAttack();

    void Attack();
    void Hit(int Damage);
    void DieProcess();
private:
    float _AttackCountingDown;
};
