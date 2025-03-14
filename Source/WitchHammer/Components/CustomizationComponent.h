// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlotType SlotType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* Mesh; 
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WITCHHAMMER_API UCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCustomizationComponent();
	
	TArray<FNameBySlotType> SlotNames;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<ESlotType, UItem*> EquippedItems;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DefaultMeshes")
	TArray<FMeshBySlotType> DefaultMeshes;
	
public:
	UFUNCTION()
	void EquipItem(ESlotType SlotType, UItem* Item);

	UFUNCTION()
	void UnEquipItem(ESlotType SlotType);

	UFUNCTION()
	void SetDefaultMeshes();
};
