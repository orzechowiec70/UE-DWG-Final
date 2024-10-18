// Fill out your copyright notice in the Description page of Project Settings.

#include "DF_DoorInteractableActor.h"
#include "MotionWarpingComponent.h"
#include "DF_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

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
	IKTarget = CreateDefaultSubobject<USceneComponent>("IK Target");
	IKTarget->SetupAttachment(DoorMesh);
}

void ADF_DoorInteractableActor::PreInteract(AActor* OtherActor)
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
		StopInteracting();
	}
	else
	{
		if (IsValid(MotionWarping))
		{
			MotionWarping->AddOrUpdateWarpTargetFromComponent(FName("Target"), bIsInFront ? FrontEntryPoint : BackEntryPoint, FName(), false);
		}

		InteractingPlayer = Cast<ADF_PlayerCharacter>(OtherActor);
		// Dlaczego nie mogê ich przyrównaæ??
		if (InteractingPlayer.IsValid())
		{
			InteractingPlayer->RightHandIKTarget = IKTarget;
		}

		UAnimMontage* Montage = OpenDoorFront.LoadSynchronous();
		AnimInstance->Montage_Play(Montage);

		if (InteractingComp.IsValid())
		{
			AnimInstance->OnMontageEnded.AddDynamic(this, &ADF_DoorInteractableActor::OnMontageEnded);
		}
	}
}

void ADF_DoorInteractableActor::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (InteractingComp.IsValid())
	{
		InteractingComp->bIsInteracting = false;
	}

	if (InteractingPlayer.IsValid())
	{
		InteractingPlayer->RightHandIKTarget = nullptr;
	}
}

void ADF_DoorInteractableActor::Interact_Internal(AActor* OtherActor)
{
	if (bIsOpen)
	{
		Close();
	}
	else
	{
		Open();
	}

	bIsOpen = !bIsOpen;
}