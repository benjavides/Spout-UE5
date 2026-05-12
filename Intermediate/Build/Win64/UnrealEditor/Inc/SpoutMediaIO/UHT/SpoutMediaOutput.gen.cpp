// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpoutMediaIO/Public/SpoutMediaOutput.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpoutMediaOutput() {}

// Begin Cross Module References
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_EPixelFormat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaOutput();
SPOUTMEDIAIO_API UClass* Z_Construct_UClass_USpoutMediaOutput();
SPOUTMEDIAIO_API UClass* Z_Construct_UClass_USpoutMediaOutput_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpoutMediaIO();
// End Cross Module References

// Begin Class USpoutMediaOutput
void USpoutMediaOutput::StaticRegisterNativesUSpoutMediaOutput()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpoutMediaOutput);
UClass* Z_Construct_UClass_USpoutMediaOutput_NoRegister()
{
	return USpoutMediaOutput::StaticClass();
}
struct Z_Construct_UClass_USpoutMediaOutput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SpoutMediaOutput.h" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpoutName_MetaData[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAppendNodeAndViewport_MetaData[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportId_MetaData[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Used by direct nDisplay callback fallback path when MediaCapture callbacks are not dispatched.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used by direct nDisplay callback fallback path when MediaCapture callbacks are not dispatched." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputSize_MetaData[] = {
		{ "Category", "Capture" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputPixelFormat_MetaData[] = {
		{ "Category", "Capture" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInvertAlpha_MetaData[] = {
		{ "Category", "Capture" },
		{ "ModuleRelativePath", "Public/SpoutMediaOutput.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SpoutName;
	static void NewProp_bAppendNodeAndViewport_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAppendNodeAndViewport;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ViewportId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputSize;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutputPixelFormat;
	static void NewProp_bInvertAlpha_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInvertAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USpoutMediaOutput>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_SpoutName = { "SpoutName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpoutMediaOutput, SpoutName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpoutName_MetaData), NewProp_SpoutName_MetaData) };
void Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bAppendNodeAndViewport_SetBit(void* Obj)
{
	((USpoutMediaOutput*)Obj)->bAppendNodeAndViewport = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bAppendNodeAndViewport = { "bAppendNodeAndViewport", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USpoutMediaOutput), &Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bAppendNodeAndViewport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAppendNodeAndViewport_MetaData), NewProp_bAppendNodeAndViewport_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_ViewportId = { "ViewportId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpoutMediaOutput, ViewportId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportId_MetaData), NewProp_ViewportId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_OutputSize = { "OutputSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpoutMediaOutput, OutputSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputSize_MetaData), NewProp_OutputSize_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_OutputPixelFormat = { "OutputPixelFormat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpoutMediaOutput, OutputPixelFormat), Z_Construct_UEnum_CoreUObject_EPixelFormat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputPixelFormat_MetaData), NewProp_OutputPixelFormat_MetaData) }; // 2051073252
void Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bInvertAlpha_SetBit(void* Obj)
{
	((USpoutMediaOutput*)Obj)->bInvertAlpha = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bInvertAlpha = { "bInvertAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USpoutMediaOutput), &Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bInvertAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInvertAlpha_MetaData), NewProp_bInvertAlpha_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USpoutMediaOutput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_SpoutName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bAppendNodeAndViewport,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_ViewportId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_OutputSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_OutputPixelFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpoutMediaOutput_Statics::NewProp_bInvertAlpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaOutput_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USpoutMediaOutput_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaOutput,
	(UObject* (*)())Z_Construct_UPackage__Script_SpoutMediaIO,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaOutput_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USpoutMediaOutput_Statics::ClassParams = {
	&USpoutMediaOutput::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USpoutMediaOutput_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaOutput_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutMediaOutput_Statics::Class_MetaDataParams), Z_Construct_UClass_USpoutMediaOutput_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USpoutMediaOutput()
{
	if (!Z_Registration_Info_UClass_USpoutMediaOutput.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpoutMediaOutput.OuterSingleton, Z_Construct_UClass_USpoutMediaOutput_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USpoutMediaOutput.OuterSingleton;
}
template<> SPOUTMEDIAIO_API UClass* StaticClass<USpoutMediaOutput>()
{
	return USpoutMediaOutput::StaticClass();
}
USpoutMediaOutput::USpoutMediaOutput(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USpoutMediaOutput);
USpoutMediaOutput::~USpoutMediaOutput() {}
// End Class USpoutMediaOutput

// Begin Registration
struct Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaOutput_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USpoutMediaOutput, USpoutMediaOutput::StaticClass, TEXT("USpoutMediaOutput"), &Z_Registration_Info_UClass_USpoutMediaOutput, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpoutMediaOutput), 1365863396U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaOutput_h_3266091566(TEXT("/Script/SpoutMediaIO"),
	Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaOutput_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutMediaIO_Public_SpoutMediaOutput_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
