// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "EnemyAIController.h"
#include "BTDecorator_EnemyState.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UBTDecorator_EnemyState : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

	UBTDecorator_EnemyState(FObjectInitializer const& ObjectInitializer);
	
protected:

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	EEnemyStateType EnemyState;
};
