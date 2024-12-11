// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WitchHammer/Inventory/Item.h"
#include "CustomizationComponent.generated.h"
UENUM(BlueprintType)
enum class ESlotType : uint8
{
	Head,
	Body,
	Back,
	LeftArm,
	RightArm,
	Hips,
	Legs,
};

USTRUCT(BlueprintType)
struct FNameBySlotType
{
	GENERATED_BODY()

	ESlotType SlotType;
	FName SlotName;
};

USTRUCT(BlueprintType)
struct FMeshBySlotType
{
	GENERATED_BODY()

	UPROPERTY()
	ESlotType SlotType;
	
	UPROPERTY()
	USkeletalMesh* Mesh; 
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnEquipItem, ESlotType, UItem*);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUnEquipItem, ESlotType);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WITCHHAMMER_API UCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCustomizationComponent();
	
	TArray<FNameBySlotType> SlotNames;

	USkeletalMeshComponent* GetMeshBySlot(ESlotType SlotType)
	{
		return CustomizableMeshes[SlotType];
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<ESlotType, UItem*> EquippedItems;

	//Meshes
	UPROPERTY()
	USkeletalMeshComponent* Head;
	
	UPROPERTY()
	USkeletalMeshComponent* Body;
	
	UPROPERTY()
	USkeletalMeshComponent* LeftArm;
	
	UPROPERTY()
	USkeletalMeshComponent* RightArm;
	
	UPROPERTY()
	USkeletalMeshComponent* Back;
	
	UPROPERTY()
	USkeletalMeshComponent* Hips;
	
	UPROPERTY()
	USkeletalMeshComponent* Legs;
	
	TMap<ESlotType, USkeletalMeshComponent*> CustomizableMeshes{
		{ESlotType::Head, Head},
	{ESlotType::Body, Body},
	{ESlotType::Back, Back},
	{ESlotType::LeftArm, LeftArm},
	{ESlotType::RightArm, RightArm},
	{ESlotType::Hips, Hips},
	{ESlotType::Legs, Legs},
	};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DefaultMeshes")
	TArray<FMeshBySlotType> DefaultMeshes;
	
public:
	UFUNCTION()
	void EquipItem(ESlotType SlotType, UItem* Item);

	UFUNCTION()
	void UnEquipItem(ESlotType SlotType);

	FOnEquipItem OnEquipItem;
	FOnUnEquipItem OnUnEquipItem;
};
