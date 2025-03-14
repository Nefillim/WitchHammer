// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WitchHammer/AbilityObjects/BaseProjectile.h"
#include "SpawnAbility.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API USpawnAbility : public UGameplayAbility
{
	GENERATED_BODY()
	virtual bool K2_CommitAbility() override;
public:
	UPROPERTY()
	TSubclassOf<ABaseProjectile> ProjectileClass;
	
	UFUNCTION()
	void SpawnProjectiles();
};
