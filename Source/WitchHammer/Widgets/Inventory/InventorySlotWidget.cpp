// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"

void UInventorySlotWidget::Init(UItemStack* Stack)
{
	StackIcon = Stack->Asset->Icon;
	ItemStack = Stack;
}
