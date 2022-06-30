// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/FrameWork/CheekGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCheekGameMode() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_ACheekGameMode_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_ACheekGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
// End Cross Module References
	void ACheekGameMode::StaticRegisterNativesACheekGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACheekGameMode_NoRegister()
	{
		return ACheekGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACheekGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACheekGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACheekGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FrameWork/CheekGameMode.h" },
		{ "ModuleRelativePath", "Public/FrameWork/CheekGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACheekGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACheekGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACheekGameMode_Statics::ClassParams = {
		&ACheekGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACheekGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACheekGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACheekGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACheekGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACheekGameMode, 3135764500);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<ACheekGameMode>()
	{
		return ACheekGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACheekGameMode(Z_Construct_UClass_ACheekGameMode, &ACheekGameMode::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("ACheekGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACheekGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
