// Fill out your copyright notice in the Description page of Project Settings.

#include "FrameWork/ChessRule.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AChessRule::AChessRule()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChessRule::BeginPlay()
{
	Super::BeginPlay();

}


void AChessRule::Init()
{
	for (int32 i = 0; i < 10; i++)
		for (int32 j = 0; j < 9; j++)
			RunChessArray[i][j] = InitChessArray[i][j];
}

bool AChessRule::IsRedChess(int32 inValue)
{
	if (inValue > 7 && inValue < 15) { return true; }
	return false;
}

bool AChessRule::IsBlueChess(int32 inValue)
{
	if (inValue < 8 && inValue>0) { return true; }
	return false;
}


bool AChessRule::IsRedChess(int32 inRow, int32 inCol)
{
	return IsRedChess(RunChessArray[inRow][inCol]);
}

bool AChessRule::IsBlueChess(int32 inRow, int32 inCol)
{
	return IsBlueChess(RunChessArray[inRow][inCol]);
}

bool AChessRule::IsSameColorChess(int32 inValue1, int32 inValue2)
{
	if (IsRedChess(inValue1) && IsRedChess(inValue2) || IsBlueChess(inValue1) && IsBlueChess(inValue2)) return true;
	else return false;
}

bool AChessRule::CanTouch(int32 boardPosition[10][9], int32 fromRow, int32 fromCol, int32 toRow, int32 toCol)
{
	if (fromRow == toRow && fromCol == toCol) return false;//起始点和落子点相同则函数不生效直接返回出去

	int32 fromValue = boardPosition[fromRow][fromCol];
	int32 toValue = boardPosition[toRow][toCol];
	/*
	黑 : 将1,車2,马3,炮4,象5,士6,卒7
	红 : 帅8,車9,马10,炮11,相12,士13,兵14
	*/
	int32 temp_row = 0; int32 temp_col = 0;
	switch (fromValue)
	{
	case 1://黑将的走法
		if (toValue == 8) //将帅照面的情况下可以直接把对方干掉
		{
			if (fromCol != toCol) return false;//将帅不在同一列的情况直接判断为无效
			//如果在同一列,中间没有其他棋子的情况也直接为无效
			for (int32 i = fromRow + 1; i < toRow; i++)
				if (boardPosition[i][fromCol] != 0)return false;
		}
		else
		{
			if (toRow > 2 || toCol < 3 || toCol>5) return false; //超出九宫格的直接视为无效
			if (UKismetMathLibrary::Abs(fromRow - toRow) + UKismetMathLibrary::Abs(fromCol - toCol) != 1) return false;//走棋超过一格视为无效
		}
		break;
	case 8://红帅的走法
		if (toValue == 1) //将帅照面的情况下可以直接把对方干掉
		{
			if (fromCol != toCol) return false;//将帅不在同一列的情况直接判断为无效
			//如果在同一列,中间没有其他棋子的情况也直接为无效
			for (int32 i = toRow + 1; i < fromRow; i++)
				if (boardPosition[i][fromCol] != 0)return false;
		}
		else
		{
			if (toRow < 7 || toCol < 3 || toCol>5) return false; //超出九宫格的直接视为无效
			if (UKismetMathLibrary::Abs(fromRow - toRow) + UKismetMathLibrary::Abs(fromCol - toCol) != 1) return false;//走棋超过一格视为无效
		}
		break;
	case 2:
	case 9:
		//車的走法
		if (fromRow != toRow && fromCol != toCol)return false;	//如果不是直线的话直接否定
		if (fromRow == toRow)//水平移动
		{
			if (fromCol > toCol)//向右走棋
			{
				for (int32 i = fromCol - 1; i > toCol; i--)
				{
					if (boardPosition[fromRow][i] != 0) return false;
				}
			}
			else //向左走棋
			{
				for (int32 i = fromCol + 1; i < toCol; i++)
				{
					if (boardPosition[fromRow][i] != 0) return false;
				}
			}
		}
		else//竖直移动(前进或后退)
		{
			if (fromRow > toRow)//向上移动(前进)
			{
				for (int32 i = fromRow - 1; i > toRow; i--)
				{
					if (boardPosition[i][fromCol] != 0) return false;
				}
			}
			else//向下移动(后退)
			{
				for (int32 i = fromRow + 1; i < toRow; i++)
				{
					if (boardPosition[i][fromCol] != 0) return false;
				}
			}
		}
		break;
	case 3:
	case 10:
		//马的走法
		if (!((UKismetMathLibrary::Abs(fromRow - toRow) == 2 && UKismetMathLibrary::Abs(fromCol - toCol) == 1) || (UKismetMathLibrary::Abs(fromRow - toRow) == 1 && UKismetMathLibrary::Abs(fromCol - toCol) == 2)))return false;//马走日
		//别马脚
		if (toRow - fromRow == 2)//向下走
		{
			temp_row = fromRow + 1;
			temp_col = fromCol;
		}
		else if (fromRow - toRow == 2)//向上走
		{
			temp_row = fromRow - 1;
			temp_col = fromCol;
		}
		else if (fromCol - toCol == 2)//向右走
		{
			temp_row = fromRow;
			temp_col = fromCol - 1;
		}
		else if (toCol - fromCol == 2)//向左走
		{
			temp_row = fromRow;
			temp_col = fromCol + 1;
		}
		if (boardPosition[temp_row][temp_col] != 0) return false;
		break;
	case 4:
	case 11:
		//炮的走法
		if (fromRow != toRow && fromCol != toCol)return false;	//如果不是直线的话直接否定
		//吃子
		if (boardPosition[toRow][toCol] != 0)
		{
			int32 eatCount = 0;
			if (fromRow == toRow)//水平方向吃子
			{
				if (fromCol > toCol)//向右吃子
				{
					for (int32 i = fromCol - 1; i > toCol; i--)
					{
						if (boardPosition[fromRow][i] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
				else//向左吃子
				{
					for (int32 i = fromCol + 1; i < toCol; i++)
					{
						if (boardPosition[fromRow][i] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
			}
			else if (fromCol == toCol)//竖直方向吃子
			{
				if (fromRow > toRow)//向上吃子
				{
					for (int32 i = fromRow - 1; i > toRow; i--)
					{
						if (boardPosition[i][fromCol] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
				else//向下吃子
				{
					for (int32 i = fromRow + 1; i < toRow; i++)
					{
						if (boardPosition[i][fromCol] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
			}
		}
		//走棋
		else
		{
			if (fromRow == toRow)//水平移动
			{
				if (fromCol > toCol)//向右走棋
				{
					for (int32 i = fromCol - 1; i > toCol; i--)
					{
						if (boardPosition[fromRow][i] != 0) return false;
					}
				}
				else //向左走棋
				{
					for (int32 i = fromCol + 1; i < toCol; i++)
					{
						if (boardPosition[fromRow][i] != 0) return false;
					}
				}
			}
			else//竖直移动(前进或后退)
			{
				if (fromRow > toRow)//向上移动(前进)
				{
					for (int32 i = fromRow - 1; i > toRow; i--)
					{
						if (boardPosition[i][fromCol] != 0) return false;
					}
				}
				else//向下移动(后退)
				{
					for (int32 i = fromRow + 1; i < toRow; i++)
					{
						if (boardPosition[i][fromCol] != 0) return false;
					}
				}
			}
		}
		break;
	case 5:
		//黑象的走法
		if (toRow > 4)return false;
		if (UKismetMathLibrary::Abs(toRow - fromRow) != 2 || UKismetMathLibrary::Abs(toCol - fromCol) != 2) return false;
		if (boardPosition[(fromRow + toRow) / 2][(fromCol + toCol) / 2] != 0) return false;
		break;
	case 12:
		//红相的走法
		if (toRow < 5)return false;
		if (UKismetMathLibrary::Abs(toRow - fromRow) != 2 || UKismetMathLibrary::Abs(toCol - fromCol) != 2) return false;
		if (boardPosition[(fromRow + toRow) / 2][(fromCol + toCol) / 2] != 0) return false;
		break;
	case 6:
		//黑士的走法
		if (toRow > 2 || toCol > 5 || toCol < 3)return false;//超出田字格直接返回false
		if (UKismetMathLibrary::Abs(toRow - fromRow) != 1 || UKismetMathLibrary::Abs(toCol - fromCol) != 1) return false;
		break;
	case 13:
		//红士的走法
		if (toRow < 7 || toCol > 5 || toCol < 3)return false;
		if (UKismetMathLibrary::Abs(toRow - fromRow) != 1 || UKismetMathLibrary::Abs(toCol - fromCol) != 1) return false;
		break;
	case 7:
		//黑卒的走法
		if (toRow < fromRow)return false;//黑卒不能回头
		if (fromRow < 5 && fromRow == toRow) return false;//过河之前不能左右走
		if (UKismetMathLibrary::Abs(toRow - fromRow) + UKismetMathLibrary::Abs(toCol - fromCol) != 1)return false;//一次只能走一步
	case 14:
		//红兵的走法
		if (toRow > fromRow)return false;//红兵不能回头
		if (fromRow > 4 && fromRow == toRow) return false;//过河之前不能左右走
		if (UKismetMathLibrary::Abs(toRow - fromRow) + UKismetMathLibrary::Abs(toCol - fromCol) != 1)return false;//一次只能走一步
		break;
	default:
		break;
	}
	return true;
}

bool AChessRule::IsValidMove(int32 boardPosition[10][9], int32 fromRow, int32 fromCol, int32 toRow, int32 toCol)
{
	int32 fromValue = boardPosition[fromRow][fromCol];
	int32 toValue = boardPosition[toRow][toCol];
	if (IsSameColorChess(fromValue, toValue)) return false;
	else
		return CanTouch(boardPosition, fromRow, fromCol, toRow, toCol);
}

bool AChessRule::IsValidMove(int32 fromRow, int32 fromCol, int32 toRow, int32 toCol)
{
	return IsValidMove(RunChessArray, fromRow, fromCol, toRow, toCol);
}

void AChessRule::ChangeRunChessArray(FChessMovePoint movePoint)
{
	RunChessArray[movePoint.to.row][movePoint.to.col] = RunChessArray[movePoint.from.row][movePoint.from.col];
	RunChessArray[movePoint.from.row][movePoint.from.col] = 0;
}

TArray<int32> AChessRule::GetCanMovePosition(int32 inRow, int32 inCol)
{
	TArray<int32> temp_array;
	for (int32 i = 0; i < 10; i++)
	{
		for (int32 j = 0; j < 9; j++)
		{
			if (IsValidMove(inRow,inCol,i,j))
			{
				temp_array.Add(i);
				temp_array.Add(j);
			}
		}
	}
	return temp_array;
}
