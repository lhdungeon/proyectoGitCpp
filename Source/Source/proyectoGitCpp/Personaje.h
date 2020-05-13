// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/SpotLightComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"

#include "Personaje.generated.h"



UCLASS()
class PROYECTOGITCPP_API APersonaje : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APersonaje();

	void MoveForward(float Axis);
	void MoveRight(float Axis);
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objects)
	USpotLightComponent* Lantern;
	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	// Variables y Funciones De Personaje

	//Muerto?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
		bool bDead;

	//Infectado?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
		bool bInfected;

	//HambrientoOSediento?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
		bool bHungryThirst;

	//Salud (¿Deberia sentenciarla en GameInstance?)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float Life;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float MaxLife;

	//Hambre
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float Hungry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float MaxHungry;

	//Sed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float Thirst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Parameters")
		float MaxThirst;

	//Timer
	UPROPERTY()
		FTimerHandle UnusedHandle;

	//Apetito y Sed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PJ Drains")
		float HungryThirstDrainRate;

	//Funcion De apetito y sed
	UFUNCTION(BlueprintCallable, Category = "PJ Drains")
		void DrainHungryThirst();

	//EquipaAlgunArma?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		bool bEquip;

	//Seleccion De Objectos (Linterna)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object to use")
		bool bLanternUse;

	//Widget
	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> WidgetHud_Class;
	UUserWidget* Hud;

	
};
