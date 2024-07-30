// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "DF_AnimNotifyStateBlend.generated.h"


UCLASS()
class DWGFINAL_API UDF_AnimNotifyStateBlend : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);

	float Alpha = 0.0f;
	float TotalTime = 0.0f;
	float CurrentTime = 0.0f;

	/*
	* Blend in defined in seconds
	*/
	UPROPERTY(EditAnywhere, meta = (Units = "s"))
	float BlendIn = 0.1f;

	/*
	* Blend out defined in seconds
	*/
	UPROPERTY(EditAnywhere, meta=(Units = "s"))
	float BlendOut = 0.1f;
};
