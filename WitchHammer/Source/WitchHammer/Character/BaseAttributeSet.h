// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
public:
	UPROPERTY()
	FGameplayAttributeData Health;
	
	UPROPERTY()
	FGameplayAttributeData Speed;
	
	UPROPERTY()
	FGameplayAttributeData Damage;

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);
	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Speed);
	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Damage);
};
