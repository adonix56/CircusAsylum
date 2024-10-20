// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIProjectCharacter.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AIProjectController.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API AAIProjectController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAIProjectController();

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

protected:

	virtual void BeginPlay();
	virtual void OnPossess(APawn* aPawn) override;
	virtual void SetupInputComponent() override;

	AAIProjectCharacter* GetPlayerCharacter() { return Cast<AAIProjectCharacter>(GetPawn()); }

	void OnJumpStarted();
	void OnJumpCompleted();
	void OnMove(const FInputActionValue& Value);
	void OnLook(const FInputActionValue& Value);
};
