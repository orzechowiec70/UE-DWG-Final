// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_AnimInstance.h"
#include "DF_NPCAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DWGFINAL_API UDF_NPCAnimInstance : public UDF_AnimInstance
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float CurrentSpeedSq;
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
