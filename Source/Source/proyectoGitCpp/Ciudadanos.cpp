// Fill out your copyright notice in the Description page of Project Settings.


#include "Ciudadanos.h"

// Sets default values
ACiudadanos::ACiudadanos()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACiudadanos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACiudadanos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACiudadanos::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

