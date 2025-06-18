// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"

#include "WitchHammer/Character/WitchHammerCharacter.h"
#include "WitchHammer/Inventory/Items/Item.h"


// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCustomizationComponent::EquipItem(UItem* Item)
{
	if(Item)
	{
		if(auto Character = Cast<AWitchHammerCharacter>(GetOwner()))
		{
			auto SlotType = Item->Asset.SlotType;
			if(EquippedItems.Contains(SlotType))
			{
				if(SlotType == ESlotType::RightArm)
				{
					SlotType = ESlotType::LeftArm;
					if(EquippedItems.Contains(SlotType))
					{
						UnEquipItem(SlotType);
					}
				}else
				{
					UnEquipItem(SlotType);
				}
			}
		
			EquippedItems.Emplace(SlotType, Item);

			if(Character->CustomizableMeshes.Contains(SlotType))
			{
				if(Item->Asset.Mesh)
				{
					if(Character->CustomizableMeshes[SlotType])
					{
						Character->CustomizableMeshes[SlotType]->SetSkeletalMesh(Item->Asset.Mesh);
					}
				}
			}
			Item->OnEquipItem.Broadcast(Character);	
		}	
	}
}

void UCustomizationComponent::UnEquipItem(ESlotType SlotType)
{
	if(auto Character = Cast<AWitchHammerCharacter>(GetOwner()))
	{
		if(EquippedItems.Contains(SlotType))
		{
			EquippedItems[SlotType]->OnUnEquipItem.Broadcast(Character);
			EquippedItems.Remove(SlotType);
		}
		if(Character->CustomizableMeshes.Contains(SlotType))
		{
			if(DefaultMeshes.FindByPredicate([SlotType](FMeshBySlotType MeshBySlot){return MeshBySlot.SlotType == SlotType;})->Mesh)
			{
				Character->CustomizableMeshes[SlotType]->SetSkeletalMesh(
					DefaultMeshes.FindByPredicate([SlotType](FMeshBySlotType MeshBySlot){return MeshBySlot.SlotType == SlotType;})->Mesh);
			}
		}
		
	}
}

void UCustomizationComponent::SetDefaultMeshes()
{
	for(auto [SLotType, Item] : EquippedItems)
	{
		UnEquipItem(SLotType);
	}
}



