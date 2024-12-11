// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreUObjectClasses.h"
#include "ItemFactory.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UItemFactory : public UObject
{
	GENERATED_BODY()

	UFUNCTION()
	UItem* CreateItem(FString ItemId, FItemPostCreationProps Props);
};
