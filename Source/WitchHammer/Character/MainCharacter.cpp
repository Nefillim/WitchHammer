// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(GetMesh());
	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(GetMesh());
	Back = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Back"));
	Back->SetupAttachment(GetMesh());
	LeftArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftArm"));
	LeftArm->SetupAttachment(GetMesh());
	RightArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightArm"));
	RightArm->SetupAttachment(GetMesh());
	Hips = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hips"));
	Hips->SetupAttachment(GetMesh());
	Legs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	Legs->SetupAttachment(GetMesh());

	//Inputs
	CustomInputComponent = CreateDefaultSubobject<UBaseInputComponent>(TEXT("InputComponent"));

	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

