// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UEnemyAnimInstance.generated.h"


UENUM(BlueprintType)
enum class EEnemyState : uint8
{
    Locomotion UMETA(DisplayName = "Locomotion"),
    Attack UMETA(DisplayName = "Attack"),
    Hit UMETA(DisplayName = "Hit"),
    Die UMETA(DisplayName = "Die")
};
/**
 * 
 */
UCLASS()
class PANGAEA_API UUEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    float Speed;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    EEnemyState State;


    UFUNCTION(BlueprintCallable)
    void OnStateAnimationEnds();
};
