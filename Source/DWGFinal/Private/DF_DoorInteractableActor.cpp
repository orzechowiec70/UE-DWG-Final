// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_DoorInteractableActor.h"
#include "Components/BoxComponent.h"

ADF_DoorInteractableActor::ADF_DoorInteractableActor()
	: ADF_InteractableActor()
{
	DoorPivot = CreateDefaultSubobject<USceneComponent>("Pivot");
	DoorPivot ->SetupAttachment(Trigger);
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	DoorMesh->SetupAttachment(DoorPivot);

}
