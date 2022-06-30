// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/FrameWork/ChessPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessPlayerController() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPlayerController_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessRule_NoRegister();
// End Cross Module References
	void AChessPlayerController::StaticRegisterNativesAChessPlayerController()
	{
	}
	UClass* Z_Construct_UClass_AChessPlayerController_NoRegister()
	{
		return AChessPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AChessPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsMousePressed_MetaData[];
#endif
		static void NewProp_bIsMousePressed_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsMousePressed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chessRule_BP_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_chessRule_BP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FrameWork/ChessPlayerController.h" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed_MetaData[] = {
		{ "Category", "MouseAttrs" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed_SetBit(void* Obj)
	{
		((AChessPlayerController*)Obj)->bIsMousePressed = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed = { "bIsMousePressed", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AChessPlayerController), &Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerController_Statics::NewProp_chessRule_BP_MetaData[] = {
		{ "Category", "FrameWorks" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChessPlayerController_Statics::NewProp_chessRule_BP = { "chessRule_BP", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPlayerController, chessRule_BP), Z_Construct_UClass_AChessRule_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AChessPlayerController_Statics::NewProp_chessRule_BP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerController_Statics::NewProp_chessRule_BP_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChessPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPlayerController_Statics::NewProp_bIsMousePressed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPlayerController_Statics::NewProp_chessRule_BP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChessPlayerController_Statics::ClassParams = {
		&AChessPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AChessPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChessPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChessPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChessPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChessPlayerController, 2839436002);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChessPlayerController>()
	{
		return AChessPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChessPlayerController(Z_Construct_UClass_AChessPlayerController, &AChessPlayerController::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChessPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
