// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChineseCheekGame/Public/Chess/EffectPosition.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEffectPosition() {}
// Cross Module References
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AEffectPosition_NoRegister();
	CHINESECHEEKGAME_API UClass* Z_Construct_UClass_AEffectPosition();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ChineseCheekGame();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AEffectPosition::StaticRegisterNativesAEffectPosition()
	{
	}
	UClass* Z_Construct_UClass_AEffectPosition_NoRegister()
	{
		return AEffectPosition::StaticClass();
	}
	struct Z_Construct_UClass_AEffectPosition_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_moveMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_moveMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_eatMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_eatMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEffectPosition_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChineseCheekGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEffectPosition_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Chess/EffectPosition.h" },
		{ "ModuleRelativePath", "Public/Chess/EffectPosition.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEffectPosition_Statics::NewProp_rootComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/EffectPosition.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEffectPosition_Statics::NewProp_rootComp = { "rootComp", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEffectPosition, rootComp), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEffectPosition_Statics::NewProp_rootComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEffectPosition_Statics::NewProp_rootComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEffectPosition_Statics::NewProp_moveMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/EffectPosition.h" },
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe6\xa0\xb9\xe7\xbb\x84\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEffectPosition_Statics::NewProp_moveMesh = { "moveMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEffectPosition, moveMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEffectPosition_Statics::NewProp_moveMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEffectPosition_Statics::NewProp_moveMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEffectPosition_Statics::NewProp_eatMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "Comment", "//\xe5\x8f\xaf\xe7\xa7\xbb\xe5\x8a\xa8\xe7\xbd\x91\xe6\xa0\xbc\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chess/EffectPosition.h" },
		{ "ToolTip", "\xe5\x8f\xaf\xe7\xa7\xbb\xe5\x8a\xa8\xe7\xbd\x91\xe6\xa0\xbc" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEffectPosition_Statics::NewProp_eatMesh = { "eatMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEffectPosition, eatMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEffectPosition_Statics::NewProp_eatMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEffectPosition_Statics::NewProp_eatMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEffectPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEffectPosition_Statics::NewProp_rootComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEffectPosition_Statics::NewProp_moveMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEffectPosition_Statics::NewProp_eatMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEffectPosition_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEffectPosition>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEffectPosition_Statics::ClassParams = {
		&AEffectPosition::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEffectPosition_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEffectPosition_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEffectPosition_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEffectPosition_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEffectPosition()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEffectPosition_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEffectPosition, 338037287);
	template<> CHINESECHEEKGAME_API UClass* StaticClass<AEffectPosition>()
	{
		return AEffectPosition::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEffectPosition(Z_Construct_UClass_AEffectPosition, &AEffectPosition::StaticClass, TEXT("/Script/ChineseCheekGame"), TEXT("AEffectPosition"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEffectPosition);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
