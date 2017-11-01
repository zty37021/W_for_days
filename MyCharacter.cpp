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
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	check(InputComponent);
	InputComponent -> BindAxis("Forward", this, &AMyCharacter::MoveForward);
	InputComponent -> BindAxis("Back", this, &AMyCharacter::MoveBack);
	InputComponent -> BindAxis("Left", this, &AMyCharacter::MoveLeft);
	InputComponent -> BindAxis("Right", this, &AMyCharacter::MoveRight);
	//普通方式，需要创建方法，调用基类的接口来获取鼠标位移值

	//InputComponent -> BindAxis("Yaw", this, &AMyCharacter::Yaw);
	//InputComponent -> BindAxis("Pitch", this, &AMyCharacter::Pitch);


	//取巧，直接调用APawn中的方法
	InputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

};

void AMyCharacter::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AMyCharacter::MoveBack(float amount)
{
	if (Controller && amount)
	{
		FVector back = -GetActorForwardVector();
		AddMovementInput(back, amount);
	}
}

void AMyCharacter::MoveLeft(float amount)
{
	if (Controller && amount)
	{
		FVector left = -GetActorRightVector();
		AddMovementInput(left, amount);
	}
}

void AMyCharacter::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

//void AMyCharacter::Yaw(float amount)
//{
//	if (Controller && amount)
//	{
//		AddControllerYawInput(50.f * amount * GetWorld()->GetDeltaSeconds());
//	}
//}
//
//void AMyCharacter::Pitch(float amount)
//{
//	if (Controller && amount)
//	{
//		AddControllerPitchInput(-50.f * amount * GetWorld()->GetDeltaSeconds());
//	}
//}
