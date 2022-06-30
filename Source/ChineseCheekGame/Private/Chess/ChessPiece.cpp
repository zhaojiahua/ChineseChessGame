// Fill out your copyright notice in the Description page of Project Settings.


#include "Chess/ChessPiece.h"
#include "Components/TextRenderComponent.h"

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
	
}

// Called every frame
void AChessPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

