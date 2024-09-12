// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_AnimInstance.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"
#include "DF_PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DWGFINAL_API UDF_PlayerAnimInstance : public UDF_AnimInstance
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector DesiredVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ADF_PlayerCharacter> OwningCharacter;

	UPROPERTY(EditDefaultsOnly)
	float VelocityInterpSpeed = 10;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsJumping = false;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsGrounded = true;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RightHandIKAlpha = 0.0f;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FTransform RightHandIKTarget;

protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
