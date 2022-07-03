// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchMoveEngine.generated.h"

UCLASS()
class CHINESECHEEKGAME_API ASearchMoveEngine : public AActor
{
	GENERATED_BODY()
	
public:	
	ASearchMoveEngine();

public:
	FChessPosition relativePoss[20];//用来存储棋子的相关位置
	int32 relativeChessIndex = 0;	//用来索引relativePos

	void AddRelativePos(int32 inRow, int32 inCol);
	void GetRelativePosPiece(int32 chessBoard[10][9], int32 startX, int32 startY);

	void SetChessRule(class AChessRule* inChessRule);

private:
	class AChessRule* chessRule;
};
