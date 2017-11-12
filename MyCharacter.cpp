// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AMyCharacter::MoveLeft);
	PlayerInputComponent->BindAxis("MoveJump", this, &AMyCharacter::MoveJump);
	PlayerInputComponent->BindAxis("Mouse_x", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Mouse_y", this, &APawn::AddControllerPitchInput);
}

//实现玩家控制
void AMyCharacter::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector MoveForward = GetActorForwardVector();
		AddMovementInput(MoveForward, amount);
	}
}

void AMyCharacter::MoveLeft(float amount)
{
	if (Controller && amount)
	{
		FVector MoveLeft = -GetActorRightVector();
		AddMovementInput(MoveLeft, amount);
	}
}

void AMyCharacter::MoveJump(float amount)
{
	if (Controller && amount)
	{
		FVector MoveJump = GetActorUpVector();
		AddMovementInput(MoveJump, amount);
	}
}
