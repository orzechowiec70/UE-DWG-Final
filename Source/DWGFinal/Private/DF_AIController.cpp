// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_AIController.h"

ADF_AIController::ADF_AIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior tree");
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>("Blackboard");
}