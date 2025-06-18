// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "WitchHammer/Components/InteractionComponent.h"
#include "WitchHammer/Components/InventoryComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	CustomizationComponent = CreateDefaultSubobject<UCustomizationComponent>(TEXT("CustomizationComponent"));
	//AbilitySystem
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto HealthAttribute = AttributeSet->GetHealthAttribute();
	InteractionSphere->OnComponentBeginOverlap.AddUniqueDynamic(this, &ABaseCharacter::AddInteractableObject);
}

void ABaseCharacter::BindAbility(TSubclassOf<UGameplayAbility> AbilityClass, int InputId)
{
	if(AbilitySystemComponent)
	{
		if(auto OldAbility = AbilitySystemComponent->FindAbilitySpecFromInputID(InputId))
		{
			AbilitySystemComponent->ClearAbility(OldAbility->Handle);
		}
		auto NewAbilitySpec = AbilitySystemComponent->BuildAbilitySpecFromClass(AbilityClass, 0, InputId);
		AbilitySystemComponent->GiveAbility(NewAbilitySpec);
	}
}

void ABaseCharacter::AddInteractableObject(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	if(Actor->FindComponentByClass<UInteractionComponent>())
	{
		InteractionTarget = Actor;
	}
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
