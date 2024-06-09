// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_AnimInstance.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"


void UDF_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OwningCharacter = Cast<ADF_PlayerCharacter>(GetOwningActor());
}

void UDF_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwningCharacter))
	{
		DesiredVelocity = OwningCharacter->GetDesiredVelocity();
		CurrentVelocity = FMath::VInterpTo(CurrentVelocity, DesiredVelocity, DeltaSeconds, VelocityInterpSpeed); //Lerp
	}
}
