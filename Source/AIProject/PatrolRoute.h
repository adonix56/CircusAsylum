// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PatrolRoute.generated.h"

UCLASS()
class AIPROJECT_API APatrolRoute : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolRoute();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PatrolRoute, meta = (AllowPrivateAccess = "true"))
	USplineComponent* SplineComponent;

	UFUNCTION(BlueprintCallable)
	FVector GetNextPatrolLocation();

protected:
	int patrolLength;
	int curPatrolPoint;

};
