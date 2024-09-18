// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_CalculateRandomPoint.h"
#include "NavigationSystem.h"
#include "DF_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskNode_CalculateRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// 1. kod do liczenia random pointa

	// 2. zapisz FVector random pointa w blackboardzie

	AiCurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	UNavigationSystemV1* NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	if (IsValid(NavArea))
	{
		bRandomLocationFound = NavArea->GetRandomReachablePointInRadius(AiCurrentLocation, SearchRadius, RandomTargetLocation);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector("Destination", RandomTargetLocation);
	}
	
	return EBTNodeResult::Succeeded;
}
