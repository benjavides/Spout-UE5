// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpoutMediaIO/Public/SpoutMediaCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpoutMediaCapture() {}

// Begin Cross Module References
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaCapture();
SPOUTMEDIAIO_API UClass* Z_Construct_UClass_USpoutMediaCapture();
SPOUTMEDIAIO_API UClass* Z_Construct_UClass_USpoutMediaCapture_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpoutMediaIO();
// End Cross Module References

// Begin Class USpoutMediaCapture
void USpoutMediaCapture::StaticRegisterNativesUSpoutMediaCapture()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpoutMediaCapture);
UClass* Z_Construct_UClass_USpoutMediaCapture_NoRegister()
{
	return USpoutMediaCapture::StaticClass();
}
struct Z_Construct_UClass_USpoutMediaCapture_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "SpoutMediaCapture.h" },
		{ "ModuleRelativePath", "Public/SpoutMediaCapture.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USpoutMediaCapture>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USpoutMediaCapture_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaCapture,
	(UObject* (*)())Z_Construct_UPackage__Script_SpoutMediaIO,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaCapture_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USpoutMediaCapture_Statics::ClassParams = {
	&USpoutMediaCapture::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaCapture_Statics::Class_MetaDataParams), Z_Construct_UClass_USpoutMediaCapture_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USpoutMediaCapture()
{
	if (!Z_Registration_Info_UClass_USpoutMediaCapture.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpoutMediaCapture.OuterSingleton, Z_Construct_UClass_USpoutMediaCapture_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USpoutMediaCapture.OuterSingleton;
}
template<> SPOUTMEDIAIO_API UClass* StaticClass<USpoutMediaCapture>()
{
	return USpoutMediaCapture::StaticClass();
}
USpoutMediaCapture::USpoutMediaCapture() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USpoutMediaCapture);
USpoutMediaCapture::~USpoutMediaCapture() {}
// End Class USpoutMediaCapture

// Begin Registration
struct Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USpoutMediaCapture, USpoutMediaCapture::StaticClass, TEXT("USpoutMediaCapture"), &Z_Registration_Info_UClass_USpoutMediaCapture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpoutMediaCapture), 1946684640U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaCapture_h_1312625636(TEXT("/Script/SpoutMediaIO"),
	Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
