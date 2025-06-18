// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WitchHammer/Components/InteractionComponent.h"
#include "WitchHammer/Inventory/Items/Item.h"
#include "CustomizationSource.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API ACustomizationSource : public AActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	ACustomizationSource();
	
	UFUNCTION()
	UInteractionComponent* GetInteractionComponent()
	{
		return InteractionComponent;
	};
private:
	UPROPERTY()
	TObjectPtr<UInteractionComponent> InteractionComponent;

	UPROPERTY(EditAnywhere)
	FString ItemId;

	UFUNCTION()
	void OnInteract(ABaseCharacter* Source);
	
};
