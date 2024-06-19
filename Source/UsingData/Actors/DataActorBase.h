// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataActorBase.generated.h"

class USphereComponent;

UCLASS()
class USINGDATA_API ADataActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintreadWrite, Category="Category")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintreadWrite, Category="Category")
	USphereComponent* SphereCollider; 
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
