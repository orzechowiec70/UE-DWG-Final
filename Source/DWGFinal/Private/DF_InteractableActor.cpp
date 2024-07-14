
#include "DF_InteractableActor.h"
#include "Components/BoxComponent.h"

ADF_InteractableActor::ADF_InteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	Trigger = CreateDefaultSubobject<UBoxComponent>("Trigger");
	Trigger->SetupAttachment(Origin);

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADF_InteractableActor::OnOverlap);
}

void ADF_InteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADF_InteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADF_InteractableActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Interact(OtherActor);
}

