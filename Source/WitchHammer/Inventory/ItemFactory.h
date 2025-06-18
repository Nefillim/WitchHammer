// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreUObjectClasses.h"
#include "Items/Item.h"
#include "Items/ItemStack.h"
#include "ItemFactory.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UItemFactory : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static UItemStack* CreateItemStack(FString ItemId, UObject* WorldContext, FItemGeneratedProps Props = FItemGeneratedProps(),
	                                   int32 Count = 1);
};
