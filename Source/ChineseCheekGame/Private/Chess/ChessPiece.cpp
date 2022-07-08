// Fill out your copyright notice in the Description page of Project Settings.


#include "Chess/ChessPiece.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AChessPiece::AChessPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("rootComp"));
	chessMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("chessMesh"));
	textComp= CreateDefaultSubobject<UTextRenderComponent>(TEXT("textComp"));

	if (rootComp) { RootComponent = rootComp; }
	if (chessMesh)
	{
		chessMesh->SetupAttachment(rootComp);
	}
	if (textComp)
	{
		textComp->SetupAttachment(rootComp);
		textComp->SetWorldRotation(FRotator(90, 0, 0));
		textComp->SetWorldLocation(FVector(0, 0, 1.9));
		textComp->SetWorldScale3D(FVector(0.18, 0.18, 0.18));
		textComp->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
		textComp->VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
	}
}

// Called when the game starts or when spawned
void AChessPiece::BeginPlay()
{
	Super::BeginPlay();
	deathTime = maxMoveTime;
}

// Called every frame
void AChessPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickMoveSelf(DeltaTime);
	while (deathTime>0)
	{
		deathTime -= DeltaTime;
		if (deathTime<=0)
		{
			IsCanDeath = true;
			break;
		}
	}
}

void AChessPiece::SetTextInfo(FString inStr)
{
	textComp->SetText(inStr);
}

void AChessPiece::SetTextColor(bool isRedChess)
{
	if (isRedChess)
	{
		SetActorRotation(FRotator(0, 180, 0));
		if (matForRedChess)
		{
			textComp->SetMaterial(0, matForRedChess);
		}
	}
	else
	{
		if (matForBlueChess) { textComp->SetMaterial(0, matForBlueChess); }
	}
}

void AChessPiece::DefaultMat()
{
	if (matForWoodDefault)		chessMesh->SetMaterial(0, matForWoodDefault);
	if (matForRoundDefault) 	chessMesh->SetMaterial(1, matForRoundDefault);
}

void AChessPiece::ClickMat()
{
	if (matForWoodClick)	chessMesh->SetMaterial(0, matForWoodClick);
	if (matForRoundClick)	chessMesh->SetMaterial(1, matForRoundClick);
}

void AChessPiece::TickMoveSelf(float deltaTime)
{
	if (!isAutoMove) return;

	moveTime += deltaTime;
	if (moveTime>=maxMoveTime)
	{
		isAutoMove = false;
		SetActorLocation(targetLocation);
	}
	else
	{
		FVector temp_location = startLocation + moveDirection * moveTime * moveVelocity;
		temp_location.Z += 0.2 * moveDistance * UKismetMathLibrary::Sin((moveTime / maxMoveTime) * 3.14159);
		SetActorLocation(temp_location);
	}
}

void AChessPiece::MoveSelf(FVector inLocation)
{
	isAutoMove = true;
	targetLocation = inLocation;
	moveTime = 0;
	startLocation = GetActorLocation();//移动的初始位置
	moveDirection = targetLocation - startLocation;//移动的方向
	moveDistance = moveDirection.Size();//移动的距离
	moveDirection.Normalize();
	moveVelocity = moveDistance / maxMoveTime;//移动的速度
}

void AChessPiece::DeletSelf()
{
	if (IsCanDeath) 
	{ 
		Destroy(true); 
		IsCanDeath = false;
		deathTime = maxMoveTime;
	}
}

