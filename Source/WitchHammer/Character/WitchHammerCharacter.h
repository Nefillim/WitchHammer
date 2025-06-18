// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorTransformer.h"
#include "BaseCharacter.h"
#include "WitchHammer/CharacterAbilities/Spawn/SpawnProjectilesAbility.h"
#include "WitchHammerCharacter.generated.h"

class UBaseInputComponent;

UCLASS(Blueprintable)
class AWitchHammerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AWitchHammerCharacter();

	virtual void BeginPlay() override;

	UFUNCTION()
	void InitMeshes();

	UFUNCTION()
	void InitAbilities();
	
	UFUNCTION()
	void InitAbility(FGameplayTag AbilityTag);

	UFUNCTION()
	void InitTimers();

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ESlotType, USkeletalMeshComponent*> CustomizableMeshes;
	//Meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> LeftArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> RightArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Back;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Hips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Legs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector ProjectileSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> AttackAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> JumpAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> GrabAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> TossAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> SelectTargetAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> AbilityClassByTag;
	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseInputComponent> CustomInputComponent;

	//GAS
	UFUNCTION()
	void ActivateAbility(FGameplayTag InputId);
	
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

