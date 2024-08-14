// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_InteractingComponent.h"

// Sets default values for this component's properties
UDF_InteractingComponent::UDF_InteractingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UDF_InteractingComponent::InteractNotify()
{
	OnInteractNotify.Broadcast();
}

// Called when the game starts
void UDF_InteractingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDF_InteractingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

