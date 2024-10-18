// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DF_InteractingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractNotify);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DWGFINAL_API UDF_InteractingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDF_InteractingComponent();

	UPROPERTY()
	FInteractNotify OnInteractNotify;

	void InteractNotify();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool bIsInteracting = false;
};
