// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveAlongPatrol.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UBTTask_MoveAlongPatrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBTTask_MoveAlongPatrol(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	//virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
