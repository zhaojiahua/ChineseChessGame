// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/FrameWork/ChessPlayerState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessPlayerState() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPlayerState_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessPlayerState();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void AChessPlayerState::StaticRegisterNativesAChessPlayerState()
	{
	}
	UClass* Z_Construct_UClass_AChessPlayerState_NoRegister()
	{
		return AChessPlayerState::StaticClass();
	}
	struct Z_Construct_UClass_AChessPlayerState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ARMSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ARMSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MouseStyle_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_MouseStyle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessPlayerState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerState,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerState_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FrameWork/ChessPlayerState.h" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerState_Statics::NewProp_ARMSpeed_MetaData[] = {
		{ "Category", "MouseAttrs" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChessPlayerState_Statics::NewProp_ARMSpeed = { "ARMSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPlayerState, ARMSpeed), METADATA_PARAMS(Z_Construct_UClass_AChessPlayerState_Statics::NewProp_ARMSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerState_Statics::NewProp_ARMSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessPlayerState_Statics::NewProp_MouseStyle_MetaData[] = {
		{ "Category", "MouseAttrs" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChessPlayerState_Statics::NewProp_MouseStyle = { "MouseStyle", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChessPlayerState, MouseStyle), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AChessPlayerState_Statics::NewProp_MouseStyle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerState_Statics::NewProp_MouseStyle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChessPlayerState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPlayerState_Statics::NewProp_ARMSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChessPlayerState_Statics::NewProp_MouseStyle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessPlayerState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessPlayerState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChessPlayerState_Statics::ClassParams = {
		&AChessPlayerState::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AChessPlayerState_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerState_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChessPlayerState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChessPlayerState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChessPlayerState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChessPlayerState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChessPlayerState, 1510561725);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChessPlayerState>()
	{
		return AChessPlayerState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChessPlayerState(Z_Construct_UClass_AChessPlayerState, &AChessPlayerState::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChessPlayerState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessPlayerState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
