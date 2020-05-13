// Fill out your copyright notice in the Description page of Project Settings.


#include "Items.h"

#include "Personaje.h"


// Sets default values
AItems::AItems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));

	RootComponent = SceneRoot;

	StaticMesh->SetupAttachment(RootComponent);

	SphereCollision->SetupAttachment(StaticMesh);
	SphereCollision->SetSphereRadius (100.f);
	SphereCollision->bHiddenInGame = false;
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AItems::OnOverlapBegin);

	bIsFood = false;
	bIsLiquid = false;
	bIsOtherItem = false;

}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//Overlap Con item (añadir funcion de habilitar valores float al habilitar valores bool)/(Clampear Valores de hambre y sed al setear)
void AItems::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	APersonaje* Character = Cast<APersonaje>(OtherActor);
	if (bIsFood == true || bIsLiquid == false)
	{
		Character->Hungry += FoodValue;
	}

	else if (bIsLiquid == true || bIsFood == false)
	{
		Character->Thirst += LiquidValue;
	}

	else if (bIsFood == true || bIsLiquid == true)
	{
		Character->Hungry += FoodValue;
		Character->Thirst += LiquidValue;
	}

	Destroy();
}



/*switch (Type)
		{
		case 1: Character->Hungry <- Character->Hungry - 20.f ? Character->Hungry += 10.f : Character->MaxHungry;
			break;

		case 2: Character->Thirst <- Character->Thirst - 20.f ? Character->Thirst += 20.f : Character->MaxThirst;
			break;

		case 3:  Character->Hungry < -Character->Hungry - 20.f ? Character->Hungry += 10.f : Character->MaxHungry;
			Character->Thirst < -Character->Thirst - 20.f ? Character->Thirst += 20.f : Character->MaxThirst;
			break;

		default:
			break;
		}*/