// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChessMainUI.generated.h"

/**
 * 
 */
UCLASS()
class CHINESECHEEKGAME_API UChessMainUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void AddToScreenInfo(FString instring, int32 inType);
	TArray<UDebugTextUI*> infoItemsList;
	UFUNCTION(BlueprintImplementableEvent)
		class UDebugTextUI* AddInfo(const FString& inString, int32 inNifoType);//添加日志输出
};
