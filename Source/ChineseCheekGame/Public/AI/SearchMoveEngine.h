// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FrameWork/ChessRule.h"
#include "SearchMoveEngine.generated.h"

UCLASS()
class CHINESECHEEKGAME_API ASearchMoveEngine : public AActor
{
	GENERATED_BODY()
	
public:	
	ASearchMoveEngine();

public:
	UPROPERTY(EditAnywhere,Category="SearchAttrs")
	int32 searchDepth = 1;//搜索的深度同时也是游戏难度(要从UI界面上获取值)
	int32 maxSearchDepth;

	FChessMovePoint cBestMove;//最佳走法	
	FChessPosition relativePoss[20];//用来存储棋子的相关位置
	int32 relativeChessIndex = 0;	//用来索引relativePos

	int32 attackPoss[10][9];//记录棋子的威胁信息
	int32 guardPoss[10][9];//记录棋子保护的信息
	int32 flexiblePoss[10][9];//记录棋子的灵活性能
	int32 mainValue[10][9];//记录棋子的总价值

/*
黑 : 将1,車2,马3,炮4,象5,士6,卒7
红 : 帅8,車9,马10,炮11,相12,士13,兵14
*/
	//存储棋子的基础灵活度(描述不同棋子本身的属性)
	int32 baseFlexible[15]{ 0,0,6,12,6,1,1,15,0,6,12,6,1,1,15 };
	//存储棋子的基础价值(用来突出不同棋子的重要程度)
	/*开局情况下,如果给車的战斗力为100分的话,炮的战斗力可给到50,马的战斗力稍微逊色一点可给到45,象的重要性给到23,士的重要性给到21,兵的重要性给到10,
	战到后期的残局情况下,車的战斗力仍然是100,炮应该削减到45,马应该提升至50,象的重要性也应该稍有削减可给到21,士的重要性则应该增加至23,过河兵的重要性
	可增加至25,如果过河兵到达了底线则应该再削减至10分*/
	int32 baseMainValue[15]{ 0,10000,100,45,50,23,21,10,10000,100,45,50,23,21,10 };

	int32 AIChessBoard[10][9];//动态AI棋盘,用来演算用的
	
	//卒和兵在不同的位置会有不同的附加价值
	int32 zuValueScale[10][9] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{5, 6, 7, 8, 8, 8, 7, 6, 5},
	{7, 8, 9, 10, 10, 10, 9, 8, 7},
	{9, 10, 11, 12, 12, 12, 11, 10, 9},
	{9, 10, 11, 12, 12, 12, 11, 10, 9},
	{0, 0, 2, 1, 1, 1, 2, 0, 0}
	};
	int32 bingValueScale[10][9] = {
	{0, 0, 2, 1, 1, 1, 2, 0, 0},
	{9, 10, 11, 12, 12, 12, 11, 10, 9},
	{9, 10, 11, 12, 12, 12, 11, 10, 9},
	{7, 8, 9, 10, 10, 10, 9, 8, 7},
	{5, 6, 7, 8, 8, 8, 7, 6, 5},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	void Init(class AChessRule* inRule, class AAIMoveGenerator* inMoveGen);//初始化函数供playerController调用

	void AddRelativePos(int32 inRow, int32 inCol);
	void GetRelativePosPiece(int32 chessBoard[10][9], int32 startX, int32 startY);
	int32 ChessEveluate(int32 chessBoard[10][9], bool isRedActive);
	int32 GetBingAddedValue(int32 chessBoard[10][9], int32 x, int32 y); //获取兵的附加值
	int32 IsGameOver(int32 chessBoard[10][9], int32 inSearchDepth);

	int32 HypoMove(FChessMovePoint inChessMove);//假象改变AI棋盘
	void UndoHypoMove(FChessMovePoint inChessMove, int32 inChessID);//恢复改变的AI棋盘

	int32 NegativeMax(int32 inDepth);//负极大值搜索函数

	void SetChessRule(class AChessRule* inChessRule);
	void SetGeneratorMove(class AAIMoveGenerator* inMove);

	FChessMovePoint AIMove();//把最佳走法返回出去

private:
	class AChessRule* chessRule;
	class AAIMoveGenerator* cMove;//合法走法类
	
};
