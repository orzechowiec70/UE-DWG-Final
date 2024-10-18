// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_OpeningAnimNotifyState.h"
#include "DF_PlayerCharacter.h"

void UDF_OpeningAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	AActor* OwnerActor = MeshComp->GetOwner();
	Player = Cast<ADF_PlayerCharacter>(OwnerActor);
	if (Player.IsValid())
	{
		Player->bCanOpen = true;
	}
}

void UDF_OpeningAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (Player.IsValid())
	{
		Player->bCanOpen = false;
	}
}
