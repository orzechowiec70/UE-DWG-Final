// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "DWGFinal/Public/DF_PlayerController.h"


ADF_PlayerCharacter::ADF_PlayerCharacter()
{
	Camera = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->TargetArmLength = 400.f; //jak daleko kamera
	Camera->bUsePawnControlRotation = true; //follows rotation of the parent

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(Camera, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ADF_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ADF_PlayerController* DF_PlayerController = Cast<ADF_PlayerController>(Controller);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	check(DF_PlayerController && EnhancedInput)
		DF_PlayerController->BindInput(EnhancedInput, this);
}

void ADF_PlayerCharacter::MoveCharacterWithInput(const FInputActionValue& InputValue)
{
	const FVector2D InputVector = InputValue.Get<FVector2D>();

	const FQuat ControlRotation2D = FRotator(0, GetControlRotation().Yaw, 0).Quaternion();
	const FVector Y = ControlRotation2D.GetForwardVector() * InputVector.Y;
	const FVector X = ControlRotation2D.GetRightVector() * InputVector.X;
	const FVector Normalized = (X + Y).GetSafeNormal();

	DesiredVelocity = FVector(GetActorRightVector().Dot(Normalized), GetActorForwardVector().Dot(Normalized), 0);
}

void ADF_PlayerCharacter::StopMoveInput(const FInputActionValue& InputValue)
{
	DesiredVelocity = FVector::ZeroVector;
}

void ADF_PlayerCharacter::LookInput(const FInputActionValue& InputValue)
{
	const FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void ADF_PlayerCharacter::JumpInput()
{
	ACharacter::Jump();
	//zalogowa� velocity %s GetVelocity().ToString()

	bIsJumping = true;


	/*
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && JumpMontage)
	{
		if (!AnimInstance->Montage_IsPlaying(JumpMontage))
		{
			AnimInstance->Montage_Play(JumpMontage);
		}
	}
	*/
}

void ADF_PlayerCharacter::StopJumpInput()
{
	bIsJumping = false;
}

FVector ADF_PlayerCharacter::GetDesiredVelocity()
{
	return DesiredVelocity;
}

bool ADF_PlayerCharacter::IsJumping() const
{
	return bIsJumping;
}

bool ADF_PlayerCharacter::IsGrounded() const
{
	return GetCharacterMovement()->IsMovingOnGround();
}
