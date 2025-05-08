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

int UInventoryComponent::GetItemsCount(const FString& ItemId)
{
	if(ItemStacks.Contains(ItemId))
	{
		return ItemStacks[ItemId]->Count;
	}
	return 0;
}

void UInventoryComponent::AddItem(UItemStack* Item)
{
	if(ItemStacks.Contains(Item->Asset.Id))
	{
		ItemStacks[Item->Asset.Id]->Count+= Item->Count;
		OnAddItems.Broadcast(Item->Asset.Id, Item->Count);
		OnInventoryChanged.Broadcast();
		return;
	}
	ItemStacks.Add(Item->Asset.Id,Item);
	OnAddItems.Broadcast(Item->Asset.Id, Item->Count);
	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::RemoveItems(UItemStack* Item, int Count)
{
	if(ItemStacks.Contains(Item->Asset.Id))
	{
		auto ResCount = ItemStacks[Item->Asset.Id]->Count > Count ? ItemStacks[Item->Asset.Id]->Count - Count : 0;
		ItemStacks[Item->Asset.Id]->Count = ResCount;
		OnRemoveItems.Broadcast(Item->Asset.Id, ResCount);
		OnInventoryChanged.Broadcast();
	}
}


TArray<UItem*> UInventoryComponent::GetItems()
{
	TArray<UItem*> ResItems;
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
	
	return ResItems;
}

void UInventoryComponent::Empty()
{
	ItemStacks.Empty();
	
	OnInventoryChanged.Broadcast();
}






