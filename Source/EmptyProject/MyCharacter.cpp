#include"MyCharacter.h"
#include"Components/InputComponent.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::MoveForward(float amount) 
{
	
	// Не вводите тело этой функции, если контроллер
	// ещё не установлен или если сумма для движения равна 0
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		// мы вызываем AddMovementInput, чтобы собственно двигать
		// игрока `суммой` в направлениях `fwd`
		AddMovementInput(fwd, amount);
	}

}
void AMyCharacter::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		// мы вызываем AddMovementInput, чтобы собственно двигать
		// игрока `суммой` в направлениях `fwd`
		AddMovementInput(right, amount);
	}
}

void AMyCharacter::Yaw(float amount)
{
	AddControllerYawInput(amount);
}

void AMyCharacter::Pitch(float amount)
{
	AddControllerPitchInput(amount);
}
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent*	PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Yaw", this, &AMyCharacter::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AMyCharacter::Pitch);
}