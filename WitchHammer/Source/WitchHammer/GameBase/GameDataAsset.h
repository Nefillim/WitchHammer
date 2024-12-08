// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UGameDataAsset : public UDataAsset
{
	GENERATED_BODY()

	protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	UDataTable ItemsDataTable;
	
};
