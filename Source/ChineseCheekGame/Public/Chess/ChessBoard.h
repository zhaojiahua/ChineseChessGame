// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FrameWork/ChessRule.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessBoard.generated.h"

UCLASS()
class CHINESECHEEKGAME_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* rootComp;//作为根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* boardMesh;//棋盘网格体
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* arrowComp;//箭头定位


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChessAttrs")
		float chessDistance = 90.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChessAttrs")
		TSubclassOf<class AEffectPosition> clickPos;//引入点击有效位置类
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChessAttrs")
		TSubclassOf<class AChessPiece> chessPiece;//引入棋子类

	class AEffectPosition* firstClickPos=nullptr;//第一次点击存储的effectposition

	class AChessRule* chessRule;//开始将ChessRule类引入进来
	void SetRule(class AChessRule* inRule);

	void Init();//做一些初始化的工作

	void SpawnChessAndPos();//负责生成棋盘上的棋子和有效位置
	class AEffectPosition* SpawnClickPos(FVector inLocation, int32 inRow, int32 inCol);//负责生成可点击位置
	class AChessPiece* SpawnChess(FVector inLocation, int32 chessValue);//负责生成棋子

	FString GetChessInfo(int32 inValue);//获取棋子的信息

	bool MouseClick(AEffectPosition* effectPos, FChessMovePoint& playerMovePoint);//棋盘的点击事件

	//通过行列查找可点击的位置
	class AEffectPosition* GetClickPosition(int32 inRow, int32 inCol);

	//清空可行走位置
	void ClearCanMovePointsArray();

	void InitBoardAgain();
	//清空棋盘上的棋子
	void ClearChessPiece();
	//返回悔棋棋盘
	void BackPreBoard(int32 inBoardPosition[10][9]);

private:
	class AEffectPosition* clickPointsArray[10][9];

	TArray<class AEffectPosition*> canMovePointsArray;//棋盘上所有的可点击的点
	TArray<class AChessPiece*>chessArray;//生成的棋盘上的所有的棋子
};
