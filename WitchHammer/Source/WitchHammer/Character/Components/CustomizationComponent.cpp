// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"


// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCustomizationComponent::EquipItem(ESlotType SlotType, UItem* Item)
{
	if(EquippedItems.Contains(SlotType))
	{
		UnEquipItem(SlotType, Item);
	}
	EquippedItems.Add(SlotType, Item);	
}

void UCustomizationComponent::UnEquipItem(ESlotType SlotType, UItem* Item)
{
	if(EquippedItems.Contains(SlotType))
	{
		EquippedItems.Remove(SlotType);
	}
}

