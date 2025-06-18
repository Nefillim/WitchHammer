// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "Components/SphereComponent.h"
#include "WitchHammer/Components/CustomizationComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class WITCHHAMMER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY()
	TObjectPtr<AActor> GrabbedObject;

	UFUNCTION()
	void BindAbility(TSubclassOf<UGameplayAbility> AbilityClass, int InputId);
	
	UPROPERTY()
	TObjectPtr<AActor> InteractionTarget;
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

	//Interaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USphereComponent> InteractionSphere;

	UFUNCTION()
	void AddInteractableObject(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
							   UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
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
