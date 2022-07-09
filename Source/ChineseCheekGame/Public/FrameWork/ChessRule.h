// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectMacros.h"
#include "ChessRule.generated.h"

//棋子的结构
USTRUCT(BlueprintType)
struct FChessPosition
{
	//行和列的标记
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ChessAttrs")
		int32 row;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ChessAttrs")
		int32 col;
};

//走法的结构体
USTRUCT(BlueprintType)
struct FChessMovePoint
{
	GENERATED_USTRUCT_BODY()
public:
	//起始位置和终点位置
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ChessAttrs")
		FChessPosition from;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ChessAttrs")
		FChessPosition to;
};

UCLASS()
class CHINESECHEEKGAME_API AChessRule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessRule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/*
	黑 : 将1,車2,马3,炮4,象5,士6,卒7
	红 : 帅8,車9,马10,炮11,相12,士13,兵14
	*/

	//默认的 初始的棋盘
	int32 InitChessArray[10][9] = 
	{
		{2,3,5,6,1,6,5,3,2},
		{0,0,0,0,0,0,0,0,0},
		{0,4,0,0,0,0,0,4,0},
		{7,0,7,0,7,0,7,0,7},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{14,0,14,0,14,0,14,0,14},
		{0,11,0,0,0,0,0,11,0},
		{0,0,0,0,0,0,0,0,0},
		{9,10,12,13,8,13,12,10,9}
	};

	//行走中的棋盘
	int32 RunChessArray[10][9];

	void Init();//初始化RunChessArray(运行中的棋盘)

	bool IsRedChess(int32 inValue);//判断是否是红色棋子
	bool IsBlueChess(int32 inValue);//判断是否是黑色棋子

	bool IsRedChess(int32 inRow,int32 inCol);//判断是否是红色棋子
	bool IsBlueChess(int32 inRow, int32 inCol);//判断是否是黑色棋子

	bool IsSameColorChess(int32 inValue1, int32 inValue2);//判断两个棋子是否为相同颜色的棋子
	bool CanTouch(int32 boardPosition[10][9], int32 fromRow, int32 fromCol, int32 toRow, int32 toCol);//不考虑棋盘上其他棋子位置的时候可行走的通用规则
	bool IsValidMove(int32 RunChessArray[10][9], int32 fromRow, int32 fromCol, int32 toRow, int32 toCol);
	bool IsValidMove(int32 fromRow, int32 fromCol, int32 toRow, int32 toCol);//是否为有效走法

	void ChangeRunChessArray(FChessMovePoint movePoint);//改变行走的棋盘

		//获取棋盘中可走位置和可吃子位置的标记
	TArray<int32> GetCanMovePosition(int32 inRow, int32 inCol);

	//判断是否将军
	int32 Checking();
};
