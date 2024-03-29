#include "SkateboardGuy.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ASkateboardGuy::ASkateboardGuy() :
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f)
{
 	
	PrimaryActorTick.bCanEverTick = true;

	// SpringArmComponent
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true; // rotate the springarm based on the controller

	// Camera Component
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // attaching to the end of the springarm
	FollowCamera->bUsePawnControlRotation = false;

	// StaticMeshComponents
	Skate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Skate"));
	Skate->SetupAttachment(RootComponent);
	Patienta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Patienta"));
	Patienta->SetupAttachment(Skate);
	Patienta1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Patienta1"));
	Patienta1->SetupAttachment(Skate);
	Rueda0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rueda0"));
	Rueda0->SetupAttachment(Patienta);
	Rueda1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rueda1"));
	Rueda1->SetupAttachment(Patienta);
	Rueda2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rueda2"));
	Rueda2->SetupAttachment(Patienta1);
	Rueda3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rueda3"));
	Rueda3->SetupAttachment(Patienta1);
}


void ASkateboardGuy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASkateboardGuy::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		// forward
		const FRotator Rotation{ Controller->GetControlRotation() };
		const FRotator YawRotation{ 0, Rotation.Yaw, 0 };

		const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::X) };
		AddMovementInput(Direction, Value);
	}
}

void ASkateboardGuy::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		// right
		const FRotator Rotation{ Controller->GetControlRotation() };
		const FRotator YawRotation{ 0, Rotation.Yaw, 0 };

		const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::Y) };
		AddMovementInput(Direction, Value);
	}
}

void ASkateboardGuy::TurnAtRate(float Rate)
{
	// calculate delta from the rate
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASkateboardGuy::LookUpAtRate(float Rate)
{
	// calculate delta from the rate
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


void ASkateboardGuy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASkateboardGuy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASkateboardGuy::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASkateboardGuy::MoveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASkateboardGuy::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASkateboardGuy::LookUpAtRate);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

