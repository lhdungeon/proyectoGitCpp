// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"

#include "Items.generated.h"



UCLASS()
class PROYECTOGITCPP_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SphereCollision;

	UPROPERTY()
		USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propertys")
		bool bIsFood;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propertys")
		bool bIsLiquid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propertys")
		bool bIsOtherItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propertys")
		float FoodValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propertys")
		float LiquidValue;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};


