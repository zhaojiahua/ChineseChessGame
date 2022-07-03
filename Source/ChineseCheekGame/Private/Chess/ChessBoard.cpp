// Fill out your copyright notice in the Description page of Project Settings.


#include "Chess/ChessBoard.h"
#include "Chess/EffectPosition.h"
#include "Chess/ChessPiece.h"
#include "FrameWork/ChessRule.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#

// Sets default values
AChessBoard::AChessBoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("rootComp"));
	if (rootComp) { RootComponent = rootComp; }
	boardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("boardMesh"));
	if (boardMesh)
	{
		boardMesh->SetupAttachment(rootComp);
	}
	arrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("arrowComp"));
	if (arrowComp)
	{
		arrowComp->SetupAttachment(rootComp);
		arrowComp->SetWorldRotation(FRotator(90, 0, 0));
		arrowComp->SetWorldLocation(FVector(350, 314, 230));
		arrowComp->ArrowSize = 0.5;
		arrowComp->ArrowColor = FColor::Green;
	}
}

// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChessBoard::SetRule(class AChessRule* inRule) { chessRule = inRule; }

void AChessBoard::Init() { SpawnChessAndPos(); }

void AChessBoard::SpawnChessAndPos()
{
	FVector InitLocation = arrowComp->GetComponentLocation();
	for (int32 i = 0; i < 10; i++)
	{
		for (int32 j = 0; j < 9; j++)
		{
			FVector newLocation = InitLocation + InitLocation.BackwardVector * i * chessDistance + InitLocation.LeftVector * j * chessDistance;
			AEffectPosition* clickPosition = nullptr;
			AChessPiece* chessActor = nullptr;
			if (clickPos) 
			{ 
				clickPosition = SpawnClickPos(newLocation, i, j); 
				clickPointsArray[i][j] = clickPosition;
			}
			if (chessPiece && chessRule->InitChessArray[i][j] != 0)
			{
				chessActor = SpawnChess(newLocation, chessRule->InitChessArray[i][j]);//创建了棋子
				//然后把棋子传入到可点击的EffectPosition上面
				clickPosition->SetChessToThisPos(chessActor);

			}
		}
	}
}

AEffectPosition* AChessBoard::SpawnClickPos(FVector inLocation, int32 inRow, int32 inCol)
{
	AEffectPosition* tempEpos = GetWorld()->SpawnActor<AEffectPosition>(clickPos);
	tempEpos->SetActorLocation(inLocation);
	tempEpos->SetRowCol(inRow, inCol);
	return tempEpos;
}

AChessPiece* AChessBoard::SpawnChess(FVector inLocation, int32 chessValue)
{
	AChessPiece* chess_temp = GetWorld()->SpawnActor<AChessPiece>(chessPiece);//生成棋子
	//设置位置
	chess_temp->SetActorLocation(inLocation);
	//指定是哪一颗棋子

	//设置该棋子字面文字
	chess_temp->SetTextInfo(GetChessInfo(chessValue));
	//设置该棋子的颜色
	chess_temp->SetTextColor(chessRule->IsRedChess(chessValue));

	return chess_temp;
}

FString AChessBoard::GetChessInfo(int32 inValue)
{
	FString info = " ";
	switch (inValue)
	{
	case 1:
		info = TEXT("将");
		break;
	case 2:
		info = TEXT("車");
		break;
	case 3:
		info = TEXT("马");
		break;
	case 4:
		info = TEXT("炮");
		break;
	case 5:
		info = TEXT("象");
		break;
	case 6:
		info = TEXT("士");
		break;
	case 7:
		info = TEXT("卒");
		break;
	case 8:
		info = TEXT("帅");
		break;
	case 9:
		info = TEXT("車");
		break;
	case 10:
		info = TEXT("马");
		break;
	case 11:
		info = TEXT("炮");
		break;
	case 12:
		info = TEXT("相");
		break;
	case 13:
		info = TEXT("士");
		break;
	case 14:
		info = TEXT("兵");
		break;
	default:
		break;
	}
	return info;
}

bool AChessBoard::MouseClick(AEffectPosition* effectPos, FChessMovePoint& playerMovePoint)
{
	//判断是否是自己的棋子(如果是自己的棋子就产生效果,如果是对方的棋子就没有反应)
	bool isRedChess = chessRule->IsRedChess(effectPos->GetRow(), effectPos->GetCol());

	//每次点击都要清空一下canMovePointArray
	ClearCanMovePointsArray();

	//第一次点击进行存储
	if (firstClickPos == nullptr)
	{
		//空指针说明是第一次点击
		if (isRedChess)
		{
			firstClickPos = effectPos;
			//要产生的点击效果
			if (effectPos->HasChessActor())
			{
				firstClickPos->GetChessFromThisPos()->ClickMat();
				//同时标记可走位置和可吃子
				TArray<int32> canMoveArray = chessRule->GetCanMovePosition(firstClickPos->GetRow(), firstClickPos->GetCol());
				for (int32 temp=0;temp<canMoveArray.Num();temp+=2)
				{
					AEffectPosition* temp_effectPos = GetClickPosition(canMoveArray[temp], canMoveArray[temp + 1]);
					canMovePointsArray.Add(temp_effectPos);
					if (temp_effectPos->GetChessFromThisPos()) { temp_effectPos->ShowEatMesh(); }//如果该位置有棋子说明是吃子
					else { temp_effectPos->ShowMoveMesh(); }//否则说明是走棋
				}
			}
		}
	}
	//第二次点击要么是走棋要么是吃子
	else
	{
		firstClickPos->GetChessFromThisPos()->DefaultMat();//第二次点击时.第一个棋子的特效就要被关掉
		//如果第二次点击的仍然是自己的棋子
		if (isRedChess)
		{
			firstClickPos = nullptr;
			MouseClick(effectPos, playerMovePoint);
		}
		else
		{
			//否则点击到了对方的棋子(那就是为了吃子)或者是点到了空(那就是行走)
			//首先判断走棋是否有效
			bool isValidMove = chessRule->IsValidMove(firstClickPos->GetRow(), firstClickPos->GetCol(), effectPos->GetRow(), effectPos->GetCol());
			if (isValidMove)
			{
				//走棋有效再产生走法
				//对走法进行赋值
				playerMovePoint.from.row = firstClickPos->GetRow();
				playerMovePoint.from.col = firstClickPos->GetCol();
				playerMovePoint.to.row = effectPos->GetRow();
				playerMovePoint.to.col = effectPos->GetCol();
				firstClickPos = nullptr;
				return true;
			}
		}
	}
	return false;
}

class AEffectPosition* AChessBoard::GetClickPosition(int32 inRow, int32 inCol)
{
	return clickPointsArray[inRow][inCol];
}

void AChessBoard::ClearCanMovePointsArray()
{
	for (int32 i = 0; i < canMovePointsArray.Num(); i++) { canMovePointsArray[i]->HideMesh(); }
	canMovePointsArray.Reset(0);
}


