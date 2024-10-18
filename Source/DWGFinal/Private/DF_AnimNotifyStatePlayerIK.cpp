// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_AnimNotifyStatePlayerIK.h"
#include "DF_PlayerCharacter.h"

void UDF_AnimNotifyStatePlayerIK::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	Player = Cast<ADF_PlayerCharacter>(MeshComp->GetOwner());

	if (Player.IsValid())
	{
		Player->RightHandIKAlpha = 0;
	}
}

void UDF_AnimNotifyStatePlayerIK::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);
	if (Player.IsValid())
	{
		Player->RightHandIKAlpha = Alpha;
	}
}

void UDF_AnimNotifyStatePlayerIK::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (Player.IsValid())
	{
		Player->RightHandIKAlpha = 0;
	}
}