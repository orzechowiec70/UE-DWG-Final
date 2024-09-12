// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_AIController.h"

ADF_AIController::ADF_AIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior tree");
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>("Blackboard");
}

void ADF_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(BT))
	{
		Blackboard->InitializeBlackboard(*BT->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*BT);
	}
}
