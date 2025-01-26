#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemy::AEnemy()
{
    PrimaryActorTick.bCanEverTick = true;

    // Ustawienia domyœlne
    HealthPoints = 100;
    Strength = 10.0f;
    AttackRange = 200.0f;
    AttackInterval = 1.5f;

    _AttackCountingDown = 0.0f;
}

void AEnemy::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (_AttackCountingDown > 0.0f)
    {
        _AttackCountingDown -= DeltaTime;
    }
}

bool AEnemy::CanAttack()
{
    return _AttackCountingDown <= 0.0f;
}

void AEnemy::Attack()
{
    _AttackCountingDown = AttackInterval;

}

void AEnemy::Hit(int Damage)
{
    HealthPoints -= Damage;
    if (HealthPoints <= 0)
    {
        DieProcess();
    }
}

void AEnemy::DieProcess()
{
    Destroy();
}
