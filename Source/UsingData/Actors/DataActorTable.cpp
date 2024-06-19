// Fill out your copyright notice in the Description page of Project Settings.


#include "DataActorTable.h"

#if WITH_EDITOR
void ADataActorTable::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!bRunCPP || ItemType == EItemType::None) { return; }

	if (ItemDataTable)
	{
		const FName RowName = FName(UEnum::GetDisplayValueAsText(ItemType).ToString());  // Get row name as string from Enum
		FItemInformationTable* Row = ItemDataTable->FindRow<FItemInformationTable>(RowName, "Item Details");

		if (Row)
		{
			GenericItemInfo.ItemType = Row->ItemType;
			GenericItemInfo.ItemName = Row->ItemName;
			GenericItemInfo.ItemInfo = Row->ItemInfo;
			GenericItemInfo.ItemImage = Row->ItemImage;
			GenericItemInfo.Mesh = Row->Mesh;
			GenericItemInfo.ItemCost = Row->ItemCost;
			GenericItemInfo.CurveFloat = Row->CurveFloat;
			GenericItemInfo.RotationDuration = Row->RotationDuration;

			Mesh->SetStaticMesh(GenericItemInfo.Mesh);

			if (GenericItemInfo.CurveFloat)
			{
				mFloatCurve = GenericItemInfo.CurveFloat;
				mRotationDuration = GenericItemInfo.RotationDuration;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Item type is valid but a data table has not been set."));
	}
}
#endif