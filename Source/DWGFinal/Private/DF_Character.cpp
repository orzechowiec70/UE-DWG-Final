// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DWGFinal/Public/DF_PlayerController.h"

// Sets default values
ADF_Character::ADF_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->TargetArmLength = 400.f; //jak daleko kamera
	Camera->bUsePawnControlRotation = true; //follows rotation of the parent

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(Camera, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ADF_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADF_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADF_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ADF_PlayerController* DF_PlayerController = Cast<ADF_PlayerController>(Controller);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	check(DF_PlayerController && EnhancedInput)
		DF_PlayerController->BindInput(EnhancedInput, this);
}

void ADF_Character::MoveCharacterWithInput(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FRotationMatrix DirectionMatrix = FRotationMatrix(YawRotation);
		const FVector ForwardDirection = DirectionMatrix.GetUnitAxis(EAxis::X);
		const FVector RightDirection = DirectionMatrix.GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void ADF_Character::LookInput(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller)) {
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void ADF_Character::JumpInput()
{
	ACharacter::Jump();
}
