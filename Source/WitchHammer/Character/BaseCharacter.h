// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "WitchHammer/Components/CustomizationComponent.h"
#include "WitchHammer/Inventory/Components/InventoryComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class WITCHHAMMER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCustomizationComponent> CustomizationComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInventoryComponent> InventoryComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//GAS
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseAttributeSet> AttributeSet;
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Stress
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StressLevel = 0;
	
	//Components getters
	UFUNCTION()
	UAbilitySystemComponent* GetAbilitySystemComponent(){return AbilitySystemComponent;}

	UFUNCTION()
	UCustomizationComponent* GetCustomizationComponent(){return CustomizationComponent;}

	UFUNCTION()
	UInventoryComponent* GetInventoryComponent(){return InventoryComponent;}
	
};
