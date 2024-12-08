// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Item.generated.h"

/**
 * 
 */
USTRUCT()
struct FItemAsset
{
	GENERATED_BODY()

	UPROPERTY()
	FString Id;

	UPROPERTY()
	UMeshComponent Mesh;

	UPROPERTY()
	UTexture2D* Texture;

	UPROPERTY()
	UTexture2D* Icon;
};

UCLASS()
class WITCHHAMMER_API UItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FString Id;	

	/*
	 * TODO Add item properties
	 */
};
