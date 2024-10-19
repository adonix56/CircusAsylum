// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_CarClownDash.h"

UBTTask_CarClownDash::UBTTask_CarClownDash(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Car Clown Dash");
}

EBTNodeResult::Type UBTTask_CarClownDash::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ACarClownAIController* EnemyCont = Cast<ACarClownAIController>(OwnerComp.GetAIOwner())) {
		FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());
		EnemyCont->StartAttack(TargetLocation);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
