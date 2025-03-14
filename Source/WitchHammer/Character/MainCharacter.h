// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "WitchHammer/Components/BaseInputComponent.h"
#include "WitchHammer/Components/CustomizationComponent.h"
#include "MainCharacter.generated.h"


UCLASS()
class WITCHHAMMER_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	TMap<ESlotType, USkeletalMeshComponent*> CustomizableMeshes{
		{ESlotType::Head, Head},
		{ESlotType::Body, Body},
		{ESlotType::Back, Back},
		{ESlotType::LeftArm, LeftArm},
		{ESlotType::RightArm, RightArm},
		{ESlotType::Hips, Hips},
		{ESlotType::Legs, Legs},
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* LeftArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* RightArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Back;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Hips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Legs;


	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseInputComponent> CustomInputComponent;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//ComponentGetters
};
