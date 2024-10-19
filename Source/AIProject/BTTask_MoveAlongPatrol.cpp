// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "BTTask_MoveAlongPatrol.h"

UBTTask_MoveAlongPatrol::UBTTask_MoveAlongPatrol(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Move Along Patrol Path");
}

EBTNodeResult::Type UBTTask_MoveAlongPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn())) {
		if (APatrolRoute* PatrolRoute = Enemy->GetPatrolRoute()) {
			FVector NextLocation = PatrolRoute->GetNextPatrolLocation();
			OwnerComp.GetAIOwner()->MoveToLocation(NextLocation);
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), NextLocation);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::InProgress;
		}
	}
	return EBTNodeResult::Failed;
}
/*
void UBTTask_MoveAlongPatrol::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	EPathFollowingStatus::Type MoveStatus = OwnerComp.GetAIOwner()->GetPathFollowingComponent()->GetStatus();
	if (MoveStatus == EPathFollowingStatus::Idle) {
		UE_LOG(LogTemp, Warning, TEXT("MoveAlong: Idle"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
	else if (MoveStatus != EPathFollowingStatus::Moving) {
		UE_LOG(LogTemp, Warning, TEXT("MoveAlong: Failed"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("MoveAlong: Moving"));
	}
}*/
