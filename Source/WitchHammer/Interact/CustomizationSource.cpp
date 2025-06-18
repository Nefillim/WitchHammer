// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationSource.h"

#include "WitchHammer/Components/InventoryComponent.h"
#include "WitchHammer/Inventory/ItemFactory.h"
#include "WitchHammer/Inventory/Items/ItemStack.h"

void ACustomizationSource::BeginPlay()
{
	Super::BeginPlay();
	InteractionComponent->OnStartInteraction.BindDynamic(this, &ACustomizationSource::OnInteract);
}

ACustomizationSource::ACustomizationSource()
{
	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"));
}

void ACustomizationSource::OnInteract(ABaseCharacter* Source)
{
	if(auto CustomizationComponent = Source->GetCustomizationComponent())
	{
		if(auto Inventory = Source->GetInventoryComponent())
		{
			/*if(Inventory->HasItems(ItemId))
			{
				auto Item = Inventory->GetItems(ItemId)[0];
				CustomizationComponent->EquipItem(Item);
				return;
			}*/
			
			auto Item = UItemFactory::CreateItemStack(ItemId, Source->GetWorld());
			//Inventory->AddItem(Item);
			CustomizationComponent->EquipItem(Item);
		}
	}
}
