// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_EnemyState.h"

UBTDecorator_EnemyState::UBTDecorator_EnemyState(FObjectInitializer const& ObjectInitializer) {
	NodeName = TEXT("Enemy State Is");
}

bool UBTDecorator_EnemyState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AEnemyAIController* EnemyCont = Cast<AEnemyAIController>(OwnerComp.GetAIOwner())) {
		return EnemyCont->GetEnemyState() == EnemyState;
	}
	return false;
}
