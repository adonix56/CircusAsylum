// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnemyAIController.h"
#include "BTTask_SetEnemyState.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UBTTask_SetEnemyState : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_SetEnemyState(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	EEnemyStateType NewEnemyState;
	
};
