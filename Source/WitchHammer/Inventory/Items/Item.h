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
struct FItemAsset : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxCountInStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlotType SlotType;

	//TODO: Add ability data instead of spec, spec is created only after adding ability to AS
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> AbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag InputTag;

	FItemAsset(){}
	
	FItemAsset(FItemAsset* Asset);
	
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
	void SetupAsset(FString ItemId, UObject* WorldContext);
	
	UFUNCTION()
	void GenerateProps(FItemGeneratedProps Props);
	
	UFUNCTION()
	void OnEquip(ABaseCharacter* Character);
	
	UFUNCTION()
	void OnUnEquip(ABaseCharacter* Character);
	
	FOnEquipItem OnEquipItem;
	FOnUnEquipItem OnUnEquipItem;
};
