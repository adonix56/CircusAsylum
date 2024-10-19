// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "BTTask_SetEnemyState.h"

UBTTask_SetEnemyState::UBTTask_SetEnemyState(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Set Enemy State");
}

EBTNodeResult::Type UBTTask_SetEnemyState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemyAIController* EnemyCont = Cast<AEnemyAIController>(OwnerComp.GetAIOwner())) {
		if (NewEnemyState == EEnemyStateType::PATROLLING) {
			if (AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(EnemyCont->GetPawn())) {
				if (Enemy->GetPatrolRoute() == nullptr) {
					FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
					return EBTNodeResult::Failed;
				}
			}
		}
		EnemyCont->SetEnemyState(NewEnemyState);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
