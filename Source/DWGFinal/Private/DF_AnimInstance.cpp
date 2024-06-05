// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_AnimInstance.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"

FVector UDF_AnimInstance::GetDesiredVelocity(const ADF_PlayerCharacter& Instance)
{
	return Velocity = Instance.DesiredVelocity;
}

void UDF_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	GetDesiredVelocity();
	DesiredVelocity = Velocity;
}
