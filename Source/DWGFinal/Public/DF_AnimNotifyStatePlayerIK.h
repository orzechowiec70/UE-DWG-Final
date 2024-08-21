// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_AnimNotifyStateBlend.h"
#include "DF_AnimNotifyStatePlayerIK.generated.h"

class ADF_PlayerCharacter;

/**
 * 
 */
UCLASS()
class DWGFINAL_API UDF_AnimNotifyStatePlayerIK : public UDF_AnimNotifyStateBlend
{
	GENERATED_BODY()

#if WITH_EDITOR

public:
	/** Override this to prevent firing this notify state type in animation editors */
	virtual bool ShouldFireInEditor() { return false; }

#endif

protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);


	TWeakObjectPtr<ADF_PlayerCharacter> Player;
};
