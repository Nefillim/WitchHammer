// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemStack.h"

#include "WitchHammer/Character/WitchHammerCharacter.h"

UItemStack* UItemStack::Create(int32 Count = 1)
{
	UItemStack* Stack = NewObject<UItemStack>();
	if(Stack)
	{
		Stack->Count = Count;
		Stack->OnEquipItem.AddUniqueDynamic(Stack, &UItem::OnEquip);
		Stack->OnUnEquipItem.AddUniqueDynamic(Stack, &UItem::OnUnEquip);
		return Stack;	
	}
	return nullptr;
}


