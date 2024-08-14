
#include "DF_InteractableActor.h"
#include "Components/BoxComponent.h"

ADF_InteractableActor::ADF_InteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	Trigger = CreateDefaultSubobject<UBoxComponent>("Trigger");
	Trigger->SetupAttachment(Origin);

	InteractingComponent = CreateDefaultSubobject<UDF_InteractingComponent>("Interacting Component");

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADF_InteractableActor::OnOverlap);
}

void ADF_InteractableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADF_InteractableActor::Interact(AActor* OtherActor)
{
	CurrentInteractingActor = OtherActor;

	PreInteract(OtherActor);

	if (!ShouldWaitForAnimNotify())
	{
		Interact_Internal(OtherActor);
	}
	else
	{
		if (UDF_InteracingComponent* InteractingComponent = OtherActor->FindComponentByClass<UDF_InteractingComponent>(); IsValid(InteractingComponent))
		{
			InteractingComponent->OnInteractNotify.AddDynamic(this, &ADF_InteractableActor::OnInteractNotify);
		}
	}
}

void ADF_InteractableActor::OnInteractNotify()
{
	Interact_Internal(CurrentInteractingActor.Get());

	if (UDF_InteracingComponent* InteractingComponent = CurrentInteractingActor->FindComponentByClass<UDF_InteractingComponent>(); IsValid(InteractingComponent))
	{
		InteractingComponent->OnInteractNotify.RemoveAll(this);
	}
}

void ADF_InteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADF_InteractableActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Interact(OtherActor);
}

