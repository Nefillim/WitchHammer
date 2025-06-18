// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WitchHammer/Character/BaseCharacter.h"
#include "InteractionComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInteractionsStateChange, ABaseCharacter*, Interacting);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WITCHHAMMER_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionComponent();

	//Add client logic and signals to server to start server logic
	//Will be invoked on client by Inputs
	FOnInteractionsStateChange OnStartInteraction;

	//Add client logic and signals to server to start server logic
	//Will be invoked on client in the end of interaction and on interruption
	FOnInteractionsStateChange OnStopInteraction;
protected:
	virtual void BeginPlay() override;
};
