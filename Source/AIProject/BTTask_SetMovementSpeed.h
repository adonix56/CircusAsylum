// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SetMovementSpeed.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UBTTask_SetMovementSpeed : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_SetMovementSpeed(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	EMovementSpeedType MovementSpeed;
};
