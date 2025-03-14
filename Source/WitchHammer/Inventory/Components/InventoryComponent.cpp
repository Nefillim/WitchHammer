// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "IDetailTreeNode.h"
#include "Kismet/GameplayStatics.h"
#include "WitchHammer/Inventory/Items/ItemStack.h"
#include "WitchHammer/Inventory/Items/UniqueItem.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UInventoryComponent::HasItems(const FString& ItemId)
{
	return ItemStacks.Contains(ItemId);
}

bool UInventoryComponent::HasItem(const FName ItemId)
{
	return UniqueItems.Contains(ItemId);
}

int UInventoryComponent::GetItemsCount(const FString& ItemId)
{
	if(ItemStacks.Contains(ItemId))
	{
		return ItemStacks[ItemId]->Count;
	}
	return 0;
}

void UInventoryComponent::AddItem(UUniqueItem* Item)
{
	UniqueItems.Emplace(Item->Id,Item);
	OnAddItems.Broadcast(Item->DataTableId, 1);
	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::AddItem(UItemStack* Item)
{
	if(ItemStacks.Contains(Item->DataTableId))
	{
		ItemStacks[Item->DataTableId]->Count+= Item->Count;
		OnAddItems.Broadcast(Item->DataTableId, Item->Count);
		OnInventoryChanged.Broadcast();
		return;
	}
	ItemStacks.Add(Item->DataTableId,Item);
	OnAddItems.Broadcast(Item->DataTableId, Item->Count);
	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::RemoveItems(FString ItemId, int Count)
{
	if(ItemStacks.Contains(ItemId))
	{
		auto ResCount = ItemStacks[ItemId]->Count > Count ? ItemStacks[ItemId]->Count - Count : 0;
		ItemStacks[ItemId]->Count = ResCount;
		OnRemoveItems.Broadcast(ItemId, ResCount);
		OnInventoryChanged.Broadcast();
	}
}

void UInventoryComponent::RemoveItem(FName ItemId)
{
	if(UniqueItems.Contains(ItemId))
	{
		const FString RemovedId = UniqueItems[ItemId]->DataTableId;
		UniqueItems.Remove(ItemId);
		OnRemoveItems.Broadcast(RemovedId, 1);
		OnInventoryChanged.Broadcast();
	}
}

TArray<UItem*> UInventoryComponent::GetItems()
{
	TArray<UItem*> ResItems;
	for(auto [Id, Item] : UniqueItems)
	{
		ResItems.AddUnique(Item);
	}
	for(auto [Id, Item] : ItemStacks)
	{
		ResItems.AddUnique(Item);
	}
	return ResItems;
}

TArray<UItem*> UInventoryComponent::GetItems(FString ItemId)
{
	TArray<UItem*> ResItems;
	for(auto [Id, Item] : ItemStacks)
	{
		ResItems.AddUnique(Item);
	}
	for(auto [Id, Item] : UniqueItems)
	{
		if(Item->DataTableId == ItemId)
		{
			ResItems.AddUnique(Item);
		}
	}
	return ResItems;
}

void UInventoryComponent::Empty()
{
	UniqueItems.Empty();
	ItemStacks.Empty();
	
	OnInventoryChanged.Broadcast();
}






