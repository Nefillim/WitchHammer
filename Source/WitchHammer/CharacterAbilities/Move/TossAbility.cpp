// Fill out your copyright notice in the Description page of Project Settings.


#include "TossAbility.h"

#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/NavMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "WitchHammer/Character/WitchHammerCharacter.h"

void UTossAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void UTossAbility::CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	if(auto Character = Cast<AWitchHammerCharacter>(ActorInfo->OwnerActor))
	{
		if(Character->GrabbedObject)
		{
			const FDetachmentTransformRules Rules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
			Character->GrabbedObject->DetachFromActor(Rules);
			if(auto MoveComp = Character->GrabbedObject->GetComponentByClass<UPawnMovementComponent>())
			{
				MoveComp->AddInputVector(Character->GetActorRotation().Vector() * 2, true);
			}
			if(auto MoveComp = Character->GrabbedObject->GetComponentByClass<UProjectileMovementComponent>())
			{
				MoveComp->MaxSpeed = 2000;
				MoveComp->Velocity = Character->GetActorRotation().GetNormalized().Vector() * 500;
			}
			Character->GrabbedObject = nullptr;
		}
	}
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
}
