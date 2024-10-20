// Fill out your copyright notice in the Description page of Project Settings.


#include "AIProjectController.h"

AAIProjectController::AAIProjectController()
{
}

void AAIProjectController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	
	if (HUDWidgetClass) {
		HUDInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDInstance) {
			HUDInstance->AddToViewport();
		}
	}
}

void AAIProjectController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SendInteractRaycast();
}

void AAIProjectController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
}

void AAIProjectController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AAIProjectController::OnJumpStarted);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AAIProjectController::OnJumpCompleted);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAIProjectController::OnMove);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAIProjectController::OnLook);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AAIProjectController::OnInteractStarted);
		EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &AAIProjectController::OnInventoryStarted);
	}
	else {
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AAIProjectController::SendInteractRaycast()
{
	FVector CameraLocation;
	FRotator CameraRotation;
	GetPlayerViewPoint(CameraLocation, CameraRotation);

	FVector InteractVector = CameraLocation + (CameraRotation.Vector() * InteractDistance);

	FHitResult HitResult;
	FCollisionQueryParams HitParams;
	HitParams.AddIgnoredActor(GetPawn());

	if (GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, InteractVector, ECC_Visibility, HitParams)) {
		if (AInteractable_Base* Interactable = Cast<AInteractable_Base>(HitResult.GetActor())) {
			FocusedInteractable = Interactable;
			FocusedInteractable->InRange(true);
		}
		else {
			if (FocusedInteractable) {
				FocusedInteractable->InRange(false);
				FocusedInteractable = nullptr;
			}
		}
	}
	else {
		if (FocusedInteractable) {
			FocusedInteractable->InRange(false);
			FocusedInteractable = nullptr;
		}
	}

}

void AAIProjectController::OnJumpStarted()
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	if (PlayerCharacter) {
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

void AAIProjectController::OnInteractStarted()
{
	if (FocusedInteractable) {
		FocusedInteractable->Interact();
		AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
		if (PlayerCharacter && FocusedInteractable->IsItem()) {
			UE_LOG(LogTemp, Warning, TEXT("Controller: Interact GetItem"));
			PlayerCharacter->AcquireItem(FocusedInteractable->GetItem());
		}
	}
}

void AAIProjectController::OnInventoryStarted()
{
	AAIProjectCharacter* PlayerCharacter = GetPlayerCharacter();
	if (PlayerCharacter) {
		PlayerCharacter->PrintItems();
	}
}
