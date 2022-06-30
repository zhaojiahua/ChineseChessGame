// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/Chess/ChessPiece.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessPiece() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPiece_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPiece();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
// End Cross Module References
	void AChessPiece::StaticRegisterNativesAChessPiece()
	{
	}
	UClass* Z_Construct_UClass_AChessPiece_NoRegister()
	{
		return AChessPiece::StaticClass();
	}
	struct Z_Construct_UClass_AChessPiece_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chessMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_chessMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_textComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_textComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForRedChess_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForRedChess;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForBlueChess_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForBlueChess;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForWoodDefault_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForWoodDefault;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForWoodClick_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForWoodClick;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForRoundDefault_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForRoundDefault;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_matForRoundClick_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_matForRoundClick;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessPiece_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Chess/ChessPiece.h" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_rootComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_rootComp = { "rootComp", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, rootComp), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_rootComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_rootComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_chessMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_chessMesh = { "chessMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, chessMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_chessMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_chessMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_textComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe6\xa3\x8b\xe5\xad\x90\xe7\xbd\x91\xe6\xa0\xbc\xe4\xbd\x93\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe6\xa3\x8b\xe5\xad\x90\xe7\xbd\x91\xe6\xa0\xbc\xe4\xbd\x93" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_textComp = { "textComp", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, textComp), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_textComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_textComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRedChess_MetaData[] = {
		{ "Category", "MaterailsForChessTextInfo" },
		{ "Comment", "//\xe6\x96\x87\xe5\xad\x97\xe5\xae\x9a\xe4\xbd\x8d\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe6\x96\x87\xe5\xad\x97\xe5\xae\x9a\xe4\xbd\x8d" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRedChess = { "matForRedChess", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForRedChess), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRedChess_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRedChess_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForBlueChess_MetaData[] = {
		{ "Category", "MaterailsForChessTextInfo" },
		{ "Comment", "//\xe7\xba\xa2\xe8\x89\xb2\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe7\xba\xa2\xe8\x89\xb2\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForBlueChess = { "matForBlueChess", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForBlueChess), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForBlueChess_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForBlueChess_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodDefault_MetaData[] = {
		{ "Category", "MaterailsForChessClick" },
		{ "Comment", "//\xe8\x93\x9d\xe8\x89\xb2\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe8\x93\x9d\xe8\x89\xb2\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodDefault = { "matForWoodDefault", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForWoodDefault), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodDefault_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodDefault_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodClick_MetaData[] = {
		{ "Category", "MaterailsForChessClick" },
		{ "Comment", "//wood\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "wood\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodClick = { "matForWoodClick", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForWoodClick), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodClick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodClick_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundDefault_MetaData[] = {
		{ "Category", "MaterailsForChessClick" },
		{ "Comment", "//wood\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "wood\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundDefault = { "matForRoundDefault", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForRoundDefault), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundDefault_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundDefault_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundClick_MetaData[] = {
		{ "Category", "MaterailsForChessClick" },
		{ "Comment", "//\xe8\x8a\xb1\xe8\xbe\xb9\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/Chess/ChessPiece.h" },
		{ "ToolTip", "\xe8\x8a\xb1\xe8\xbe\xb9\xe7\x9a\x84\xe9\xbb\x98\xe8\xae\xa4\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundClick = { "matForRoundClick", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPiece, matForRoundClick), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundClick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundClick_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChessPiece_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_rootComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_chessMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_textComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRedChess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForBlueChess,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodDefault,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForWoodClick,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundDefault,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPiece_Statics::NewProp_matForRoundClick,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessPiece_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessPiece>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChessPiece_Statics::ClassParams = {
		&AChessPiece::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AChessPiece_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChessPiece_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPiece_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChessPiece()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChessPiece_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChessPiece, 1220625515);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChessPiece>()
	{
		return AChessPiece::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChessPiece(Z_Construct_UClass_AChessPiece, &AChessPiece::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChessPiece"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessPiece);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
