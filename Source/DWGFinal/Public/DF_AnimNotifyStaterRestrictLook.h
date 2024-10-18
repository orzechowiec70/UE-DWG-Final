// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "DF_AnimNotifyStaterRestrictLook.generated.h"

class ADF_PlayerCharacter;

UCLASS()
class DWGFINAL_API UDF_AnimNotifyStaterRestrictLook : public UAnimNotifyState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bAllowLook = false;

	TWeakObjectPtr<ADF_PlayerCharacter> Player;

public:
#if WITH_EDITOR
	virtual bool ShouldFireInEditor() { return false; }
#endif

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);

};
