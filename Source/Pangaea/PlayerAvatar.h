// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerAvatar.generated.h"

UCLASS()
class PANGAEA_API APlayerAvatar : public ACharacter
{
	GENERATED_BODY()

public:

	APlayerAvatar();

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	int HealthPoints = 500;

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Strength = 10.0f;

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Armor = 3.0f;

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackRange = 6.0f;

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackInterval = 1.2f;



protected:
	
	virtual void BeginPlay() override;
	int _HealthPoints;
	float _AttackCountingDown;

public:	

	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable, Category = "Pangaea|PlayerCharacter", meta = (DisplayName = "Get HP"))
	int GetHealthPoints() { return _HealthPoints; }

	UFUNCTION(BlueprintPure, Category = "Pangaea|PlayerCharacter")
	bool IsKilled() { return _HealthPoints <= 0; }

	UFUNCTION(BlueprintPure, Category = "Pangaea|PlayerCharacter")
	bool CanAttack() { return _AttackCountingDown <= 0.0f; }

	void Attack();
	void Hit(int damage);

protected:
	void DieProcess();

private:
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _cameraComponent;

};
