// Copyright Epic Games, Inc. All Rights Reserved.

#include "WitchHammerCharacter.h"

#include "GameplayTagsManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "WitchHammer/CharacterAbilities/Move/GrabAbility.h"
#include "WitchHammer/CharacterAbilities/Spawn/SpawnProjectilesAbility.h"
#include "WitchHammer/Components/BaseInputComponent.h"
#include "WitchHammer/GameBase/GameDataAsset.h"

AWitchHammerCharacter::AWitchHammerCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	PrimaryActorTick.bCanEverTick = true;
	
	InitMeshes();
}

void AWitchHammerCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitTimers();
	InitAbilities();
}

void AWitchHammerCharacter::InitMeshes()
{
	Head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(GetMesh());
	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(GetMesh());
	Back = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Back"));
	Back->SetupAttachment(GetMesh());
	LeftArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftArm"));
	LeftArm->SetupAttachment(GetMesh());
	RightArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightArm"));
	RightArm->SetupAttachment(GetMesh());
	Hips = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hips"));
	Hips->SetupAttachment(GetMesh());
	Legs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	Legs->SetupAttachment(GetMesh());
	
	CustomizableMeshes.Emplace(ESlotType::Head, Head);
	CustomizableMeshes.Emplace(ESlotType::Body, Body);
	CustomizableMeshes.Emplace(ESlotType::Back, Back);
	CustomizableMeshes.Emplace(ESlotType::LeftArm, LeftArm);
	CustomizableMeshes.Emplace(ESlotType::RightArm, RightArm);
	CustomizableMeshes.Emplace(ESlotType::Hips, Hips);
	CustomizableMeshes.Emplace(ESlotType::Legs, Legs);
}

void AWitchHammerCharacter::InitAbilities()
{
	if(AbilitySystemComponent)
	{
		for(auto Tag : AbilityClassByTag)
		{
			InitAbility(Tag.Key);
		}		
	}
}

void AWitchHammerCharacter::InitAbility(FGameplayTag AbilityTag)
{
	if(AbilityClassByTag.Contains(AbilityTag))
	{
		auto BaseAttackSpec = AbilitySystemComponent->BuildAbilitySpecFromClass(AbilityClassByTag[AbilityTag], 0,
				UGameDataAsset::Get(GetWorld())->InputIdByTag(AbilityTag));
		AbilitySystemComponent->GiveAbility(BaseAttackSpec);	
	}
}


void AWitchHammerCharacter::InitTimers()
{
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &AWitchHammerCharacter::SetLookAtRotation);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.05f, true);
	
}

void AWitchHammerCharacter::SetLookAtRotation()
{
	if(auto PC = Cast<APlayerController>(GetController()))
	{
		FHitResult hitResult;
		PC->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true,hitResult);
		FVector hitLoc = hitResult.Location;
		FRotator Rotation = FRotator(GetActorRotation().Pitch,(hitLoc - GetActorLocation()).Rotation().Yaw,GetActorRotation().Roll);
		GetCapsuleComponent()->SetWorldRotation(Rotation);	
	}
}

void AWitchHammerCharacter::ActivateAbility(FGameplayTag InputId)
{
	if(auto AS = GetAbilitySystemComponent())
	{
		if(auto Ability = AS->FindAbilitySpecFromInputID(UGameDataAsset::Get(GetWorld())->InputIdByTag(InputId)))
		{
			AS->TryActivateAbility(Ability->Handle);
		}
	}
}

