// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_BlueprintInteractableActor.h"

void ADF_BlueprintInteractableActor::Interact_Internal(AActor* OtherActor)
{
	BP_Interact();

}

void ADF_BlueprintInteractableActor::PreInteract(AActor* OtherActor)
{
	BP_PreInteract();
}
