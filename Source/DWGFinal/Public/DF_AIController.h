// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DF_AIController.generated.h"

UCLASS()
class DWGFINAL_API ADF_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY()
	TObjectPtr<UBlackboardComponent> BlackboardComponent;

public:
	ADF_AIController();
};
