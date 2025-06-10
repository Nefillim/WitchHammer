// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "WitchHammer/GameBase/GameDataAsset.h"

FItemAsset& FItemAsset::operator=(FItemAsset* ItemAsset)
{
	return *ItemAsset;
}

void UItem::SetupAsset(FString ItemId)
{
	if(auto GameData = UGameDataAsset::Get(GetWorld()))
	{
		if(auto ItemsDataTable = GameData->ItemsDataTable)
		{
			if(FItemAsset* ItemAsset = ItemsDataTable->FindRow<FItemAsset>(FName(ItemId), ""))
			{
				Asset = ItemAsset;				
			}
		}
	}
}

void UItem::GenerateProps(FItemGeneratedProps Props)
{
	if(Props.bEmpty)
		return;

	//Generate random bonuses etc.
}

void UItem::OnEquip(ABaseCharacter* Character)
{
	if(auto AbilitySystem = Character->GetAbilitySystemComponent())
	{
		AbilitySystem->GiveAbility(Asset.AbilitySpec);
	}
}

void UItem::OnUnEquip(ABaseCharacter* Character)
{
	if(auto AbilitySystem = Character->GetAbilitySystemComponent())
	{
		AbilitySystem->ClearAbility(Asset.AbilitySpec.Handle);
	}
}
