// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class WITCHHAMMER_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
public:
	ABaseProjectile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY()
	UProjectileMovementComponent* ProjectileMovementComponent;
};
