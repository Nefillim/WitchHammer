// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnProjectilesAbility.h"

#include "Kismet/GameplayStatics.h"
#include "WitchHammer/Character/WitchHammerCharacter.h"

void USpawnProjectilesAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void USpawnProjectilesAbility::CommitExecute(const FGameplayAbilitySpecHandle Handle,
                                             const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	if(auto Character = Cast<AWitchHammerCharacter>(ActorInfo->OwnerActor))
	{
		FVector SpawnLocation = Character->GetActorLocation() + Character->ProjectileSpawnLocation;
		ABaseProjectile* Projectile = GetWorld()->SpawnActor<ABaseProjectile>(SpawnProjectileClass, SpawnLocation,	Character->GetActorRotation());
		FRepMovement Movement;
		Movement.LinearVelocity = FVector::ForwardVector * 10;
		Projectile->SetReplicatedMovement(Movement);
	}
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
}