// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_CalculateRandomPoint.generated.h"

/**
 * 
 */
UCLASS()
class DWGFINAL_API UBTTaskNode_CalculateRandomPoint : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	FVector AiCurrentLocation;
	FNavLocation RandomTargetLocation;
	bool bRandomLocationFound;

public:
	UPROPERTY(EditAnywhere)
	float SearchRadius = 500.f;
};
