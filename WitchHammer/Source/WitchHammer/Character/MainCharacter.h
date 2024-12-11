// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "WitchHammer/Inventory/Components/InventoryComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class WITCHHAMMER_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY()
	UInventoryComponent* InventoryComponent;

	UPROPERTY()
	UCustomizationComponent* CustomizationComponent;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//ComponentGetters
	UFUNCTION()
	UInventoryComponent* GetInventoryComponent(){return InventoryComponent;}
};
