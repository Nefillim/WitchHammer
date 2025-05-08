// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySlotWidget.h"
#include "Blueprint/UserWidget.h"
#include "WitchHammer/WitchHammerPlayerController.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;

	UPROPERTY()
	AWitchHammerPlayerController* PlayerController;
	
	UPROPERTY()
	TArray<UInventorySlotWidget*> InventorySlots;

	UPROPERTY()
	UInventorySlotWidget* SelectedSlot;

	UFUNCTION()
	void CreateSlot(UItemStack* ItemStack);

	UFUNCTION()
	void RefreshSlots();

	UFUNCTION()
	void OnSlotSelected(UInventorySlotWidget* Slot);

	UFUNCTION()
	void EquipSelectedSlot();
};
