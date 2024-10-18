// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DF_Character.generated.h"


UCLASS()
class DWGFINAL_API ADF_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADF_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
