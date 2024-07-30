// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DF_AnimNotifyHandlingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DWGFINAL_API UDF_AnimNotifyHandlingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCanLook = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCanOpen = false;

	UPROPERTY(VisibleAnywhere)
	float RightHandIKAlpha = 0.0f;

	UPROPERTY(VisibleAnywhere)
	FTransform RightHandIKTarget;

public:	
	UDF_AnimNotifyHandlingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
