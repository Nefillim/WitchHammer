// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItem;
class UUniqueItem;
class UItemStack;
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

	TMap<FName, UUniqueItem*> UniqueItems;

public:
	FOnAddItems OnAddItems;
	FOnRemoveItems OnRemoveItems;
	FOnInventoryChanged OnInventoryChanged;
	//Check if inventory contains item stack
	UFUNCTION()
	bool HasItems(const FString& ItemId);

	//Check if inventory contains unique item
	UFUNCTION()
	bool HasItem(FName ItemId);
	
	UFUNCTION()
	int GetItemsCount(const FString& ItemId);

	void AddItem(UUniqueItem* Item);

	void AddItem(UItemStack* Item);
	
	//Remove items from stacks
	UFUNCTION()
	void RemoveItems(FString ItemId, int Count);

	//Remove unique item
	UFUNCTION()
	void RemoveItem(FName ItemId);

	TArray<UItem*> GetItems();

	TArray<UItem*> GetItems(FString ItemId);

	UFUNCTION()
	void Empty();
};


