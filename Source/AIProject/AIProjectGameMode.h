// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Item.h"
#include "AIProjectGameMode.generated.h"

UCLASS(minimalapi)
class AAIProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAIProjectGameMode();

	UFUNCTION(BlueprintCallable)
	UItem* GetItemByID(int ItemID);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDataTable* ItemCatalogue;

};



