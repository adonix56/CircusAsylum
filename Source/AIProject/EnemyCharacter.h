// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolRoute.h"
#include "EnemyCharacter.generated.h"

class UBehaviorTree;

UENUM(BlueprintType)
enum class EMovementSpeedType : uint8 {
	IDLE = 0 UMETA(DisplayName = "Idle"),
	WALKING = 1 UMETA(DisplayName = "Walking"),
	JOGGING = 2 UMETA(DisplayName = "Jogging"),
	SPRINTING = 3 UMETA(DisplayName = "Sprinting")
};

UCLASS()
class AIPROJECT_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

	float GetHearingRange() const { return HearingRange; }
	float GetSightRadius() const { return SightRadius; }
	float GetLoseSightRadius() const { return LoseSightRadius; }

	UFUNCTION(BlueprintCallable)
	APatrolRoute* GetPatrolRoute() const { return PatrolRoute; }

	UFUNCTION(BlueprintCallable)
	void SetMovementSpeed(EMovementSpeedType MovementType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	float HearingRange; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	float SightRadius; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	float LoseSightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	APatrolRoute* PatrolRoute;

};
