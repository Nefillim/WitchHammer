// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnAbility.h"
#include "SpawnProjectilesAbility.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API USpawnProjectilesAbility : public USpawnAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ABaseProjectile> SpawnProjectileClass;
};
