// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataLibrary.generated.h"


UENUM()
enum class EItemType : uint8
{
	None UMETA(DisplayName = "None"),
	Radio UMETA(DisplayName = "Radio"),
	Trophy UMETA(DisplayName = "Trophy"),
	Spaceship UMETA(DisplayName = "Spaceship"),
};

USTRUCT(BlueprintType)
struct FGenericItemInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	EItemType ItemType;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemCost;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemInfo;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UCurveFloat *CurveFloat;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	float RotationDuration = 5;
};

USTRUCT(BlueprintType)
struct FItemInformationTable : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	EItemType ItemType;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemCost;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	FString ItemInfo;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	UCurveFloat *CurveFloat;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category="Item Info")
	float RotationDuration = 5;
};

UCLASS()
class USINGDATA_API UDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
