// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "UniqueItem.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UUniqueItem : public UItem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FGuid Id;
};
