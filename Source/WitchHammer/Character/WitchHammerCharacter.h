// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorTransformer.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "WitchHammer/CharacterAbilities/Spawn/SpawnProjectilesAbility.h"
#include "WitchHammerCharacter.generated.h"

class UBaseInputComponent;

UCLASS(Blueprintable)
class AWitchHammerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	TMap<ESlotType, USkeletalMeshComponent*> CustomizableMeshes{
			{ESlotType::Head, Head},
			{ESlotType::Body, Body},
			{ESlotType::Back, Back},
			{ESlotType::LeftArm, LeftArm},
			{ESlotType::RightArm, RightArm},
			{ESlotType::Hips, Hips},
			{ESlotType::Legs, Legs},
		};
	
	AWitchHammerCharacter();

	virtual void BeginPlay() override;

	UFUNCTION()
	void InitMeshes();

	UFUNCTION()
	void InitAbilities();

	UFUNCTION()
	void InitTimers();

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector ProjectileSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> AttackAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> SelectTargetAbilityClass;

	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseInputComponent> CustomInputComponent;

	UFUNCTION()
	void BaseAttack();

	UFUNCTION()
	void ActivateAbility(int InputId);
private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UFUNCTION()
	void SetLookAtRotation();

};

