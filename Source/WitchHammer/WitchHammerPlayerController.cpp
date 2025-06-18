// Copyright Epic Games, Inc. All Rights Reserved.

#include "WitchHammerPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Character/WitchHammerCharacter.h"
#include "Components/InteractionComponent.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AWitchHammerPlayerController::AWitchHammerPlayerController(): ShortPressThreshold(0), FXCursor(nullptr),
                                                              DefaultMappingContext(nullptr),
                                                              MoveUpAction(nullptr),
                                                              MoveDownAction(nullptr),
                                                              MoveLeftAction(nullptr),
                                                              MoveRightAction(nullptr),
                                                              JumpAction(nullptr),
                                                              bMoveToMouseCursor(0),
                                                              bIsTouch(false)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AWitchHammerPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AWitchHammerPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::MoveForward);
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::MoveBack);
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::MoveLeft);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::MoveRight);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::MoveUp);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AWitchHammerPlayerController::Interact);
		
		EnhancedInputComponent->BindAction(BaseAttackAction, ETriggerEvent::Ongoing, this, &AWitchHammerPlayerController::BaseAttack);
		
		EnhancedInputComponent->BindAction(SpecialAction, ETriggerEvent::Started, this, &AWitchHammerPlayerController::SpecialAttack);
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &AWitchHammerPlayerController::Grab);
		EnhancedInputComponent->BindAction(TossAction, ETriggerEvent::Started, this, &AWitchHammerPlayerController::Toss);
		EnhancedInputComponent->BindAction(MoveBoostAction, ETriggerEvent::Started, this, &AWitchHammerPlayerController::MoveBoost);
		EnhancedInputComponent->BindAction(CoreAction, ETriggerEvent::Started, this, &AWitchHammerPlayerController::UseCoreAbility);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AWitchHammerPlayerController::Move(FVector Direction)
{
	if (auto ControlledPawn = Cast<ACharacter>(GetPawn()))
	{
		ControlledPawn->AddMovementInput(Direction, 1.0, false);
	}
}

void AWitchHammerPlayerController::MoveForward()
{
	Move(FVector::ForwardVector);
}

void AWitchHammerPlayerController::MoveBack()
{
	Move(FVector::BackwardVector);
}

void AWitchHammerPlayerController::MoveLeft()
{
	Move(FVector::LeftVector);
}

void AWitchHammerPlayerController::MoveRight()
{
	Move(FVector::RightVector);
}

void AWitchHammerPlayerController::MoveUp()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.Jump")));
}

void AWitchHammerPlayerController::BaseAttack()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.BaseAttack")));
}

void AWitchHammerPlayerController::SpecialAttack()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.SpecialAction")));
}

void AWitchHammerPlayerController::Grab()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.Grab")));
}

void AWitchHammerPlayerController::Toss()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.Toss")));
}

void AWitchHammerPlayerController::MoveBoost()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.OnMove")));
}

void AWitchHammerPlayerController::UseCoreAbility()
{
	UseAbilityByType(UGameplayTagsManager::Get().RequestGameplayTag(FName("AbilityType.Core")));
}

void AWitchHammerPlayerController::UseAbilityByType(FGameplayTag InputId)
{
	if(auto ControlledPawn = Cast<AWitchHammerCharacter>(GetPawn()))
	{
		ControlledPawn->ActivateAbility(InputId);
	}
}

void AWitchHammerPlayerController::Interact()
{
	if(auto ControlledPawn = Cast<AWitchHammerCharacter>(GetPawn()))
	{
		if(auto Target = ControlledPawn->InteractionTarget)
		{
			if(auto InteractionComp = Target->FindComponentByClass<UInteractionComponent>())
			{
				InteractionComp->OnStartInteraction.Execute(ControlledPawn);
			}
		}
	}
}

/*
// Triggered every frame when the input is held down
void AWitchHammerPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AWitchHammerPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AWitchHammerPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AWitchHammerPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}*/
