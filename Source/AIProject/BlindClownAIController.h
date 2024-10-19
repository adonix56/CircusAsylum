// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAIController.h"
#include "EnemyCharacter.h"
#include "AIProjectCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AIPerceptionComponent.h"
#include "BlindClownAIController.generated.h"

/**
 *
 */
UCLASS()
class AIPROJECT_API ABlindClownAIController : public AEnemyAIController
{
	GENERATED_BODY()

public:
	ABlindClownAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

	UAISenseConfig_Hearing* HearingConfig;
	void SetupPerceptionSystem();
	void SetupPerceptionConfig();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus);
};
