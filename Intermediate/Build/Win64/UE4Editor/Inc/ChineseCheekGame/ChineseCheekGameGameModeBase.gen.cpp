// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/ChineseCheekGameGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChineseCheekGameGameModeBase() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChineseCheekGameGameModeBase_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AChineseCheekGameGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
// End Cross Module References
	void AChineseCheekGameGameModeBase::StaticRegisterNativesAChineseCheekGameGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AChineseCheekGameGameModeBase_NoRegister()
	{
		return AChineseCheekGameGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ChineseCheekGameGameModeBase.h" },
		{ "ModuleRelativePath", "ChineseCheekGameGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChineseCheekGameGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::ClassParams = {
		&AChineseCheekGameGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChineseCheekGameGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChineseCheekGameGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChineseCheekGameGameModeBase, 2491457980);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AChineseCheekGameGameModeBase>()
	{
		return AChineseCheekGameGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChineseCheekGameGameModeBase(Z_Construct_UClass_AChineseCheekGameGameModeBase, &AChineseCheekGameGameModeBase::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AChineseCheekGameGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChineseCheekGameGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
