// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "CarClownCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackEnd);

/**
 * 
 */
UCLASS()
class AIPROJECT_API ACarClownCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void Attack(FVector TargetLocation);

	virtual void Tick(float DeltaTime) override;

	float GetDashOffset() const { return DashOffset; }

	FAttackEnd AttackEndEvent;

protected:

	UPROPERTY(EditDefaultsOnly, Category = Dash)
	UCurveFloat* DashCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dash)
	bool bIsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dash, meta = (AllowPrivateAccess = "true"))
	float DashSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dash, meta = (AllowPrivateAccess = "true"))
	float DashOffset;

	float CurrentDashTimer;
	float DashDuration;
	FVector DashEndLocation;
	FVector DashStartLocation;
};
