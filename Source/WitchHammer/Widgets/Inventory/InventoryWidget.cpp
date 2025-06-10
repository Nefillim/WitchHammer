// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "WitchHammer/Character/WitchHammerCharacter.h"

void UInventoryWidget::CreateSlot(UItemStack* ItemStack)
{
	if(auto SlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass))
	{
		SlotWidget->Init(ItemStack);
		InventorySlots.Add(SlotWidget);
	}
}

void UInventoryWidget::RefreshSlots()
{
	for(auto InventorySlotWidget : InventorySlots)
	{
		InventorySlotWidget->Destruct();
	}
	
	InventorySlots.Empty();
	
	if(PlayerController)
	{
		if(auto Character = Cast<AWitchHammerCharacter>(PlayerController->GetCharacter()))
		{
			if(auto Inventory = Character->GetInventoryComponent())
			{
				for(auto ItemStack : Inventory->GetItems())
				{
					
				}
			}
		}
	}
}

void UInventoryWidget::OnSlotSelected(UInventorySlotWidget* InventorySlot)
{
	SelectedSlot = InventorySlot;
}

void UInventoryWidget::EquipSelectedSlot()
{
	if(PlayerController)
	{
		if(auto Character = Cast<AWitchHammerCharacter>(PlayerController->GetCharacter()))
		{
			if(auto CustomisationComponent = Character->GetCustomizationComponent())
			{
				CustomisationComponent->EquipItem(SelectedSlot->ItemStack);
			}
		}
	}
}
