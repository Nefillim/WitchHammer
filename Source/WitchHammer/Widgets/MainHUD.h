// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomizationWiget.h"
#include "GameFramework/HUD.h"
#include "Inventory/InventoryWidget.h"
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
	UInventoryWidget* InventoryWindow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCustomizationWiget* CustomizationWindow;
};
