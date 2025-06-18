// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
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
	static UGameDataAsset* Get(const UObject* WorldContext);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	UDataTable* ItemsDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	UDataTable* DefaultMeshesDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	TMap<FGameplayTag, int> InputIdMap;

	UFUNCTION()
	int InputIdByTag(FGameplayTag Tag);
};
