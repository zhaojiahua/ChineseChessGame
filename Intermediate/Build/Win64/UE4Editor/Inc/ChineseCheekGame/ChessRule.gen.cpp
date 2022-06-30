// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/FrameWork/ChessRule.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessRule() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessRule_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChessRule();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
// End Cross Module References
	void AChessRule::StaticRegisterNativesAChessRule()
	{
	}
	UClass* Z_Construct_UClass_AChessRule_NoRegister()
	{
		return AChessRule::StaticClass();
	}
	struct Z_Construct_UClass_AChessRule_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessRule_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessRule_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FrameWork/ChessRule.h" },
		{ "ModuleRelativePath", "Public/FrameWork/ChessRule.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessRule_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessRule>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChessRule_Statics::ClassParams = {
		&AChessRule::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChessRule_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChessRule_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChessRule()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChessRule_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChessRule, 1527821749);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChessRule>()
	{
		return AChessRule::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChessRule(Z_Construct_UClass_AChessRule, &AChessRule::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChessRule"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessRule);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
