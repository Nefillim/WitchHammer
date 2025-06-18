// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "WitchHammer/GameBase/GameDataAsset.h"

FItemAsset::FItemAsset(FItemAsset* Asset)
{
	Id = Asset->Id;
	Texture = Asset->Texture;
	Icon = Asset->Icon;
	MaxCountInStack = Asset->MaxCountInStack;
	AbilityClass = Asset->AbilityClass;
	Mesh = Asset->Mesh;
	InputTag = Asset->InputTag;
	SlotType = Asset->SlotType;
}

FItemAsset& FItemAsset::operator=(FItemAsset* ItemAsset)
{
	return *ItemAsset;
}

void UItem::SetupAsset(FString ItemId, UObject* WorldContext)
{
	if(auto GameData = UGameDataAsset::Get(WorldContext))
	{
		if(auto ItemsDataTable = GameData->ItemsDataTable)
		{
			if(FItemAsset* ItemAsset = ItemsDataTable->FindRow<FItemAsset>(FName(ItemId), ""))
			{
				Asset = FItemAsset(ItemAsset);
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
	if(Asset.AbilityClass)
	{
		if(auto GameData = UGameDataAsset::Get(Character->GetWorld()))
		{
			Character->BindAbility(Asset.AbilityClass, GameData->InputIdByTag(Asset.InputTag));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("GameData is not valid"));
		}
	}
}

void UItem::OnUnEquip(ABaseCharacter* Character)
{
	if(auto AbilitySystem = Character->GetAbilitySystemComponent())
	{
		if(GetWorld())
		{
			if(auto GameData = UGameDataAsset::Get(GetWorld()))
			{
				if(auto Ability = AbilitySystem->FindAbilitySpecFromInputID(GameData->InputIdByTag(Asset.InputTag)))
				{
					AbilitySystem->ClearAbility(Ability->Handle);
				}
			}
		}
	}
}
