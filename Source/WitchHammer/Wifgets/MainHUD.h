// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomizationWindow.h"
#include "GameFramework/HUD.h"
#include "Inventory/InventoryWindow.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryWindow* InventoryWindow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCustomizationWindow* CustomizationWindow;
};
