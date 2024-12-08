// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStack.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UItemStack : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	TArray<UItem*> Items;
	
	UPROPERTY()
	int MaxStackSize = -1;
};
