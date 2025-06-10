#include "JumpAbility.h"

#include "WitchHammer/Character/WitchHammerCharacter.h"

void UJumpAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void UJumpAbility::CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	if(auto Character = Cast<AWitchHammerCharacter>(ActorInfo->OwnerActor))
	{
		Character->Jump();
	}
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
}
