// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameWork/ChessCharacter.h"
#include "FrameWork/ChessPlayerState.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AChessCharacter::AChessCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("rootComp"));
	ARMcomp = CreateDefaultSubobject<USpringArmComponent>(TEXT("ARMcomp"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	if (rootComp)	{RootComponent = rootComp;}
	if (ARMcomp)	
	{	
		ARMcomp->SetupAttachment(rootComp);
		ARMcomp->TargetArmLength = 1050;
		ARMcomp->bUsePawnControlRotation = true;
	}
	if (CameraComp) { CameraComp->SetupAttachment(ARMcomp); }


}

// Called when the game starts or when spawned
void AChessCharacter::BeginPlay()
{
	Super::BeginPlay();
	cplayerState=zjhGetPlayerState();
}

void AChessCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChessCharacter::MouseWheelPush(float value)
{
	if (cplayerState)	ARMcomp->TargetArmLength += value * cplayerState->ARMSpeed;
}

AChessPlayerState* AChessCharacter::zjhGetPlayerState()
{
	return Cast<AChessPlayerState>(GetWorld()->GetFirstPlayerController()->GetPawn()->GetPlayerState());
	
}

