// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_SetMovementSpeed.h"
#include "AIController.h"

UBTTask_SetMovementSpeed::UBTTask_SetMovementSpeed(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Set Movement Speed");
}

EBTNodeResult::Type UBTTask_SetMovementSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn())) {
		Enemy->SetMovementSpeed(MovementSpeed);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
