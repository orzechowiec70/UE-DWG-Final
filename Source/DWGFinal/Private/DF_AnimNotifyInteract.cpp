// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_AnimNotifyInteract.h"
#include "DF_PlayerCharacter.h"
#include "DF_InteractingComponent.h"

void UDF_AnimNotifyInteract::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (IsValid(MeshComp))
	{
		if (AActor* OwnerActor = MeshComp->GetOwner(); IsValid(OwnerActor))
		{
			if (UDF_InteractingComponent* InteractingComp = OwnerActor->FindComponentByClass<UDF_InteractingComponent>())
			{
				InteractingComp->InteractNotify();
			}
			else 
			{
				UE_LOG(LogTemp, Warning, TEXT("Trying to interact notify, but owner actor isn't player"))
			}
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Trying to interact notify, but owner actor is invalid"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Trying to interact notify, but owner mesh comp is invalid"))
	}
}
