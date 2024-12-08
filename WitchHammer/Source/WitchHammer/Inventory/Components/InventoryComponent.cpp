// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UInventoryComponent::HasItems(FString ItemId)
{
	return ItemStacks.Contains(ItemId) & ItemStacks[ItemId]->Items.Num() > 0;
}

int UInventoryComponent::GetItemsCount(FString ItemId)
{
	return ItemStacks.Contains(ItemId) ? ItemStacks[ItemId]->Items.Num() : 0;
}

void UInventoryComponent::AddItems(UItemStack* ItemStack)
{
	if(ItemStack)
	{
		if(!ItemStacks.Contains(ItemStack->Id))
		{
			ItemStacks.Add(ItemStack->Id, ItemStack);
		}
		ItemStacks[ItemStack->Id]->Items.Append(ItemStack->Items);
		OnAddItems.Broadcast(ItemStack);
	}
}

void UInventoryComponent::RemoveItems(FString ItemId, int Count)
{
	const auto RemovedCount = ItemStacks[ItemId]->Items.Num() > Count ? Count : ItemStacks[ItemId]->Items.Num();
	ItemStacks[ItemId]->Items.RemoveAll(RemovedCount);
	if(!ItemStacks[ItemId]->Items.Num() > 0)
	{
		ItemStacks.Remove(ItemId);
	}
	OnRemoveItems.Broadcast(ItemId, RemovedCount);
}





