// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerAvatar.h"
#include "PlayerAvatarAnimInstance.h"


APlayerAvatar::APlayerAvatar()
{
	
	PrimaryActorTick.bCanEverTick = true;


	_springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_springArmComponent->SetupAttachment(RootComponent);
	_springArmComponent->TargetArmLength = 800.f;
	_springArmComponent->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));

	_cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_cameraComponent->SetupAttachment(_springArmComponent);

	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	auto characterMovement = GetCharacterMovement();
	characterMovement->bOrientRotationToMovement = true;
	characterMovement->RotationRate = FRotator(0.f, 640.f, 0.f);


}


void APlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	

}

void APlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto animInst = Cast<UPlayerAvatarAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->Speed = GetCharacterMovement()->Velocity.Size2D();

}


void APlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

