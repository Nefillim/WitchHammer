// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WitchHammer/Inventory/Items/ItemStack.h"
#include "WitchHammer/Inventory/Items/UniqueItem.h"
#include "InventoryComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAddItems, FString, int);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRemoveItems, FString, int);
DECLARE_MULTICAST_DELEGATE(FOnInventoryChanged);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WITCHHAMMER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<FString, UItemStack*> ItemStacks;

	TMap<FGuid, UUniqueItem*> UniqueItems;

public:
	//Check if inventory contains item stack
	UFUNCTION()
	bool HasItems(const FString& ItemId);

	//Check if inventory contains unique item
	UFUNCTION()
	bool HasItem(FGuid ItemId);
	
	UFUNCTION()
	int GetItemsCount(FString ItemId);

	UFUNCTION()
	void AddItem(UUniqueItem* Item);

	UFUNCTION()
	void AddItem(UItemStack* Item);
	
	//Remove items from stacks
	UFUNCTION()
	void RemoveItems(FString ItemId, int Count);

	//Remove unique item
	UFUNCTION()
	void RemoveItem(FGuid ItemId);

	UFUNCTION()
	TArray<UItem*> GetItems();

	UFUNCTION()
	TArray<UItem*> GetItems(FString ItemId);

	UFUNCTION()
	void Empty();
	
	
	FOnAddItems OnAddItems;
	FOnRemoveItems OnRemoveItems;
	FOnInventoryChanged OnInventoryChanged;
};


