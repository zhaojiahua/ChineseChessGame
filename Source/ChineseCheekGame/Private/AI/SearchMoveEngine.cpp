// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SearchMoveEngine.h"
#include "Chess/ChessBoard.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASearchMoveEngine::ASearchMoveEngine()
{
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
		for (x = 7; x <= 10; x++)
		{
			for (y = 3; y < 6; y++)
				if (chessRule->CanTouch(chessBoard, startX, startY, x, y)) AddRelativePos(x, y);
		}
		break;
	case 2://黑車
	case 9://红車
		x = 0, y = 0, nchessID = chessBoard[startX][startY];
		x = startX + 1; y = startY;//向下遍历
		while (x < 11)
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
		while (y < 10)
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
		while (x < 11)
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
		while (x < 11)
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
		while (x < 11)
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
		while (x < 11)
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
		if (x < 11 && y < 10 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX + 2; y = startY - 2;
		if (x < 11 && y >= 0 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
		x = startX - 2; y = startY + 2;
		if (x >= 0 && y < 10 && chessRule->CanTouch(chessBoard,startX, startY, x, y)) AddRelativePos(x, y);
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
		if (x < 11 ) AddRelativePos(x, y);
		//小兵过河的情况还要遍历左右
		if (x > 4)
		{
			x = startX; y = startY + 1;//向左遍历
			if (y < 10) AddRelativePos(x, y);
			x = startX; y = startY - 1;//向右遍历
			if (y >= 0) AddRelativePos(x, y);
		}
		break;
	case 13://红士
		x = 0, y = 0;
		for (x = 7; x <= 10; x++)
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
			if (y < 10) AddRelativePos(x, y);
			x = startX; y = startY - 1;//向右遍历
			if (y >= 0) AddRelativePos(x, y);
		}
		break;
	default:
		break;
	}

}

void ASearchMoveEngine::SetChessRule(AChessRule* inChessRule)
{
	chessRule = inChessRule;
}


