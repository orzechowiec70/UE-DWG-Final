// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_DoorInteractableActor.h"
#include "MotionWarpingComponent.h"
#include "Components/BoxComponent.h"

ADF_DoorInteractableActor::ADF_DoorInteractableActor()
	: ADF_InteractableActor()
{
	DoorPivot = CreateDefaultSubobject<USceneComponent>("Pivot");
	DoorPivot ->SetupAttachment(Trigger);
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	DoorMesh->SetupAttachment(DoorPivot);
	FrontEntryPoint = CreateDefaultSubobject<USceneComponent>("Front Entry Point");
	FrontEntryPoint->SetupAttachment(RootComponent);
	BackEntryPoint = CreateDefaultSubobject<USceneComponent>("Back Entry Point");
	BackEntryPoint->SetupAttachment(RootComponent);
}

void ADF_DoorInteractableActor::Interact(AActor* OtherActor)
{
	auto SkeletalMesh = OtherActor->GetComponentByClass<USkeletalMeshComponent>(); //auto bo widaæ jaki typ zwraca
	if (!IsValid(SkeletalMesh)) //early returny
	{
		return;
	}

	UAnimInstance* AnimInstance = SkeletalMesh->GetAnimInstance();
	if (!IsValid(AnimInstance))
	{
		return;
	}

	auto MotionWarping = OtherActor->GetComponentByClass<UMotionWarpingComponent>();

	UE_LOG(LogTemp, Warning, TEXT("Door is: %hs"), bIsOpen ? "Open" : "Closed")

	//on which side is the player
	bool bIsInFront = false;
	FVector DoorFwd = DoorMesh->GetForwardVector();
	FVector OtherCharacterFwd = OtherActor->GetActorForwardVector();
	float Dot = DoorFwd.Dot(OtherCharacterFwd);
	bIsInFront = Dot < 0;
	UE_LOG(LogTemp, Warning, TEXT("Door is: %hs"), bIsInFront ? "In Front" : "Behind")


	if (bIsOpen)
	{
		Close();
	}
	else
	{
		if (IsValid(MotionWarping))
		{
			MotionWarping->AddOrUpdateWarpTargetFromComponent(FName("Target"), bIsInFront ? FrontEntryPoint : BackEntryPoint, FName(), false);
		}

		UAnimMontage* Montage = OpenDoorFront.LoadSynchronous();
		AnimInstance->Montage_Play(Montage);
		Open();
	}

	bIsOpen = !bIsOpen;
}
