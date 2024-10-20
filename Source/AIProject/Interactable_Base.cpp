// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable_Base.h"

// Sets default values
AInteractable_Base::AInteractable_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	InteractableWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interactable Widget"));
	InteractableWidget->SetupAttachment(RootComponent);
	InteractableWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void AInteractable_Base::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Interactable Interact"));
}

void AInteractable_Base::InRange_Implementation(bool inRange)
{
	if (InteractableWidget)
		InteractableWidget->SetVisibility(inRange);
}

// Called when the game starts or when spawned
void AInteractable_Base::BeginPlay()
{
	Super::BeginPlay();
	InteractableWidget->SetVisibility(false);
}

/*
// Called every frame
void AInteractable_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

