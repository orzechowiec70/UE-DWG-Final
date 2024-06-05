// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"
#include "DF_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DWGFINAL_API UDF_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector DesiredVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector Velocity;

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	FVector GetDesiredVelocity(const ADF_PlayerCharacter& Instance);
};