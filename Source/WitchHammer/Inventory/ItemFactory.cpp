// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFactory.h"

#include "Items/ItemStack.h"
#include "WitchHammer/GameBase/GameDataAsset.h"

UItemStack* UItemFactory::CreateItemStack(FString ItemId, UObject* WorldContext, FItemGeneratedProps Props, int32 Count)
{
	if(auto Stack = UItemStack::Create(Count))
	{
		Stack->SetupAsset(ItemId, WorldContext);
		Stack->GenerateProps(Props);
		return Stack;
	}
	return nullptr;
}
