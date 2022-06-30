// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/Chess/ChessBoard.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessBoard() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessBoard_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessBoard();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AEffectPosition_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPiece_NoRegister();
// End Cross Module References
	void AChessBoard::StaticRegisterNativesAChessBoard()
	{
	}
	UClass* Z_Construct_UClass_AChessBoard_NoRegister()
	{
		return AChessBoard::StaticClass();
	}
	struct Z_Construct_UClass_AChessBoard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rootComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_rootComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_boardMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_boardMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_arrowComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_arrowComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chessDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_chessDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_clickPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_clickPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chessPiece_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_chessPiece;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessBoard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Chess/ChessBoard.h" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_rootComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_rootComp = { "rootComp", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, rootComp), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_rootComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_rootComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_boardMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_boardMesh = { "boardMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, boardMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_boardMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_boardMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_arrowComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe6\xa3\x8b\xe7\x9b\x98\xe7\xbd\x91\xe6\xa0\xbc\xe4\xbd\x93\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
		{ "ToolTip", "\xe6\xa3\x8b\xe7\x9b\x98\xe7\xbd\x91\xe6\xa0\xbc\xe4\xbd\x93" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_arrowComp = { "arrowComp", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, arrowComp), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_arrowComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_arrowComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_chessDistance_MetaData[] = {
		{ "Category", "ChessAttrs" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_chessDistance = { "chessDistance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, chessDistance), METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_chessDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_chessDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_clickPos_MetaData[] = {
		{ "Category", "ChessAttrs" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_clickPos = { "clickPos", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, clickPos), Z_Construct_UClass_AEffectPosition_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_clickPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_clickPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessBoard_Statics::NewProp_chessPiece_MetaData[] = {
		{ "Category", "ChessAttrs" },
		{ "Comment", "//\xe5\xbc\x95\xe5\x85\xa5\xe7\x82\xb9\xe5\x87\xbb\xe6\x9c\x89\xe6\x95\x88\xe4\xbd\x8d\xe7\xbd\xae\xe7\xb1\xbb\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessBoard.h" },
		{ "ToolTip", "\xe5\xbc\x95\xe5\x85\xa5\xe7\x82\xb9\xe5\x87\xbb\xe6\x9c\x89\xe6\x95\x88\xe4\xbd\x8d\xe7\xbd\xae\xe7\xb1\xbb" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChessBoard_Statics::NewProp_chessPiece = { "chessPiece", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessBoard, chessPiece), Z_Construct_UClass_AChessPiece_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::NewProp_chessPiece_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::NewProp_chessPiece_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChessBoard_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_rootComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_boardMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_arrowComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_chessDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_clickPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessBoard_Statics::NewProp_chessPiece,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessBoard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessBoard>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChessBoard_Statics::ClassParams = {
		&AChessBoard::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AChessBoard_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChessBoard_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChessBoard_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChessBoard()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChessBoard_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChessBoard, 537544452);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChessBoard>()
	{
		return AChessBoard::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChessBoard(Z_Construct_UClass_AChessBoard, &AChessBoard::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChessBoard"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessBoard);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
