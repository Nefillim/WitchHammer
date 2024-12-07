// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WitchHammerGameMode.generated.h"

UCLASS(minimalapi)
class AWitchHammerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWitchHammerGameMode();
	virtual void BeginPlay() override;
};



