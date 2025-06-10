

#pragma once

#include "CoreMinimal.h"
#include "MoveAbility.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/MovementComponent.h"
#include "JumpAbility.generated.h"

/**
 * 
 */
UCLASS()
class WITCHHAMMER_API UJumpAbility : public UMoveAbility
{
	GENERATED_BODY()

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	virtual void CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;

};
