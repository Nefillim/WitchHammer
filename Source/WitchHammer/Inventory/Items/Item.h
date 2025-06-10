// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WitchHammer/Character/BaseCharacter.h"
#include "Item.generated.h"

/**
 * 
 */
//Item properties that must be set in data table

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquipItem, ABaseCharacter*, Character);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnEquipItem, ABaseCharacter*, Character);

USTRUCT()
struct FItemAsset
{
	GENERATED_BODY()

	UPROPERTY()
	FString Id;

	UPROPERTY()
	USkeletalMesh* Mesh;

	UPROPERTY()
	UTexture2D* Texture;

	UPROPERTY()
	UTexture2D* Icon;

	UPROPERTY()
	int32 MaxCountInStack;

	UPROPERTY()
	ESlotType SlotType;

	UPROPERTY()
	FGameplayAbilitySpec AbilitySpec;
	
	FItemAsset& operator=(FItemAsset* ItemAsset);
};

//Item properties that must be set in ItemFactory (like unique random bonuses)
//Use for save items generated props data between sessions
USTRUCT()
struct FItemGeneratedProps
{
	GENERATED_BODY()
	//if true recreate props or dont use struct
	bool bEmpty = true;

	
};


UCLASS()
class WITCHHAMMER_API UItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FItemAsset Asset;

	UFUNCTION()
	void SetupAsset(FString ItemId);
	
	UFUNCTION()
	void GenerateProps(FItemGeneratedProps Props);
	
	UFUNCTION()
	void OnEquip(ABaseCharacter* Character);
	
	UFUNCTION()
	void OnUnEquip(ABaseCharacter* Character);
	
	FOnEquipItem OnEquipItem;
	FOnUnEquipItem OnUnEquipItem;
};
