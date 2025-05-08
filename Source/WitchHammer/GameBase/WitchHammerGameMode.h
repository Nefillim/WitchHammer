// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameDataAsset.h"
#include "GameFramework/GameModeBase.h"
#include "WitchHammer/Inventory/ItemFactory.h"
#include "WitchHammerGameMode.generated.h"

UCLASS(minimalapi)
class AWitchHammerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWitchHammerGameMode();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGameDataAsset* GameData;
};



