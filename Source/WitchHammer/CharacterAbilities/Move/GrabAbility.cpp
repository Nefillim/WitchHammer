// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabAbility.h"

#include "MovieSceneTracksComponentTypes.h"
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
		if(Character->GrabbedObject)
		{
			const FDetachmentTransformRules Rules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
			Character->GrabbedObject->DetachFromActor(Rules);
			Character->GrabbedObject = nullptr;
		}
		if (USkeletalMeshSocket const* RightHandSocket = Character->GetMesh()->GetSocketByName(SocketName))
		{
			if(auto PC = Cast<APlayerController>(Character->GetController()))
			{
				FHitResult hitResult;
				PC->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true,hitResult);
				if(auto Target = hitResult.GetActor())
				{
					if(Target->GetComponentByClass(UAbilitySystemComponent::StaticClass()))
					{
						const FAttachmentTransformRules Rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
						Target->AttachToActor(Character, Rules, SocketName);
						Character->GrabbedObject = Target;
						if(auto MoveComp = Character->GrabbedObject->GetComponentByClass<UProjectileMovementComponent>())
						{
							MoveComp->Velocity = FVector(0, 0, 0);
						}
					}
				}
			}
		}
	}
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
}
