// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_AnimNotifyStaterRestrictLook.h"
#include "DF_PlayerCharacter.h"

void UDF_AnimNotifyStaterRestrictLook::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	AActor* OwnerActor = MeshComp->GetOwner();
	Player = Cast<ADF_PlayerCharacter>(OwnerActor);
	if (Player.IsValid() && IsValid(Player->Controller))
	{
		if (!bAllowLook)
		{
			Player->bCanLook = false;
		}
		Player->bUseControllerRotationYaw = false;
	}
}

void UDF_AnimNotifyStaterRestrictLook::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (Player.IsValid() && IsValid(Player->Controller))
	{
		Player->bCanLook = true;
		Player->bUseControllerRotationYaw = true;

		FRotator TargetControlRotation = Player->Controller->GetControlRotation();
		TargetControlRotation.Yaw = Player->GetActorRotation().Yaw;

		Player->Controller->SetControlRotation(TargetControlRotation);
	}
}
