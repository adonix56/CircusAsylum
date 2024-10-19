// Fill out your copyright notice in the Description page of Project Settings.


#include "CarClownAIController.h"

ACarClownAIController::ACarClownAIController()
{
	SetupPerceptionSystem();
}

void ACarClownAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ACarClownCharacter* Enemy = Cast<ACarClownCharacter>(InPawn)) {
		CurEnemy = Enemy;
		CurEnemy->AttackEndEvent.AddDynamic(this, &ACarClownAIController::EndAttack);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("CarClownAIController: Bind To End Attack"));
		if (UBehaviorTree* EnemyTree = CurEnemy->GetBehaviorTree()) {
			UBlackboardComponent* BlackboardTemp;
			UseBlackboard(EnemyTree->BlackboardAsset, BlackboardTemp);
			Blackboard = BlackboardTemp;
			RunBehaviorTree(EnemyTree);
			SetupPerceptionConfig();
		}
	}
}

void ACarClownAIController::OnUnPossess()
{
	Super::OnUnPossess();

	CurEnemy->AttackEndEvent.RemoveDynamic(this, &ACarClownAIController::EndAttack);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("CarClownAIController: Unbind To End Attack"));
}

void ACarClownAIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (SightConfig) {
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		SightConfig->SightRadius = 0.f;
		SightConfig->LoseSightRadius = 0.0f;
		SightConfig->PeripheralVisionAngleDegrees = 45.f;
		SightConfig->SetMaxAge(3.0f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ACarClownAIController::OnTargetDetected);
	}
}

void ACarClownAIController::SetupPerceptionConfig()
{
	//ACarClownCharacter* Enemy = Cast<ACarClownCharacter>(GetPawn());
	if (SightConfig && CurEnemy) {
		SightConfig->SightRadius = CurEnemy->GetSightRadius();
		SightConfig->LoseSightRadius = CurEnemy->GetLoseSightRadius();
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
	}
}

void ACarClownAIController::OnTargetDetected(AActor* Actor, const FAIStimulus Stimulus)
{
	if (AAIProjectCharacter* Player = Cast<AAIProjectCharacter>(Actor)) {
		if (CurEnemy) {
			bool Sensed = Stimulus.WasSuccessfullySensed();
			FVector TargetLocation = Player->GetActorLocation() - CurEnemy->GetActorLocation();
			TargetLocation = CurEnemy->GetDashOffset() * TargetLocation.GetSafeNormal() + TargetLocation;
			TargetLocation = CurEnemy->GetActorLocation() + TargetLocation;
			GetBlackboardComponent()->SetValueAsVector("PerceivedLocation", Sensed ? TargetLocation : CurEnemy->GetActorLocation());
			if (Sensed) {
				SetEnemyState(EEnemyStateType::CHASING);
			}
		}
	}
}

void ACarClownAIController::EndAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("CarClownAIController: End Attack Received"));
	SetEnemyState(EEnemyStateType::IDLE);
}

void ACarClownAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEnemyStateType"), true);
	if (EnumPtr)
	{
		FString EnumName = EnumPtr->GetNameStringByIndex(static_cast<int32>(EnemyState));
		FString DisplayName = EnumPtr->GetDisplayNameTextByIndex(static_cast<int32>(EnemyState)).ToString();

		// Add debug message
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Red, FString::Printf(TEXT("Enum Name: %s, Display Name: %s"), *EnumName, *DisplayName));
		}
	}
}

void ACarClownAIController::StartAttack(FVector TargetLocation)
{
	if (CurEnemy) {
		SetEnemyState(EEnemyStateType::ATTACKING);
		CurEnemy->Attack(TargetLocation);
	}
}
