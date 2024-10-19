// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAIController.h"
#include "CarClownCharacter.h"
#include "AIProjectCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "CarClownAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API ACarClownAIController : public AEnemyAIController
{
	GENERATED_BODY()

public:
	ACarClownAIController();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void StartAttack(FVector TargetLocation);

protected:
	virtual void OnPossess(APawn* InPawn) override; 
	virtual void OnUnPossess() override;

	UAISenseConfig_Sight* SightConfig; 
	void SetupPerceptionSystem();
	void SetupPerceptionConfig();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus);

	UFUNCTION()
	void EndAttack();

	ACarClownCharacter* CurEnemy;

};
