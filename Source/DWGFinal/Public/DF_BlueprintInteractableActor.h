// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_InteractableActor.h"
#include "DF_BlueprintInteractableActor.generated.h"

/**
 * 
 */
UCLASS()
class DWGFINAL_API ADF_BlueprintInteractableActor : public ADF_InteractableActor
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Interact();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PreInteract();

	virtual void Interact_Internal(AActor* OtherActor) override;
	virtual void PreInteract(AActor* OtherActor) override;
};
