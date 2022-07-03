// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIMoveGenerator.h"

// Sets default values
AAIMoveGenerator::AAIMoveGenerator()
{
}

void AAIMoveGenerator::SetAIRule(class AChessRule* inRule)
{
	chessRule = inRule;
}

void AAIMoveGenerator::AddValidMove(int32 chessIndex,int32 inFromRow, int32 inFromCol, int32 inToRow, int32 inToCol)
{
	validMoveList[chessIndex][validMoveCount].from.row = inFromRow;
	validMoveList[chessIndex][validMoveCount].from.col = inFromCol;
	validMoveList[chessIndex][validMoveCount].to.row = inToRow;
	validMoveList[chessIndex][validMoveCount].to.col = inToCol;
	validMoveCount++;
}

void AAIMoveGenerator::ValidMovePoints(int32 chessBoard[10][9], int32 chessIndex, int32 isRedSide)
{
	validMoveCount = 0;//首先把计数器归零
	int32 i = 0, j = 0, nchessID = 0;
	for (i=0;i<10;i++)
	{
		for (j=0;j<9;j++)
		{
			nchessID = chessBoard[i][j];
			if (nchessID)//如何格子上没有棋子则直接跳过
			{
				if (isRedSide &&chessRule->IsBlueChess(nchessID)) continue;//如果是产生红棋的走法,则跳过黑棋
				if (!isRedSide &&chessRule->IsRedChess(nchessID)) continue;//如果是产生黑棋的走法,则跳过红棋
				/*
				黑 : 将1,車2,马3,炮4,象5,士6,卒7
				红 : 帅8,車9,马10,炮11,相12,士13,兵14
				*/
				switch (nchessID)
				{
				case 1://黑将
				case 8://红帅
					Gen_KingMove(chessBoard, i, j, chessIndex);
					break;
				case 2://黑車
				case 9://红車
					Gen_JuMove(chessBoard, i, j, chessIndex);
					break;
				case 3://黑马
				case 10://红马
					Gen_MaMove(chessBoard, i, j, chessIndex);
					break;
				case 4://黑炮
				case 11://红炮
					Gen_PaoMove(chessBoard, i, j, chessIndex);
					break;
				case 5://黑象
				case 12://红相
					Gen_XiangMove(chessBoard, i, j, chessIndex);
					break;
				case 6://黑士
					Gen_BShiMove(chessBoard, i, j, chessIndex);
					break;
				case 7://黑卒
					Gen_ZuMove(chessBoard, i, j, chessIndex);
					break;
				case 13://红士
					Gen_RShiMove(chessBoard, i, j, chessIndex);
					break;
				case 14://红兵
					Gen_BingMove(chessBoard, i, j, chessIndex);
					break;
				default:
					break;
				}
			}
		}
	}
}

void AAIMoveGenerator::Gen_KingMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 temp_row = 0, temp_col = 0;
	for (temp_row=0;temp_row<3;temp_row++)
	{
		for (temp_col=3;temp_col<6;temp_col++)
		{
			if (chessRule->IsValidMove(chessBoard, startRow, startCol, temp_row, temp_col)) AddValidMove(chessIndex, startRow, startCol, temp_row, temp_col);
		}
	}
	for (temp_row = 7; temp_row < 10; temp_row++)
	{
		for (temp_col = 3; temp_col < 6; temp_col++)
		{
			if (chessRule->IsValidMove(chessBoard, startRow, startCol, temp_row, temp_col)) AddValidMove(chessIndex, startRow, startCol, temp_row, temp_col);
		}
	}
}

void AAIMoveGenerator::Gen_JuMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0, nchessID = chessBoard[startRow][startCol];
	x = startRow + 1; y = startCol;//向下遍历
	while (x<11)
	{
		if (chessBoard[x][y] == 0) AddValidMove(chessIndex, startRow, startCol, x, y);
		else
		{
			if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		x++;
	}
	x = startRow - 1; y = startCol;//向上遍历
	while (x>=0)
	{
		if (chessBoard[x][y] == 0) AddValidMove(chessIndex, startRow, startCol, x, y);
		else
		{
			if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		x--;
	}
	x = startRow; y = startCol+1;//向左遍历
	while (y<10)
	{
		if (chessBoard[x][y] == 0) AddValidMove(chessIndex, startRow, startCol, x, y);
		else
		{
			if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		y++;
	}
	x = startRow; y = startCol-1;//向右遍历
	while (y>=0)
	{
		if (chessBoard[x][y] == 0) AddValidMove(chessIndex, startRow, startCol, x, y);
		else
		{
			if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		y--;
	}
}

void AAIMoveGenerator::Gen_MaMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0;
	//八个方向分别遍历
	x = startRow + 1; y = startCol + 2;
	if (x < 10 && y < 9 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow + 1; y = startCol - 2;
	if (x < 10 && y >=0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 1; y = startCol + 2;
	if (x >= 0 && y < 9 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 1; y = startCol - 2;
	if (x >= 0 && y >= 0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow + 2; y = startCol + 1;
	if (x < 10 && y < 9 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow + 2; y = startCol - 1;
	if (x < 10 && y >=0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 2; y = startCol + 1;
	if (x >= 0 && y < 9 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 2; y = startCol - 1;
	if (x >= 0 && y >= 0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
}

void AAIMoveGenerator::Gen_PaoMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0, nchessID = chessBoard[startRow][startCol];
	bool flag = false;
	x = startRow + 1; y = startCol;//向下遍历
	flag = false;
	while (x < 11)
	{
		if (chessBoard[x][y] == 0)
		{
			if (!flag)AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		else
		{
			if (flag == false)flag = true;
			else
			{
				if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
				break;
			}
		}
		x++;
	}
	x = startRow - 1; y = startCol;//向上遍历
	flag = false;
	while (x < 11)
	{
		if (chessBoard[x][y] == 0)
		{
			if (!flag)AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		else
		{
			if (flag == false)flag = true;
			else
			{
				if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
				break;
			}
		}
		x--;
	}
	x = startRow; y = startCol + 1;//向左遍历
	flag = false;
	while (x < 11)
	{
		if (chessBoard[x][y] == 0)
		{
			if (!flag)AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		else
		{
			if (flag == false)flag = true;
			else
			{
				if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
				break;
			}
		}
		y++;
	}
	x = startRow; y = startCol - 1;//向右遍历
	flag = false;
	while (x < 11)
	{
		if (chessBoard[x][y] == 0)
		{
			if (!flag)AddValidMove(chessIndex, startRow, startCol, x, y);
		}
		else
		{
			if (flag == false)	flag = true;
			else
			{
				if (!chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
				break;
			}
		}
		y--;
	}
}

void AAIMoveGenerator::Gen_XiangMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0;
	//四个方向分别遍历
	x = startRow + 2; y = startCol + 2;
	if (x<11&&y<10&&chessRule->IsValidMove(startRow, startCol,x,y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow + 2; y = startCol - 2;
	if (x < 11 && y >= 0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 2; y = startCol + 2;
	if (x >= 0 && y < 10 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
	x = startRow - 2; y = startCol - 2;
	if (x >=0 && y>=0 && chessRule->IsValidMove(startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
}

void AAIMoveGenerator::Gen_BShiMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0;
	for (x = 0; x < 3; x++)
	{
		for (y = 3; y < 6; y++)
		{
			if (chessRule->IsValidMove(chessBoard, startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
	}
}

void AAIMoveGenerator::Gen_RShiMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0;
	for (x = 7; x <= 10; x++)
	{
		for (y = 3; y < 6; y++)
		{
			if (chessRule->IsValidMove(chessBoard, startRow, startCol, x, y)) AddValidMove(chessIndex, startRow, startCol, x, y);
		}
	}
}

void AAIMoveGenerator::Gen_ZuMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0, nchessID = chessBoard[startRow][startCol];
	x = startRow + 1; y = startCol;
	if (x < 11 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
	//小兵过河的情况还要遍历左右
	if (x > 4)
	{
		x = startRow; y = startCol + 1;//向左遍历
		if (y < 10 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		x = startRow; y = startCol - 1;//向右遍历
		if (y >= 0 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
	}

}

void AAIMoveGenerator::Gen_BingMove(int32 chessBoard[10][9], int32 startRow, int32 startCol, int32 chessIndex)
{
	int32 x = 0, y = 0, nchessID = chessBoard[startRow][startCol];
	x = startRow - 1; y = startCol;
	if (x >= 0 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
	//小兵过河的情况还要遍历左右
	if (x<5)
	{
		x = startRow; y = startCol + 1;//向左遍历
		if (y < 10 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
		x = startRow; y = startCol - 1;//向右遍历
		if (y >= 0 && !chessRule->IsSameColorChess(nchessID, chessBoard[x][y])) AddValidMove(chessIndex, startRow, startCol, x, y);
	}
}

