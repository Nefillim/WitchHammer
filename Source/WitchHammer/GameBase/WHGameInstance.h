// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameDataAsset.h"
#include "Engine/GameInstance.h"
#include "WHGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UWHGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GameData")
	UGameDataAsset* GetGameDataAsset() const;

protected:
	UPROPERTY()
	TSoftObjectPtr<UGameDataAsset> GameData;
};
