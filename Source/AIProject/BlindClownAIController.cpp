// Fill out your copyright notice in the Description page of Project Settings.


#include "BlindClownAIController.h"

ABlindClownAIController::ABlindClownAIController()
{
	SetupPerceptionSystem();
}

void ABlindClownAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(InPawn)) {
		if (UBehaviorTree* EnemyTree = Enemy->GetBehaviorTree()) {
			UBlackboardComponent* BlackboardTemp;
			UseBlackboard(EnemyTree->BlackboardAsset, BlackboardTemp);
			Blackboard = BlackboardTemp;
			RunBehaviorTree(EnemyTree);
			SetupPerceptionConfig();
		}
	}
}

void ABlindClownAIController::SetupPerceptionSystem()
{
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
	if (HearingConfig) {
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		HearingConfig->HearingRange = 0.f;
		HearingConfig->SetMaxAge(3.0f);
		HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
		HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
		HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
		GetPerceptionComponent()->SetDominantSense(*HearingConfig->GetSenseImplementation());
		GetPerceptionComponent()->ConfigureSense(*HearingConfig);
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABlindClownAIController::OnTargetDetected);
	}
}

void ABlindClownAIController::SetupPerceptionConfig()
{
	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(GetPawn());
	if (HearingConfig && Enemy) {
		HearingConfig->HearingRange = Enemy->GetHearingRange();
		GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	}
}

void ABlindClownAIController::OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus)
{
	if (AAIProjectCharacter* Player = Cast<AAIProjectCharacter>(Actor)) {
		bool Sensed = Stimulus.WasSuccessfullySensed();
		GetBlackboardComponent()->SetValueAsObject("Player", Sensed ? Player : nullptr);
		if (Sensed) {
			SetEnemyState(EEnemyStateType::CHASING);
		}
	}
}