// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_Character.h"
#include "DF_PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;
class UMotionWarpingComponent;
class UDF_InteractingComponent;

UCLASS()
class DWGFINAL_API ADF_PlayerCharacter : public ADF_Character
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector DesiredVelocity;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMotionWarpingComponent> MotionWarping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDF_InteractingComponent> InteractingComp;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCanLook = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCanOpen = false;

	UPROPERTY(VisibleAnywhere)
	float RightHandIKAlpha = 0.0f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> RightHandIKTarget;

	ADF_PlayerCharacter();

	void MoveCharacterWithInput(const FInputActionValue& InputValue);
	void StopMoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void JumpInput();
	void StopJumpInput();
	void RunningInput();
	FVector GetDesiredVelocity();
	bool IsJumping() const;
	bool IsGrounded() const;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool bIsJumping = false;
	bool bIsRunning = false;
};
