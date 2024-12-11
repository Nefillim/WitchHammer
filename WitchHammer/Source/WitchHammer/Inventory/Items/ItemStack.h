// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
#include "ItemStack.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UItemStack : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int Count = 0;
};
