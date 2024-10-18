// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DF_InteractingComponent.h"
#include "DF_InteractableActor.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class DWGFINAL_API ADF_InteractableActor : public AActor
{
	GENERATED_BODY()

	TWeakObjectPtr<AActor> CurrentInteractingActor;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> Origin;

	TWeakObjectPtr<UDF_InteractingComponent> InteractingComp;
	
public:	
	// Sets default values for this actor's properties
	ADF_InteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Interact(AActor* OtherActor);
	virtual void Interact_Internal (AActor* OtherActor) {  }
	virtual void PreInteract(AActor* OtherActor) {  }

	UFUNCTION(BlueprintCallable)
	void StopInteracting();

	virtual bool ShouldWaitForAnimNotify() const { return false; };

	UFUNCTION()
	void OnInteractNotify();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
};
