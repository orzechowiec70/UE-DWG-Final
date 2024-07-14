// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_InteractableActor.h"
#include "DF_DoorInteractableActor.generated.h"


UCLASS()
class DWGFINAL_API ADF_DoorInteractableActor : public ADF_InteractableActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> DoorPivot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> DoorMesh;

public:
	ADF_DoorInteractableActor();

protected:
	virtual void Interact(AActor* OtherActor) override;
	bool bIsOpen;
};
