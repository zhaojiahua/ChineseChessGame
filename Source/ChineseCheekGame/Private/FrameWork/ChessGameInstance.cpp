// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameWork/ChessGameInstance.h"

void UChessGameInstance::SetCurrentSearchDepth(int32 inDepth)
{
	currentSearchDepth = inDepth;
}

int32 UChessGameInstance::GetCurrentSearchDepth()
{
	return currentSearchDepth;
}
