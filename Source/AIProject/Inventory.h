// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIPROJECT_API UInventory : public UObject
{
	GENERATED_BODY()
	
public:
	UInventory();

	UFUNCTION(BlueprintCallable)
	void AddItem(UItem* NewItem);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(UItem* ItemToRemove);

	UFUNCTION(BlueprintCallable)
	bool HasItem(UItem* ItemToRemove) { return Items.Contains(ItemToRemove); }

	UFUNCTION(BlueprintCallable)
	TArray<UItem*> GetItems() const { return Items; }

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<UItem*> Items;
};
