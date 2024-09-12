// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_NPCAnimInstance.h"

void UDF_NPCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	APawn* OwnerPawn = TryGetPawnOwner();
	if (IsValid(OwnerPawn))
	{
		CurrentVelocity = OwnerPawn->GetVelocity();
		CurrentSpeedSq = CurrentVelocity.SquaredLength();
	}
	
	Super::NativeUpdateAnimation(DeltaSeconds);
}
