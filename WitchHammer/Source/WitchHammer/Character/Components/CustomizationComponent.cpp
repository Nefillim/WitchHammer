// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"

#include "WitchHammer/Character/MainCharacter.h"


// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	if(auto Character = Cast<AMainCharacter>(GetOwner()))
	{
		for(auto [SlotType,MeshComponent] : CustomizableMeshes)
		{
			MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(UEnum::GetValueAsName(SlotType));
			if(auto Mesh = DefaultMeshes.FindByPredicate([SlotType](FMeshBySlotType MeshBySlot){return MeshBySlot.SlotType == SlotType;})->Mesh)
			{
				MeshComponent->SetSkeletalMesh(Mesh);
			}
			MeshComponent->SetupAttachment(Character->GetMesh());
		}		
	}
}


// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();

	for(auto [SlotType,MeshComponent] : CustomizableMeshes)
	{
		if(auto Mesh = DefaultMeshes.FindByPredicate([SlotType](FMeshBySlotType MeshBySlot){return MeshBySlot.SlotType == SlotType;})->Mesh)
		{
			MeshComponent->SetSkeletalMesh(Mesh);
		}
	}	
}

void UCustomizationComponent::EquipItem(ESlotType SlotType, UItem* Item)
{
	EquippedItems.Add(SlotType, Item);
	if(CustomizableMeshes.Contains(SlotType))
	{
		CustomizableMeshes[SlotType]->SetSkeletalMesh(Item->Asset.Mesh);
	}
	OnEquipItem.Broadcast(SlotType,Item);
}

void UCustomizationComponent::UnEquipItem(ESlotType SlotType)
{
	if(EquippedItems.Contains(SlotType))
	{
		EquippedItems.Remove(SlotType);
	}
	if(CustomizableMeshes.Contains(SlotType))
	{
		CustomizableMeshes[SlotType]->SetSkeletalMesh(DefaultMeshes.FindByPredicate([SlotType](FMeshBySlotType MeshBySlot)
		{
			return MeshBySlot.SlotType == SlotType;
		})->Mesh);
	}
	OnUnEquipItem.Broadcast(SlotType);
}

