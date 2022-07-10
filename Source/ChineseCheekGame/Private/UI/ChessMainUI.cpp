// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ChessMainUI.h"
#include "UI/DebugTextUI.h"

void UChessMainUI::AddToScreenInfo(FString instring, int32 inType)
{
	infoItemsList.Add(AddInfo(instring, inType));
}

void UChessMainUI::ClearScreenInfo()
{
	for (int32 i = 0; i < infoItemsList.Num(); i++)
	{
		infoItemsList[i]->RemoveFromParent();
	}
	infoItemsList.Reset(0);
}
