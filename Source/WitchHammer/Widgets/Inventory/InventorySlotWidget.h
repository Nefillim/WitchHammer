// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WitchHammer/Inventory/Items/ItemStack.h"
#include "InventorySlotWidget.generated.h"

UCLASS()
class WITCHHAMMER_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UTexture2D* StackIcon;

	UPROPERTY()
	UItemStack* ItemStack;

	UFUNCTION()
	void Init(UItemStack* Stack);
};
