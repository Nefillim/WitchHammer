// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityAttributeSet.h"
#include "SpawnProjectileAbilityAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API USpawnProjectileAbilityAttributeSet : public UAbilityAttributeSet
{
	GENERATED_BODY()
	#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
public:
	UPROPERTY()
	int ProjectilesCount;

	UPROPERTY()
	TArray<FVector> Directions;

	UPROPERTY()
	float Spread; 
};
