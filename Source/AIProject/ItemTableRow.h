// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemTableRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct AIPROJECT_API FItemTableRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (MultiLine = "true"))
	FString Description;
};
