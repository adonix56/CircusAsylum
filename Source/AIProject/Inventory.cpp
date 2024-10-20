// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	Items.Empty();
}

void UInventory::AddItem(UItem* NewItem)
{
	if (NewItem) Items.Add(NewItem);
}

void UInventory::RemoveItem(UItem* ItemToRemove)
{
	if (ItemToRemove && HasItem(ItemToRemove)) {
		Items.RemoveSingle(ItemToRemove);
	}
}

