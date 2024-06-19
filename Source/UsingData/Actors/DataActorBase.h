// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Data/Datalibrary.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintreadWrite, Category="Components")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintreadWrite, Category="Components")
	USphereComponent* SphereCollider; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	EItemType ItemType = EItemType::None;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item Info")
	FGenericItemInfo GenericItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	bool bRunCPP = false;

	UPROPERTY(BlueprintReadWrite)
	UCurveFloat* mFloatCurve = nullptr;

	UPROPERTY(BlueprintReadWrite)
	float mRotationDuration = 0.f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float mCurrentRotation = 0.f;
};
