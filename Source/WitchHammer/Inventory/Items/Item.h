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

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEquipItem, ABaseCharacter*);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUnEquipItem, ABaseCharacter*);

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
};

//Item properties that must be set in ItemFactory (like unique random bonuses)
USTRUCT()
struct FItemPostCreationProps
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
	FString DataTableId;
	
	UPROPERTY()
	FItemAsset Asset; 
	
	
	FOnEquipItem OnEquipItem;
	FOnUnEquipItem OnUnEquipItem;
};
