// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabAbility.h"

#include "Engine/SkeletalMeshSocket.h"
#include "WitchHammer/Character/WitchHammerCharacter.h"

void UGrabAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void UGrabAbility::CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                 const FGameplayAbilityActivationInfo ActivationInfo)
{
	if(auto Character = Cast<AWitchHammerCharacter>(ActorInfo->OwnerActor))
	{
		if (USkeletalMeshSocket const* RightHandSocket = Character->GetMesh()->GetSocketByName(SocketName))
		{
			
		}
	}
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
}
