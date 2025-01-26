// Fill out your copyright notice in the Description page of Project Settings.


#include "UEnemyAnimInstance.h"
#include "Enemy.h"


void UUEnemyAnimInstance::OnStateAnimationEnds()
{

    if (State == EEnemyState::Attack)
    {
        State = EEnemyState::Locomotion;
    }
    else
    {
      
        auto Enemy = Cast<AEnemy>(GetOwningActor());
        if (!Enemy) return; 

      
        if (State == EEnemyState::Hit)
        {
            if (Enemy->HealthPoints > 0)
            {
                State = EEnemyState::Locomotion;
            }
            else
            {
                State = EEnemyState::Die;
            }
        }
      
        else if (State == EEnemyState::Die)
        {
            Enemy->DieProcess();
        }
    }
}
