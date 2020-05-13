// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"

#include "Runtime/Engine/Public/TimerManager.h"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Seteo de variables
	bDead = false;
	
	Life = 100.f;
	MaxLife = 100.f;
	Hungry = 100.f;
	MaxHungry = 100.f;
	Thirst = 100.f;
	MaxThirst = 100.f;
	bHungryThirst = false;
	HungryThirstDrainRate = 2.0f;
	
	bLanternUse = false;

	//Seteo De componentes
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	Lantern = CreateDefaultSubobject<USpotLightComponent>(TEXT("Lantern"));
	Lantern->SetupAttachment(RootComponent);
	Lantern->SetVisibility(false);
	Lantern->SetIntensity(10000.0f);

}

// Called when the game starts or when spawned
void APersonaje::BeginPlay()
{
	Super::BeginPlay();

	//Timer De Hambre y Sed
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &APersonaje::DrainHungryThirst, HungryThirstDrainRate, true, 1.f);


	//Se Agrega el widget hud a la pantalla
	if (WidgetHud_Class != nullptr)
	{
		Hud = CreateWidget(GetWorld(), WidgetHud_Class);
		Hud->AddToViewport();
	}

}

// Called every frame
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &APersonaje::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APersonaje::MoveRight);

}

//Movimiento Adelante/Atras
void APersonaje::MoveForward(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}

//Movimiento Derecha / Izquierda
void APersonaje::MoveRight(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

//Funcion de apetito y sed
void APersonaje::DrainHungryThirst()
{

	Hungry = Hungry - 0.3f;
	Thirst = Thirst - 0.5f;

	if (Hungry <= 0 || Thirst <= 0)
	{

		bHungryThirst = true;

	}
}
