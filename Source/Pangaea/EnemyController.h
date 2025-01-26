#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class PANGAEA_API AEnemyController : public AAIController
{
    GENERATED_BODY()

public:
   
    AEnemyController();


    void MakeAttackDecision(APawn* TargetPawn);

protected:
 
    virtual void BeginPlay() override;

    
    virtual void Tick(float DeltaTime) override;
};
