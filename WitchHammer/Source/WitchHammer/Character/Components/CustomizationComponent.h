// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WitchHammer/Inventory/Item.h"
#include "CustomizationComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnEquipItem, ESlotType, UItem);

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnUnEquipItem, ESlotType, UItem);

UENUM()
enum ESlotType
{
	None,
	Head,
	Body,
	LeftArm,
	RightArm,
	Back,
	Hips,
	Legs
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WITCHHAMMER_API UCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCustomizationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<ESlotType, UItem*> EquippedItems;
public:
	UFUNCTION()
	void EquipItem(ESlotType SlotType, UItem* Item);

	UFUNCTION()
	void UnEquipItem(ESlotType SlotType, UItem* Item);

	FOnEquipItem OnEquipItem;
	FOnUnEquipItem OnUnEquipItem;
};
