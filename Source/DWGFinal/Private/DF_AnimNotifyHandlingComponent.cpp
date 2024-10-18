
#include "DF_AnimNotifyHandlingComponent.h"


UDF_AnimNotifyHandlingComponent::UDF_AnimNotifyHandlingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UDF_AnimNotifyHandlingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UDF_AnimNotifyHandlingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

