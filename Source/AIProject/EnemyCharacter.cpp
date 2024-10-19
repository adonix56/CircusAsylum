// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyCharacter::SetMovementSpeed(EMovementSpeedType MovementType)
{
	switch (MovementType) {
	case EMovementSpeedType::IDLE:
		GetCharacterMovement()->MaxWalkSpeed = 0.f;
		break;
	case EMovementSpeedType::WALKING:
		GetCharacterMovement()->MaxWalkSpeed = 100.f;
		break;
	case EMovementSpeedType::JOGGING:
		GetCharacterMovement()->MaxWalkSpeed = 300.f;
		break;
	case EMovementSpeedType::SPRINTING:
		GetCharacterMovement()->MaxWalkSpeed = 500.f;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("EnemyCharacter: Invalid MovementType in SetMovementSpeed"));
		break;
	}
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

