// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFactory.h"

#include "Items/ItemStack.h"
#include "WitchHammer/GameBase/GameDataAsset.h"

UItem* UItemFactory::CreateItemStack(FString ItemId, FItemGeneratedProps Props, int32 Count = 1)
{
	if(auto Stack = UItemStack::Create(Count))
	{
		Stack->SetupAsset(ItemId);
		Stack->GenerateProps(Props);
	}
	
	return nullptr;
}
