// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilityAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UAbilityAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
public:

	UPROPERTY()
	float AbilityAreaRadius;

	
};
