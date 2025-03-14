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

	//If we want projectiles to move in different directions we use this array,
	//If directions count is less than projectiles count, it will take direction from index = projectileNumber % Directions.Num() 
	UPROPERTY()
	TArray<FVector> Directions;

	//If we want projectiles move in random direction near chosen one we set Spread > 0, for example if we are trying to create shotgun
	UPROPERTY()
	float Spread;

	//If we need projectiles to be spawned not in the same time we use SpawnDelay
	UPROPERTY()
	float SpawnDelay;
};
