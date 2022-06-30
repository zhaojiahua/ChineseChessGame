// Fill out your copyright notice in the Description page of Project Settings.


#include "Chess/EffectPosition.h"

// Sets default values
AEffectPosition::AEffectPosition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("rootComp"));
	moveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("moveMesh"));
	eatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("eatMesh"));

	if (rootComp) { RootComponent = rootComp; }
	if (moveMesh)
	{
		moveMesh->SetupAttachment(rootComp);
	}
	if (eatMesh)
	{
		eatMesh->SetupAttachment(rootComp);
	}
}

// Called when the game starts or when spawned
void AEffectPosition::BeginPlay()
{
	Super::BeginPlay();
	HideMesh();
}

// Called every frame
void AEffectPosition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEffectPosition::SetRowCol(int32 inRow, int32 inCol)
{
	row = inRow;
	col = inCol;
}

int32 AEffectPosition::GetRow() { return row; }

int32 AEffectPosition::GetCol() { return col; }

void AEffectPosition::SetChessToThisPos(class AChessPiece* inChessPiece)
{
	chessPiece = inChessPiece;
}

bool AEffectPosition::HasChessActor()
{
	if (chessPiece == nullptr) { return false; }
	return true;
}

class AChessPiece* AEffectPosition::GetChessFromThisPos()
{
	return chessPiece;
}

void AEffectPosition::HideMesh()
{
	moveMesh->SetVisibility(false);
	eatMesh->SetVisibility(false);
}

void AEffectPosition::ShowMoveMesh() { moveMesh->SetVisibility(true); }

void AEffectPosition::ShowEatMesh() { eatMesh->SetVisibility(true); }

