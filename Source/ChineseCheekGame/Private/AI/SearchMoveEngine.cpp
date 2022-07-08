// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SearchMoveEngine.h"
#include "Chess/ChessBoard.h"
#include "Kismet/KismetMathLibrary.h"
#include "AI/AIMoveGenerator.h"

// Sets default values
ASearchMoveEngine::ASearchMoveEngine()
{
}

void ASearchMoveEngine::Init(class AChessRule* inRule, class AAIMoveGenerator* inMoveGen,int32 inDepth)
{
	SetGeneratorMove(inMoveGen);
	SetChessRule(inRule);
	SetSearchDepth(inDepth);
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Silver, "current depth "+FString::FromInt(inDepth));
}

void ASearchMoveEngine::AddRelativePos(int32 inRow, int32 inCol)
{
	relativePoss[relativeChessIndex].row = inRow;
	relativePoss[relativeChessIndex].col = inCol;
	relativeChessIndex++;
}

void ASearchMoveEngine::GetRelativePosPiece(int32 chessBoard[10][9], int32 startX, int32 startY)
{
	relativeChessIndex = 0;//重置
	int32 x = 0, y = 0, nchessID = chessBoard[startX][startY];
	bool flag = false;

	switch (nchessID)
	{
	case 1://黑将
	case 8://红帅
		x = 0, y = 0;
		for (x=0;x<3;x++)
		{
			for (y = 3; y < 6; y++)
				if (chessRule->CanTouch(chessBoard, startX, startY, x, y)) AddRelativePos(x, y);
		}
		for (x = 7; x < 10; x++)
		{
			for (y = 3; y < 6; y++)
				if (chessRule->CanTouch(chessBoard, startX, startY, x, y)) AddRelativePos(x, y);
		}
		break;
	case 2://黑車
	case 9://红車
		x = 0, y = 0, nchessID = chessBoard[startX][startY];
		x = startX + 1; y = startY;//向下遍历
		while (x < 10 )
		{
			if (chessBoard[x][y] == 0) AddRelativePos(x, y);
			else
			{
				AddRelativePos(x, y);
				break;
			}
			x++;
		}
		x = startX - 1; y = startY;//向上遍历
		while (x >= 0)
		{
			if (chessBoard[x][y] == 0) AddRelativePos(x, y);
			else
			{
				AddRelativePos(x, y);
				break;
			}
			x--;
		}
		x = startX; y = startY + 1;//向左遍历
		while (y < 9 )
		{
			if (chessBoard[x][y] == 0) AddRelativePos(x, y);
			else
			{
				AddRelativePos(x, y);
				break;
			}
			y++;
		}
		x = startX; y = startY - 1;//向右遍历
		while (y >= 0)
		{
			if (chessBoard[x][y] == 0) AddRelativePos(x, y);
			else
			{
				AddRelativePos(x, y);
				break;
			}
			y--;
		}
		break;
	case 3://黑马
	case 10://红马
		x = 0, y = 0;
		//八个方向分别遍历
		x = startX + 1; y = startY + 2;
		if (x < 10 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX + 1; y = startY - 2;
		if (x < 10 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 1; y = startY + 2;
		if (x >= 0 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 1; y = startY - 2;
		if (x >= 0 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX + 2; y = startY + 1;
		if (x < 10 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX + 2; y = startY - 1;
		if (x < 10 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 2; y = startY + 1;
		if (x >= 0 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 2; y = startY - 1;
		if (x >= 0 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		break;
	case 4://黑炮
	case 11://红炮
		x = 0, y = 0, nchessID = chessBoard[startX][startY];
		x = startX + 1; y = startY;//向下遍历
		flag = false;
		while (x < 10)
		{
			if (chessBoard[x][y] == 0)
			{
				if (!flag)AddRelativePos(x, y);
			}
			else
			{
				if (flag == false)flag = true;
				else
				{
					AddRelativePos(x, y);
					break;
				}
			}
			x++;
		}
		x = startX - 1; y = startY;//向上遍历
		flag = false;
		while (x >= 0)
		{
			if (chessBoard[x][y] == 0)
			{
				if (!flag)AddRelativePos(x, y);
			}
			else
			{
				if (flag == false)flag = true;
				else
				{
					AddRelativePos(x, y);
					break;
				}
			}
			x--;
		}
		x = startX; y = startY + 1;//向左遍历
		flag = false;
		while (y < 9 )
		{
			if (chessBoard[x][y] == 0)
			{
				if (!flag)AddRelativePos(x, y);
			}
			else
			{
				if (flag == false)flag = true;
				else
				{
					AddRelativePos(x, y);
					break;
				}
			}
			y++;
		}
		x = startX; y = startY - 1;//向右遍历
		flag = false;
		while (y >= 0)
		{
			if (chessBoard[x][y] == 0)
			{
				if (!flag)AddRelativePos(x, y);
			}
			else
			{
				if (flag == false)	flag = true;
				else
				{
					AddRelativePos(x, y);
					break;
				}
			}
			y--;
		}
		break;
	case 5://黑象
	case 12://红相
		x = 0, y = 0;
		//四个方向分别遍历
		x = startX + 2; y = startY + 2;
		if (x < 10 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX + 2; y = startY - 2;
		if (x < 10 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 2; y = startY + 2;
		if (x >= 0 && y < 9 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 2; y = startY - 2;
		if (x >= 0 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		break;
	case 6://黑士
		x = 0, y = 0;
		for (x = 0; x < 3; x++)
		{
			for (y = 3; y < 6; y++)
				if (chessRule->CanTouch(chessBoard, startX, startY, x, y)) AddRelativePos(x, y);
		}
		break;
	case 7://黑卒
		x = 0, y = 0, nchessID = chessBoard[startX][startY];
		x = startX + 1; y = startY;
		if (x < 10 ) AddRelativePos(x, y);
		//小兵过河的情况还要遍历左右
		if (x > 4)
		{
			x = startX; y = startY + 1;//向左遍历
			if (y < 9) AddRelativePos(x, y);
			x = startX; y = startY - 1;//向右遍历
			if (y >= 0) AddRelativePos(x, y);
		}
		break;
	case 13://红士
		x = 0, y = 0;
		for (x = 7; x < 10; x++)
		{
			for (y = 3; y < 6; y++)
				if (chessRule->CanTouch(chessBoard, startX, startY, x, y)) AddRelativePos(x, y);
		}
		break;
	case 14://红兵
		x = 0, y = 0, nchessID = chessBoard[startX][startY];
		x = startX + 1; y = startY;
		if (x > 0) AddRelativePos(x, y);
		//小兵过河的情况还要遍历左右
		if (x < 5)
		{
			x = startX; y = startY + 1;//向左遍历
			if (y < 9) AddRelativePos(x, y);
			x = startX; y = startY - 1;//向右遍历
			if (y >= 0) AddRelativePos(x, y);
		}
		break;
	default:
		break;
	}

}

int32 ASearchMoveEngine::ChessEveluate(int32 chessBoard[10][9], bool isRedActive)
{
	//首先对这些属性进行初始化
	int32 i = 0, j = 0, k = 0, nChessID, targetChessID;
	for (i=0;i<10;i++)
	{
		for (j = 0; j < 9; j++)
		{
			attackPoss[i][j] = 0;
			guardPoss[i][j] = 0;
			flexiblePoss[i][j] = 0;
			mainValue[i][j] = 0;
		}
	}
	//列举棋子相关的位置
	for (i=0;i<10;i++)
	{
		for (j=0;j<9;j++)
		{
			//如果该点上有棋子,那把该棋子所有相关的位置点都存储到relativePoss数组里面
			if (chessBoard[i][j])
			{
				nChessID = chessBoard[i][j];
				GetRelativePosPiece(chessBoard, i, j);
				for (k=0;k< relativeChessIndex;k++)
				{
					targetChessID = chessBoard[relativePoss[k].row][relativePoss[k].col];
					if (targetChessID == 0) flexiblePoss[i][j]++;
					else
					{
						if (chessRule->IsSameColorChess(nChessID, targetChessID)) guardPoss[relativePoss[k].row][relativePoss[k].col]++;//如果是己方棋子则该棋子的保护价值增1
						else
						{
							attackPoss[relativePoss[k].row][relativePoss[k].col]++;//如果是对方的棋子则该棋子的威胁价值增1
							flexiblePoss[i][j]++;//同时ij处的棋子它的灵活性也应该增1

							//如果对面的棋子是王的情况下要单独考虑
							switch (targetChessID)
							{
							case 1:
								if (isRedActive) return 20000;	//红棋走棋的情况下如果能威胁到黑将那么就是将军,可以直接返回出去一个很大的价值
								break;
							case 8:
								if (!isRedActive) return 20000;	//黑棋走棋的情况下如果能威胁到红帅那么就是将军,可以直接返回出去一个很大的价值
								break;
							default:
								//如果威胁到的不是王那么就综合考虑其价值(根据威胁的棋子加上其威胁值)
								attackPoss[relativePoss[k].row][relativePoss[k].col] += (30 + (baseMainValue[targetChessID] - baseMainValue[nChessID]) / 10) / 10;
								break;
							}
						}
					}

				}
			}
		}
	}
	//统计数据
	for (i=0;i<10;i++)
	{
		for (j=0;j<9;j++)
		{
			nChessID = chessBoard[i][j];
			if (nChessID)
			{
				mainValue[i][j]++;//既然有棋子,那么其总价值首先要增1
				//然后把该位置的棋子的实时灵活性加进去
				mainValue[i][j] += baseFlexible[nChessID] * flexiblePoss[i][j];
				//再然后,如果是黑卒或者是红兵,那么它们有附加值,也应该加进去
				mainValue[i][j] += GetBingAddedValue(chessBoard, i, j);
			}
		}
	}
	//统计扫描到的数据
	int32 nHalfValue;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			nChessID = chessBoard[i][j];
			if (nChessID)
			{
				nHalfValue = baseMainValue[nChessID] / 16;
				//把每个棋子的基础价值加进去
				mainValue[i][j] += baseMainValue[nChessID];
				if (chessRule->IsRedChess(nChessID))//如果是红棋
				{
					if (attackPoss[i][j])//如果这个红棋有被威胁
					{
						if (isRedActive)//如果该红棋走
						{
							if (nChessID == 8) mainValue[i][j] -= 50;//如果是红帅的话,那么这颗棋子应该被减掉很大一部分价值
							else//如果是其它的棋子的话酌情减分
							{
								mainValue[i][j] -= nHalfValue * 2;
								if (guardPoss[i][j]) mainValue[i][j] += nHalfValue;	//这个棋子有保护性则酌情加分
							}
						}
						else //黑棋走,红棋被威胁
						{
							if (nChessID == 8) return 20000;//如果这颗棋子是黑子而且该黑棋走直接返回失败极大值
							mainValue[i][j] -= nHalfValue * 10;
							if (guardPoss[i][j]) mainValue[i][j] += nHalfValue * 9;
						}
						mainValue[i][j] -= attackPoss[i][j];
					}
					else//如果这个棋子没有受到威胁
					{
						if (guardPoss[i][j]) mainValue[i][j] += 5; //而且还被保护
					}
				}
				else//如果是黑棋
				{
					if (attackPoss[i][j])//如果这个黑棋有被威胁
					{
						if (!isRedActive)//如果该黑棋走
						{
							if (nChessID == 1) mainValue[i][j] -= 50;//如果是黑将的话,那么这颗棋子应该被减掉很大一部分价值
							else//如果是其它的棋子的话酌情减分
							{
								mainValue[i][j] -= nHalfValue * 2;
								if (guardPoss[i][j]) mainValue[i][j] += nHalfValue;	//这个棋子有保护性则酌情加分
							}
						}
						else //红棋走
						{
							if (nChessID == 1) return 20000;//如果该红棋走直接返回失败极大值
							mainValue[i][j] -= nHalfValue * 10;
							if (guardPoss[i][j]) mainValue[i][j] += nHalfValue * 9;
						}
						mainValue[i][j] -= attackPoss[i][j];
					}
					else//如果这个棋子没有受到威胁
					{
						if (guardPoss[i][j]) mainValue[i][j] += 5; //而且还被保护
					}
				}
			}
		}
	}
	//统计总分
	int32 nRedAllValue = 0, nBlueAllValue = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			nChessID = chessBoard[i][j];
			if (nChessID)
			{
				if (chessRule->IsRedChess(nChessID)) nRedAllValue += mainValue[i][j];//如果是红棋
				else nBlueAllValue += mainValue[i][j];
			}
		}
	}
	if (isRedActive) return nRedAllValue - nBlueAllValue;
	else return nBlueAllValue - nRedAllValue;
}

int32 ASearchMoveEngine::GetBingAddedValue(int32 chessBoard[10][9], int32 x, int32 y)
{
	if (chessBoard[x][y] == 7)//黑卒
		return zuValueScale[x][y];
	else if (chessBoard[x][y] == 14)//红兵
		return bingValueScale[x][y];
	else return 0;
}

int32 ASearchMoveEngine::IsGameOver(int32 chessBoard[10][9], int32 inSearchDepth)
{
	bool redLive = false, blueLive = false;
	for (int32 i=0;i<3;i++)
	{
		for (int32 j=3;j<6;j++)
		{
			if (chessBoard[i][j] == 1) blueLive = true;
			if (chessBoard[i][j] == 8)redLive = true;
		}
	}
	for (int32 i = 7; i < 10; i++)
	{
		for (int32 j = 3; j < 6; j++)
		{
			if (chessBoard[i][j] == 1) blueLive = true;
			if (chessBoard[i][j] == 8)redLive = true;
		}
	}
	int32 redMove = (maxSearchDepth - inSearchDepth) % 2;//判断当前该哪方棋子行走
	if (!redLive)
	{
		if (redMove) return 19990 + inSearchDepth;//返回极大值
		else return -19990 - inSearchDepth;//返回极小值
	}
	if (!blueLive)
	{
		if (redMove) return -19990 - inSearchDepth;
		else return 19990 + inSearchDepth;
	}
	return 0;
}

int32 ASearchMoveEngine::HypoMove(FChessMovePoint inChessMove)
{
	int32 chessID = AIChessBoard[inChessMove.to.row][inChessMove.to.col];//目标棋子
	AIChessBoard[inChessMove.to.row][inChessMove.to.col] = AIChessBoard[inChessMove.from.row][inChessMove.from.col];
	AIChessBoard[inChessMove.from.row][inChessMove.from.col] = 0;
	return chessID;
}

void ASearchMoveEngine::UndoHypoMove(FChessMovePoint inChessMove, int32 inChessID)
{
	AIChessBoard[inChessMove.from.row][inChessMove.from.col] = AIChessBoard[inChessMove.to.row][inChessMove.to.col];
	AIChessBoard[inChessMove.to.row][inChessMove.to.col] = inChessID;
}

int32 ASearchMoveEngine::NegativeMax(int32 inDepth)
{
	int32 current = -20000;
	int32 sorce = 0, i_over = 0, count = 0, chessID = 0;
	//检查游戏是否结束
	if (i_over) return i_over;
	//如果搜索结束了返回估值
	if (inDepth <= 0) return ChessEveluate(AIChessBoard, bool((maxSearchDepth - searchDepth) % 2));
	count = cMove->ValidMovePoints(AIChessBoard, inDepth, (maxSearchDepth - searchDepth) % 2);
	for (int32 i=0;i<count;i++)
	{
		//改变棋盘
		chessID = HypoMove(cMove->validMoveList[inDepth][i]);
		//递归调用
		sorce = NegativeMax(inDepth - 1);
		//恢复棋盘
		UndoHypoMove(cMove->validMoveList[inDepth][i], chessID);
		if (sorce>current)
		{
			current = sorce;
			if (inDepth==maxSearchDepth)
			{
				//产生最佳走法
				cBestMove = cMove->validMoveList[inDepth][i];
			}
		}
	}
	return current;//返回分数
}

void ASearchMoveEngine::SetChessRule(AChessRule* inChessRule)
{
	chessRule = inChessRule;
}

void ASearchMoveEngine::SetGeneratorMove(class AAIMoveGenerator* inMove)
{
	cMove = inMove;//给CMove赋值
}

void ASearchMoveEngine::SetSearchDepth(int32 inDepth)
{
	searchDepth = inDepth;
}

FChessMovePoint ASearchMoveEngine::AIMove()
{
	//初始化AI棋盘
	for (int32 i=0;i<10;i++)
		for (int32 j=0;j<9;j++)
			AIChessBoard[i][j] = chessRule->RunChessArray[i][j];

	//直接调用负极大值函数获取最佳走法
	maxSearchDepth = searchDepth;
	NegativeMax(maxSearchDepth);
	//然后把最佳走法返回出去
	return cBestMove;
}

