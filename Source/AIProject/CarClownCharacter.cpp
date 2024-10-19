// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetMathLibrary.h"
#include "CarClownCharacter.h"

void ACarClownCharacter::Attack(FVector TargetLocation)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Format(TEXT("CarClown: Attack at {0} {1} {2}"), { TargetLocation.X, TargetLocation.Y, TargetLocation.Z }));
	//SetActorLocation(TargetLocation);
	DashEndLocation = TargetLocation;
	DashStartLocation = GetActorLocation();
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(DashStartLocation, DashEndLocation));
	CurrentDashTimer = 0.f;
	DashDuration = FVector::Dist(DashStartLocation, DashEndLocation) / DashSpeed;
	bIsAttacking = true;
}

void ACarClownCharacter::Tick(float DeltaTime)
{
	if (bIsAttacking && DashCurve != nullptr) {
		SetActorLocation(FMath::Lerp(DashStartLocation, DashEndLocation, DashCurve->GetFloatValue(CurrentDashTimer / DashDuration)));
		if (FMath::IsNearlyEqual(CurrentDashTimer, DashDuration)) {
			bIsAttacking = false;
			AttackEndEvent.Broadcast();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("CarClownCharacter: End Attack Broadcasted"));
		}
		CurrentDashTimer = FMath::Clamp(CurrentDashTimer + DeltaTime, 0.f, DashDuration);
	}
}
