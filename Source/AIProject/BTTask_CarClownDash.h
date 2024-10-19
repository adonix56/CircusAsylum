// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "CarClownAIController.h"
#include "BTTask_CarClownDash.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UBTTask_CarClownDash : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

	UBTTask_CarClownDash(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
