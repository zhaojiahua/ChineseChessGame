// Fill out your copyright notice in the Description page of Project Settings.

#include "FrameWork/ChessPlayerController.h"
#include "FrameWork/ChessRule.h"
#include "FrameWork/ChessPlayerState.h"
#include "FrameWork/ChessCharacter.h"
#include "FrameWork/ChessGameInstance.h"
#include "Chess/EffectPosition.h"
#include "Chess/ChessBoard.h"
#include "Chess/ChessPiece.h"
#include "AI/AIMoveGenerator.h"
#include "AI/SearchMoveEngine.h"
#include "UI/ChessMainUI.h"
#include <Runtime/UMG/Public/Blueprint/UserWidget.h>
#include "Kismet/GameplayStatics.h"


AChessPlayerController::AChessPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AChessPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;	//显示鼠标指针
	cPlayer = Cast<AChessCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());//获取第一人称控制的玩家
	AChessPlayerState* cPlayerState = Cast<AChessPlayerState>(cPlayer->GetPlayerState());//获取玩家的playerstate
	
	if (cPlayerState) {
		UUserWidget* mouseStyleWiget = CreateWidget(GetWorld(), cPlayerState->MouseStyle);//获取playerstate中的UserWidget
		SetMouseCursorWidget(EMouseCursor::Default, mouseStyleWiget); 
	}//设置鼠标样式	

	//查找场景中棋盘
	TArray<AActor*> chessBoards;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChessBoard::StaticClass(), chessBoards);
	for (AActor* _cBoard: chessBoards)
	{
		AChessBoard* _tempBoard = Cast<AChessBoard>(_cBoard);
		if (_tempBoard)
		{
			chessBoard = _tempBoard;
		}
	}

	//创建规则类
	chessRule = GetWorld()->SpawnActor<AChessRule>(chessRule_BP);
	chessRule->Init(); //规则类初始化
	chessBoard->SetRule(chessRule); //将chessRule传给chessBoard
	chessBoard->Init(); //棋盘初始化

	//创建AI类
	cMove = GetWorld()->SpawnActor<AAIMoveGenerator>(cMoveGen_BP);//走法产生类
	cMove->SetAIRule(chessRule);

	searchEngine = GetWorld()->SpawnActor<ASearchMoveEngine>(searchEngine_BP);//走法产生类
	searchEngine->Init(chessRule, cMove,GetDepthFromGameInstance());

	//创建游戏主UI界面
	if (chessMainUI_BP)
	{
		UUserWidget* tempUI = CreateWidget(GetWorld(), chessMainUI_BP);
		chessMainUI = Cast<UChessMainUI>(tempUI);
		chessMainUI->AddToViewport();
	}
	//向UI界面添加信息
	AddDebugInfoToScreen(TEXT("欢迎来到中国象棋!!游戏开始了!!"));
	AddDebugInfoToScreen(TEXT("当前游戏难度等级: " + GetDepthUIFromDepth(GetDepthFromGameInstance())));
}

void AChessPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAxis("MousePush", this, &AChessPlayerController::MouseWheelPush);//绑定鼠标滚轮事件,BindAxis事件是一直被调用的
	InputComponent->BindAxis("LookUp", this, &AChessPlayerController::MouseLookUD);
	InputComponent->BindAxis("LookLeft", this, &AChessPlayerController::MouseLookLR);

	InputComponent->BindAction("MousePress",IE_Pressed, this, &AChessPlayerController::MousePressed);
	InputComponent->BindAction("MousePress", IE_Released, this, &AChessPlayerController::MouseReleased);

}

void AChessPlayerController::MouseLookUD(float value)
{
	if (bIsMousePressed) { cPlayer->AddControllerYawInput(value); }
}


void AChessPlayerController::MouseLookLR(float value)
{
	if (bIsMousePressed) { cPlayer->AddControllerPitchInput(value); }
}



void AChessPlayerController::MouseWheelPush(float value)
{
	cPlayer->MouseWheelPush(value);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("MouseWheelPush is been called!"));
}

void AChessPlayerController::MousePressed()
{
	bIsMousePressed = true;
	if (isRedMove)MouseDownClick();
}

void AChessPlayerController::MouseReleased()
{
	bIsMousePressed = false;
}

void AChessPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (tempMoveTime < moveIntervalTime) { tempMoveTime += DeltaTime; }
	else
	{
		isCanMoving = true;
		if (!isRedMove) AIMove();
	}
}

int32 AChessPlayerController::GetDepthFromGameInstance()
{
	UChessGameInstance* gameInstance = Cast<UChessGameInstance>(GetWorld()->GetGameInstance());
	return gameInstance->GetCurrentSearchDepth();
}

FString AChessPlayerController::GetDepthUIFromDepth(int32 inDepth)
{
	FString depthUI = " ";
	switch (inDepth)
	{
	case 1:
		depthUI += TEXT("初级");
		break;
	case 2:
		depthUI += TEXT("中级");
		break;
	case 3:
		depthUI += TEXT("高级");
		break;
	default:
		break;
	}
	return depthUI;
}

void AChessPlayerController::MouseDownClick()
{
	FHitResult hitResult;
	GetHitResultUnderCursor(ECC_WorldDynamic, false, hitResult);
	if (hitResult.bBlockingHit)
	{
		AEffectPosition* effectPos = Cast<AEffectPosition>(hitResult.Actor);
		if (effectPos)
		{
			int32 rowInfo =effectPos->GetRow();
			int32 colInfo = effectPos->GetCol();
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "row: " + FString::FromInt(rowInfo) + "col: " + FString::FromInt(colInfo));
			
			FChessMovePoint playerMovePoint;
			bool validMoveFinished = chessBoard->MouseClick(effectPos, playerMovePoint);//调用棋盘点击事件
			if (validMoveFinished)//走棋合法
			{
				ValidMoveChess(playerMovePoint);
				isRedMove=false;//红方合法走棋完了要设置成黑方走棋
				tempMoveTime = 0.0f;
			}
		}
	}
}

void AChessPlayerController::ValidMoveChess(FChessMovePoint playerMovePoint)
{
	AEffectPosition* firstClickPos = chessBoard->GetClickPosition(playerMovePoint.from.row, playerMovePoint.from.col);
	AEffectPosition* secondClickPos = chessBoard->GetClickPosition(playerMovePoint.to.row, playerMovePoint.to.col);
	//合法的走棋要么是行走要么是吃子
	if (chessRule->RunChessArray[playerMovePoint.to.row][playerMovePoint.to.col])//如果移动的点有棋子说明是吃子
		secondClickPos->GetChessFromThisPos()->DeletSelf();//把已有的棋子删掉
	
	//改变棋子位置
	firstClickPos->GetChessFromThisPos()->MoveSelf(secondClickPos->GetActorLocation());
	//获取第一个位置的棋子然后放置到第二个位置上
	secondClickPos->SetChessToThisPos(firstClickPos->GetChessFromThisPos());
	//把第一个位置置空
	firstClickPos->SetChessToThisPos(nullptr);

	//向界面输出信息
	FString tempLog = "";
	int32 tempInfoType = 0;
	if (isRedMove)
	{
		tempLog += TEXT("红棋: ");
		tempInfoType = 1;
	}
	else
	{
		tempLog += TEXT("黑棋: ");
		tempInfoType = 2;
	}
	//普通走棋记录
	tempLog += "from " + FString::FromInt(playerMovePoint.from.row) + "  " + FString::FromInt(playerMovePoint.from.col) + "   to " + FString::FromInt(playerMovePoint.to.row) + "  " + FString::FromInt(playerMovePoint.to.col);
	AddDebugInfoToScreen(tempLog, tempInfoType);
	//吃子的输出
	int32 chessIDValue = chessRule->RunChessArray[playerMovePoint.to.row][playerMovePoint.to.col];
	if (chessIDValue !=0)
	{
		tempLog = " ";
		tempInfoType = 0;
		if (chessRule->IsRedChess(chessIDValue))tempLog += TEXT("红色棋子: ") + chessBoard->GetChessInfo(chessIDValue) + TEXT(" 被吃掉!");
		else tempLog += TEXT("蓝色棋子: ") + chessBoard->GetChessInfo(chessIDValue) + TEXT(" 被吃掉!");
		AddDebugInfoToScreen(tempLog, tempInfoType);
	}
	//改变数组序列
	chessRule->ChangeRunChessArray(playerMovePoint);

	//将军提示
	int32 checkResult = chessRule->Checking();
	switch (checkResult)
	{
	case 1:
		AddDebugInfoToScreen(TEXT("红方被将军!!!"), 0);
		break;
	case 2:
		AddDebugInfoToScreen(TEXT("黑方被将军!!!"), 0);
		break;
	default:
		break;
	}
}

void AChessPlayerController::AIMove()
{
	FChessMovePoint temp_point = searchEngine->AIMove();
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::FromInt(temp_point.from.row) + FString::FromInt(temp_point.from.col) + FString::FromInt(temp_point.to.row) + FString::FromInt(temp_point.to.col));
	ValidMoveChess(temp_point);//AI移动棋子
	isRedMove = true;
	tempMoveTime = 0.0f;
}

void AChessPlayerController::AddDebugInfoToScreen(FString inString, int32 inType)
{
	if (chessMainUI) chessMainUI->AddToScreenInfo(inString, inType);
}

