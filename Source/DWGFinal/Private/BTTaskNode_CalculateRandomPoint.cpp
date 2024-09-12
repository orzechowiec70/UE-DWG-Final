// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_CalculateRandomPoint.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskNode_CalculateRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// 1. kod do liczenia random pointa

	// 2. zapisz FVector random pointa w blackboardzie

	OwnerComp.GetBlackboardComponent()->SetValueAsVector("Destination", FVector());
	
	return EBTNodeResult::Succeeded;
}
