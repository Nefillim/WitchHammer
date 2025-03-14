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

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	UDataTable* ItemsDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	UDataTable* DefaultMeshesDataTable;
	
};
