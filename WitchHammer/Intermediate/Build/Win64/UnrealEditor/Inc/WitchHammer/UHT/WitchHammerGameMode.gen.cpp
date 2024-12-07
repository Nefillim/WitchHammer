// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WitchHammer/GameBase/WitchHammerGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWitchHammerGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_WitchHammer();
WITCHHAMMER_API UClass* Z_Construct_UClass_AWitchHammerGameMode();
WITCHHAMMER_API UClass* Z_Construct_UClass_AWitchHammerGameMode_NoRegister();
// End Cross Module References

// Begin Class AWitchHammerGameMode
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
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameBase/WitchHammerGameMode.h" },
		{ "ModuleRelativePath", "GameBase/WitchHammerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWitchHammerGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWitchHammerGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_WitchHammer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWitchHammerGameMode_Statics::DependentSingletons) < 16);
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
// End Class AWitchHammerGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_GameBase_WitchHammerGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWitchHammerGameMode, AWitchHammerGameMode::StaticClass, TEXT("AWitchHammerGameMode"), &Z_Registration_Info_UClass_AWitchHammerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWitchHammerGameMode), 797331614U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_GameBase_WitchHammerGameMode_h_2567286194(TEXT("/Script/WitchHammer"),
	Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_GameBase_WitchHammerGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_work_WitchHammer_WitchHammer_Source_WitchHammer_GameBase_WitchHammerGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
