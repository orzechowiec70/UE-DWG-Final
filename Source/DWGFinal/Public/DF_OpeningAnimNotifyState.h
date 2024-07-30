// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "DF_OpeningAnimNotifyState.generated.h"

class ADF_PlayerCharacter;

UCLASS()
class DWGFINAL_API UDF_OpeningAnimNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

	TWeakObjectPtr<ADF_PlayerCharacter> Player;

protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);
};
