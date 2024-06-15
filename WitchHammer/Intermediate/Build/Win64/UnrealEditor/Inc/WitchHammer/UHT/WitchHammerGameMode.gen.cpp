// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WitchHammer/WitchHammerGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWitchHammerGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_WitchHammer();
	WITCHHAMMER_API UClass* Z_Construct_UClass_AWitchHammerGameMode();
	WITCHHAMMER_API UClass* Z_Construct_UClass_AWitchHammerGameMode_NoRegister();
// End Cross Module References
	void AWitchHammerGameMode::StaticRegisterNativesAWitchHammerGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWitchHammerGameMode);
	UClass* Z_Construct_UClass_AWitchHammerGameMode_NoRegister()
	{
		return AWitchHammerGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AWitchHammerGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWitchHammerGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_WitchHammer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWitchHammerGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWitchHammerGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "WitchHammerGameMode.h" },
		{ "ModuleRelativePath", "WitchHammerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWitchHammerGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWitchHammerGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWitchHammerGameMode_Statics::ClassParams = {
		&AWitchHammerGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWitchHammerGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AWitchHammerGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWitchHammerGameMode()
	{
		if (!Z_Registration_Info_UClass_AWitchHammerGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWitchHammerGameMode.OuterSingleton, Z_Construct_UClass_AWitchHammerGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWitchHammerGameMode.OuterSingleton;
	}
	template<> WITCHHAMMER_API UClass* StaticClass<AWitchHammerGameMode>()
	{
		return AWitchHammerGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWitchHammerGameMode);
	AWitchHammerGameMode::~AWitchHammerGameMode() {}
	struct Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_WitchHammerGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_WitchHammerGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWitchHammerGameMode, AWitchHammerGameMode::StaticClass, TEXT("AWitchHammerGameMode"), &Z_Registration_Info_UClass_AWitchHammerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWitchHammerGameMode), 3442835247U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_WitchHammerGameMode_h_2868092247(TEXT("/Script/WitchHammer"),
		Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_WitchHammerGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_WitchHammerGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
