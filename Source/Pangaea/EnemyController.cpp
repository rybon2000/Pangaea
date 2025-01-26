#include "EnemyController.h"
#include "Enemy.h"

AEnemyController::AEnemyController()
{
    
    PrimaryActorTick.bCanEverTick = true;
}

void AEnemyController::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

  
}

void AEnemyController::MakeAttackDecision(APawn* TargetPawn)
{

    auto ControlledEnemy = Cast<AEnemy>(GetPawn());
    if (!ControlledEnemy || !TargetPawn)
        return;

   
    float Distance = FVector::Dist2D(TargetPawn->GetActorLocation(), ControlledEnemy->GetActorLocation());

 
    if (Distance <= ControlledEnemy->AttackRange && ControlledEnemy->CanAttack())
    {
        ControlledEnemy->Attack();
    }
}
