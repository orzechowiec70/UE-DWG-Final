// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_Character.h"

// Sets default values
ADF_Character::ADF_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADF_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADF_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}