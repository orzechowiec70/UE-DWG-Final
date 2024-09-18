// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_PlayerAnimInstance.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"

void UDF_PlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OwningCharacter = Cast<ADF_PlayerCharacter>(GetOwningActor());
}

void UDF_PlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwningCharacter))
	{
		DesiredVelocity = OwningCharacter->GetDesiredVelocity();

		CurrentVelocity = FMath::VInterpTo(CurrentVelocity, DesiredVelocity, DeltaSeconds, VelocityInterpSpeed);//Lerp
		bIsJumping = OwningCharacter->IsJumping();
		bIsGrounded = OwningCharacter->IsGrounded();
		RightHandIKAlpha = OwningCharacter->RightHandIKAlpha;

		if (IsValid(OwningCharacter->RightHandIKTarget) && RightHandIKAlpha > UE_SMALL_NUMBER)
		{
			RightHandIKTarget = OwningCharacter->RightHandIKTarget->GetComponentTransform();
		}
		
	}
}