// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/KismetMathLibrary.h"
#include "FrameWork/ChessRule.h"

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

bool AChessRule::IsValidMove(int32 boardPosition[10][9], int32 fromRow, int32 fromCol, int32 toRow, int32 toCol)
{
	if (fromRow == toRow && fromCol == toCol) return;//起始点和落子点相同则函数不生效直接返回出去

	int32 fromValue = boardPosition[fromRow][fromCol];
	int32 toValue = boardPosition[toRow][toCol];
	if (IsSameColorChess(fromValue, toValue)) return false;
/*
黑 : 将1,車2,马3,炮4,象5,士6,卒7
红 : 帅8,車9,马10,炮11,相12,士13,兵14
*/
	switch (fromValue)
	{
	case 1:
		if (toValue==8) //将帅照面的情况下可以直接把对方干掉
		{
			if (fromCol != toCol) return false;//将帅不在同一列的情况直接判断为无效
			//如果在同一列,中间没有其他棋子的情况也直接为无效
			for (int32 i=fromRow+1;i<toRow;i++)
			{
				if (boardPosition[i][fromCol] != 0)return false;
			}
		}
		else
		{
			if (toRow > 2 || toCol < 3 || toCol>5) return false; //超出九宫格的直接视为无效
			if (UKismetMathLibrary::Abs(fromRow - toRow) + UKismetMathLibrary::Abs(fromCol - toCol)) return false;//走棋超过一格视为无效
		}
		break;
	case 8:
		if (toValue == 1) //将帅照面的情况下可以直接把对方干掉
		{
			if (fromCol != toCol) return false;//将帅不在同一列的情况直接判断为无效
			//如果在同一列,中间没有其他棋子的情况也直接为无效
			for (int32 i = toRow + 1; i < fromRow; i++)
			{
				if (boardPosition[i][fromCol] != 0)return false;
			}
		}
		else
		{
			if (toRow < 7 || toCol < 3 || toCol>5) return false; //超出九宫格的直接视为无效
			if (UKismetMathLibrary::Abs(fromRow - toRow) + UKismetMathLibrary::Abs(fromCol - toCol)) return false;//走棋超过一格视为无效
		}
		break;
	case 2:
	case 9:
		//車的走法
		if (fromRow != toRow && fromCol != toCol)return false;	//如果不是直线的话直接否定
		if (fromRow==toRow)//水平移动
		{
			if (fromCol>toCol)//向右走棋
			{
				for (int32 i =toCol;i<fromCol;i++)
				{
					if (boardPosition[fromRow][i] != 0) return false;
				}
			}
			else//向左走棋
			{
				for (int32 i = fromCol; i < toCol; i++)
				{
					if (boardPosition[fromRow][i] != 0) return false;
				}
			}
		}
		else//竖直移动(前进或后退)
		{
			if (fromRow>toRow)//向上移动(前进)
			{
				for (int32 i = toRow;i<fromRow;i++)
				{
					if (boardPosition[i][fromCol] != 0) return false;
				}
			}
			else//向下移动(后退)
			{
				for (int32 i = fromRow; i < toRow; i++)
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
		int32 i = 0, j = 0;
		if (toRow-fromRow==2)//向下走
		{
			i = fromRow + 1;
			j = fromCol;
		}
		else if (fromRow-toRow==2)//向上走
		{
			i = fromRow - 1;
			j = fromCol;
		}
		else if (fromCol-toCol==2)//向右走
		{
			i = fromRow;
			j = fromCol - 1;
		}
		else if (toCol-fromCol==2)//向左走
		{
			i = fromRow;
			j = fromCol + 1;
		}
		if (boardPosition[i][j] != 0) return false;
		break;
	case 4:
	case 11:
		//炮的走法
		if (fromRow != toRow && fromCol != toCol)return false;	//如果不是直线的话直接否定
		//吃子
		if (boardPosition[toRow][toCol]!=0)
		{
			int32 eatCount = 0;
			if (fromRow==toRow)//水平方向吃子
			{
				if (fromCol>toCol)//向右吃子
				{
					for (int32 i=toCol;i<fromCol;i++)
					{
						if (boardPosition[fromRow][i] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
				else//向左吃子
				{
					for (int32 i = fromCol; i < toCol; i++)
					{
						if (boardPosition[fromRow][i] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
			}
			else if (fromCol==toCol)//竖直方向吃子
			{
				if (fromRow>toRow)//向上吃子
				{
					for (int32 i = toRow; i < fromRow; i++)
					{
						if (boardPosition[i][fromCol] != 0)eatCount++;
					}
					if (eatCount != 1) return false;
				}
				else//向下吃子
				{
					for (int32 i = fromRow; i < toRow; i++)
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
					for (int32 i = toCol; i < fromCol; i++)
					{
						if (boardPosition[fromRow][i] != 0) return false;
					}
				}
				else//向左走棋
				{
					for (int32 i = fromCol; i < toCol; i++)
					{
						if (boardPosition[fromRow][i] != 0) return false;
					}
				}
			}
			else//竖直移动(前进或后退)
			{
				if (fromRow > toRow)//向上移动(前进)
				{
					for (int32 i = toRow; i < fromRow; i++)
					{
						if (boardPosition[i][fromCol] != 0) return false;
					}
				}
				else//向下移动(后退)
				{
					for (int32 i = fromRow; i < toRow; i++)
					{
						if (boardPosition[i][fromCol] != 0) return false;
					}
				}
			}
		}
		break;
	case 5:
		//黑象的走法
		break;
	case 12:
		//红相的走法
		break;
	case 6:
		//黑士的走法
		break;
	case 13:
		//红士的走法
		break;
	case 7:
	case 14:
		break;
	default:
		break;
	}
}
