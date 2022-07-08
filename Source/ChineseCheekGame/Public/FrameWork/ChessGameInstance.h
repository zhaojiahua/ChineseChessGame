// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ChessGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHINESECHEEKGAME_API UChessGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	int32 currentSearchDepth = 1;

	UFUNCTION(BlueprintCallable,Category="zjhAddFuns")
	void SetCurrentSearchDepth(int32 inDepth);
	int32 GetCurrentSearchDepth();
};
