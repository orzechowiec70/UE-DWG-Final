// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_AnimNotifyStateBlend.h"

void UDF_AnimNotifyStateBlend::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Alpha = 0.0f;
	CurrentTime = 0.0f;
	TotalTime = TotalDuration;
}

void UDF_AnimNotifyStateBlend::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	if (CurrentTime < BlendIn)
	{
		Alpha = CurrentTime / BlendIn;
	}
	else if (CurrentTime > TotalTime - BlendOut)
	{
		// TODO: Fix me
		Alpha = (CurrentTime - (TotalTime - BlendOut)) / (TotalTime - BlendOut);
	}
	else
	{
		Alpha = 1.0f;
	}
	CurrentTime += FrameDeltaTime;

	UE_LOG(LogTemp, Warning, TEXT("Alpha: %f"), Alpha);
}

void UDF_AnimNotifyStateBlend::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Alpha = 0.0f;
}
