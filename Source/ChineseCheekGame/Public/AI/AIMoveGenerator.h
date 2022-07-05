// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FrameWork/ChessRule.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIMoveGenerator.generated.h"

UCLASS()
class CHINESECHEEKGAME_API AAIMoveGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AAIMoveGenerator();

private:
	class AChessRule* chessRule;//把规则类引入

public:
	void SetAIRule(class AChessRule* inRule);
	FChessMovePoint validMoveList[8][90];//存放黑方所有棋子合法落子的队列
	int32 validMoveCount = 0;//用来存放合法队列的个数
	void AddValidMove(int32 chessIndex, int32 inFromRow, int32 inFromCol, int32 inToRow, int32 inToCol);
	int32 ValidMovePoints(int32 chessBoard[10][9], int32 chessIndex, int32 isRedSide);//遍历相应棋子在棋盘上面所有的合法走法

	void Gen_KingMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成将或者帅的合法走法(寻找合理的落子点),并插入到validMoveList队列中
	void Gen_JuMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成車的合法走法
	void Gen_MaMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成马的合法走法
	void Gen_PaoMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成炮的合法走法
	void Gen_XiangMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成象的合法走法
	void Gen_BShiMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成黑士的合法走法
	void Gen_RShiMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成红士的合法走法
	void Gen_ZuMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成卒的合法走法
	void Gen_BingMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex);//生成兵的合法走法

};
