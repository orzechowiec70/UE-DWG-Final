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

void ADF_DoorInteractableActor::Interact(AActor* OtherActor)
{

	UE_LOG(LogTemp, Warning, TEXT("Door is: %hs"), bIsOpen ? "Open" : "Closed")

	//on which side is the player
	bool bIsInFront = false;
	FVector DoorFwd = DoorMesh->GetForwardVector();
	FVector OtherCharacterFwd = OtherActor->GetActorForwardVector();
	float Dot = DoorFwd.Dot(OtherCharacterFwd);
	bIsInFront = Dot < 0;
	UE_LOG(LogTemp, Warning, TEXT("Door is: %hs"), bIsInFront ? "In Front" : "Behind")
	bIsOpen = !bIsOpen;
}
