// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "EnemyAIController.generated.h"

UENUM(BlueprintType)
enum class EEnemyStateType : uint8 {
	IDLE = 0 UMETA(DisplayName = "Idle"),
	PATROLLING = 1 UMETA(DisplayName = "Patrolling"),
	CHASING = 2 UMETA(DisplayName = "Chasing"),
	ATTACKING = 3 UMETA(DisplayName = "Attacking"),
	DEAD = 4 UMETA(DisplayName = "Dead")
};
/**
 * 
 */
UCLASS()
class AIPROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	EEnemyStateType GetEnemyState() const { return EnemyState; }

	UFUNCTION(BlueprintCallable)
	void SetEnemyState(EEnemyStateType NewEnemyState) { EnemyState = NewEnemyState; }

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	EEnemyStateType EnemyState;
};
