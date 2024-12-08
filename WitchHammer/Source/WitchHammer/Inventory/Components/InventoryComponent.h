// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WitchHammer/Inventory/Item.h"
#include "WitchHammer/Inventory/ItemStack.h"
#include "InventoryComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAddItems, UItemStack*);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRemoveItems, FString, int);

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

public:
	UFUNCTION()
	bool HasItems(FString ItemId);

	UFUNCTION()
	int GetItemsCount(FString ItemId);
	
	UFUNCTION()
	void AddItems(UItemStack* ItemStack);

	UFUNCTION()
	void RemoveItems(FString ItemId, int Count);

	FOnAddItems OnAddItems;
	FOnRemoveItems OnRemoveItems;
};
