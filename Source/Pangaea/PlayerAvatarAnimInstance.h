// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAvatarAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
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
class PANGAEA_API UPlayerAvatarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    float Speed;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    EPlayerState State;
};