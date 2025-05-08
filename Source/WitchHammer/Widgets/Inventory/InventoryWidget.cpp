// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "WitchHammer/Character/WitchHammerCharacter.h"

void UInventoryWidget::CreateSlot(UItemStack* ItemStack)
{
	if(auto Slot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass))
	{
		Slot->Init(ItemStack);
		InventorySlots.Add(Slot);
	}
}

void UInventoryWidget::RefreshSlots()
{
	for(auto Slot : InventorySlots)
	{
		Slot->Destruct();
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

void UInventoryWidget::OnSlotSelected(UInventorySlotWidget* Slot)
{
	SelectedSlot = Slot;
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
