// Fill out your copyright notice in the Description page of Project Settings.


#include "AIProjectController.h"

AAIProjectController::AAIProjectController()
{
}

void AAIProjectController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
		UE_LOG(LogTemp, Warning, TEXT("AIProjectController: Beginplay and if"));
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AAIProjectController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	UE_LOG(LogTemp, Warning, TEXT("AIProjectController: OnPossess"));
}

void AAIProjectController::SetupInputComponent()
{
	UE_LOG(LogTemp, Warning, TEXT("AIProjectController: SetupInputComponent"));
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AAIProjectController::OnJumpStarted);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AAIProjectController::OnJumpCompleted);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAIProjectController::OnMove);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAIProjectController::OnLook);
	}
	else {
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AAIProjectController::OnJumpStarted()
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	UE_LOG(LogTemp, Warning, TEXT("AIProjectController: Before Jump"));
	if (PlayerCharacter) {
		UE_LOG(LogTemp, Warning, TEXT("AIProjectController: Jump"));
		PlayerCharacter->Jump();
	}
}

void AAIProjectController::OnJumpCompleted()
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	if (PlayerCharacter) {
		PlayerCharacter->StopJumping();
	}
}

void AAIProjectController::OnMove(const FInputActionValue& Value)
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	if (PlayerCharacter) {
		PlayerCharacter->Move(Value);
	}
}

void AAIProjectController::OnLook(const FInputActionValue& Value)
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	if (PlayerCharacter) {
		PlayerCharacter->Look(Value);
	}
}
