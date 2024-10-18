// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DF_InteractableActor.h"
#include "DF_DoorInteractableActor.generated.h"


class ADF_PlayerCharacter;

UCLASS()
class DWGFINAL_API ADF_DoorInteractableActor : public ADF_InteractableActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> DoorPivot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> DoorMesh;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimMontage> OpenDoorFront;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimMontage> OpenDoorBehind;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimMontage> CloseDoorFront;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimMontage> CloseDoorBehind;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> FrontEntryPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> BackEntryPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> IKTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bCanBeOpened = true;

public:
	ADF_DoorInteractableActor();

	UFUNCTION(BlueprintImplementableEvent)
	void Open();

	UFUNCTION(BlueprintImplementableEvent)
	void Close();

protected:
	virtual void PreInteract (AActor* OtherActor) override;
	virtual void Interact_Internal(AActor* OtherActor) override;

	virtual bool ShouldWaitForAnimNotify() const override { return true; };

	UFUNCTION()
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	

	TWeakObjectPtr<ADF_PlayerCharacter> InteractingPlayer;

	bool bIsOpen;
};
