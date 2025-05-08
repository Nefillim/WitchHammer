// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataAsset.h"

#include "WHGameInstance.h"

class UWHGameInstance;

UGameDataAsset* UGameDataAsset::Get(const UObject* WorldContext)
{
	ensure(WorldContext);
	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::LogAndReturnNull)) {
		if (UWHGameInstance* GameInstance = World->GetGameInstance<UWHGameInstance>()) {
			return GameInstance->GetGameDataAsset();
		}
	}

	return nullptr;
}
