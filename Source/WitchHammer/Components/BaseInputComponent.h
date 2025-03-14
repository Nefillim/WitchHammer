// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "BaseInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WITCHHAMMER_API UBaseInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseInputComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
