// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIProjectGameMode.h"
#include "AIProjectCharacter.h"
#include "AIProjectController.h"
#include "ItemTableRow.h"
#include "UObject/ConstructorHelpers.h"

AAIProjectGameMode::AAIProjectGameMode()
{
	PlayerControllerClass = AAIProjectController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_AIProjectController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	ItemCatalogue = LoadObject<UDataTable>(nullptr, TEXT("/Game/Interactables/ItemCatalogue"));
}

UItem* AAIProjectGameMode::GetItemByID(int ItemID)
{
	FItemTableRow* Row = ItemCatalogue->FindRow<FItemTableRow>(FName(FString::FromInt(ItemID)), TEXT("GameMode GetItemByID"));
	if (Row) {
		UItem* GetItem = NewObject<UItem>();
		GetItem->ItemID = ItemID;
		GetItem->ItemName = Row->ItemName;
		GetItem->ItemDescription = Row->Description;
		return GetItem;
	}
	return nullptr;
}
