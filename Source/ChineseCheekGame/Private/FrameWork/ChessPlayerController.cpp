// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameWork/ChessPlayerState.h"
#include "FrameWork/ChessPlayerController.h"
#include "FrameWork/ChessCharacter.h"
#include "FrameWork/ChessRule.h"
#include "Chess/EffectPosition.h"
#include "Chess/ChessBoard.h"
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
	MouseDownClick();
}

void AChessPlayerController::MouseReleased()
{
	bIsMousePressed = false;
}

void AChessPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "row: " + FString::FromInt(rowInfo) + "col: " + FString::FromInt(colInfo));
			chessBoard->MouseClick(effectPos);//调用棋盘点击事件
			
		}
	}
}
