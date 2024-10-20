// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Interactable_Base.generated.h"

UCLASS()
class AIPROJECT_API AInteractable_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable_Base();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact();
	virtual void Interact_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InRange(bool inRange);
	virtual void InRange_Implementation(bool inRange);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* InteractableWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	FString InteractMessage;

	//virtual void Tick(float DeltaTime) override;
};
