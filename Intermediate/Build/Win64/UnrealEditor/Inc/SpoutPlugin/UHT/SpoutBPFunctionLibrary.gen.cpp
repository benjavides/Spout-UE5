// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpoutPlugin/Public/SpoutBPFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Public/Materials/MaterialInstanceDynamic.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpoutBPFunctionLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_EPixelFormat();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
SPOUTPLUGIN_API UClass* Z_Construct_UClass_USpoutBPFunctionLibrary();
SPOUTPLUGIN_API UClass* Z_Construct_UClass_USpoutBPFunctionLibrary_NoRegister();
SPOUTPLUGIN_API UEnum* Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom();
SPOUTPLUGIN_API UEnum* Z_Construct_UEnum_SpoutPlugin_ESpoutType();
SPOUTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSenderStruct();
UPackage* Z_Construct_UPackage__Script_SpoutPlugin();
// End Cross Module References

// Begin Enum ESpoutType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpoutType;
static UEnum* ESpoutType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESpoutType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESpoutType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SpoutPlugin_ESpoutType, (UObject*)Z_Construct_UPackage__Script_SpoutPlugin(), TEXT("ESpoutType"));
	}
	return Z_Registration_Info_UEnum_ESpoutType.OuterSingleton;
}
template<> SPOUTPLUGIN_API UEnum* StaticEnum<ESpoutType>()
{
	return ESpoutType_StaticEnum();
}
struct Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
		{ "Receiver.Comment", "// Consumes a shared DX texture from another Spout client.\n" },
		{ "Receiver.Name", "ESpoutType::Receiver" },
		{ "Receiver.ToolTip", "Consumes a shared DX texture from another Spout client." },
		{ "Sender.Comment", "// Publishes a shared DX texture to other Spout clients.\n" },
		{ "Sender.Name", "ESpoutType::Sender" },
		{ "Sender.ToolTip", "Publishes a shared DX texture to other Spout clients." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESpoutType::Sender", (int64)ESpoutType::Sender },
		{ "ESpoutType::Receiver", (int64)ESpoutType::Receiver },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SpoutPlugin,
	nullptr,
	"ESpoutType",
	"ESpoutType",
	Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SpoutPlugin_ESpoutType()
{
	if (!Z_Registration_Info_UEnum_ESpoutType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpoutType.InnerSingleton, Z_Construct_UEnum_SpoutPlugin_ESpoutType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESpoutType.InnerSingleton;
}
// End Enum ESpoutType

// Begin Enum ESpoutSendTextureFrom
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpoutSendTextureFrom;
static UEnum* ESpoutSendTextureFrom_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESpoutSendTextureFrom.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESpoutSendTextureFrom.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom, (UObject*)Z_Construct_UPackage__Script_SpoutPlugin(), TEXT("ESpoutSendTextureFrom"));
	}
	return Z_Registration_Info_UEnum_ESpoutSendTextureFrom.OuterSingleton;
}
template<> SPOUTPLUGIN_API UEnum* StaticEnum<ESpoutSendTextureFrom>()
{
	return ESpoutSendTextureFrom_StaticEnum();
}
struct Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "GameViewport.Comment", "// Uses the active game viewport's backbuffer texture (render thread only).\n" },
		{ "GameViewport.Name", "ESpoutSendTextureFrom::GameViewport" },
		{ "GameViewport.ToolTip", "Uses the active game viewport's backbuffer texture (render thread only)." },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
		{ "TextureRenderTarget2D.Comment", "// Uses a user-provided UTextureRenderTarget2D.\n" },
		{ "TextureRenderTarget2D.Name", "ESpoutSendTextureFrom::TextureRenderTarget2D" },
		{ "TextureRenderTarget2D.ToolTip", "Uses a user-provided UTextureRenderTarget2D." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESpoutSendTextureFrom::GameViewport", (int64)ESpoutSendTextureFrom::GameViewport },
		{ "ESpoutSendTextureFrom::TextureRenderTarget2D", (int64)ESpoutSendTextureFrom::TextureRenderTarget2D },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SpoutPlugin,
	nullptr,
	"ESpoutSendTextureFrom",
	"ESpoutSendTextureFrom",
	Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom()
{
	if (!Z_Registration_Info_UEnum_ESpoutSendTextureFrom.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpoutSendTextureFrom.InnerSingleton, Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESpoutSendTextureFrom.InnerSingleton;
}
// End Enum ESpoutSendTextureFrom

// Begin ScriptStruct FSenderStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SenderStruct;
class UScriptStruct* FSenderStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SenderStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SenderStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSenderStruct, (UObject*)Z_Construct_UPackage__Script_SpoutPlugin(), TEXT("SenderStruct"));
	}
	return Z_Registration_Info_UScriptStruct_SenderStruct.OuterSingleton;
}
template<> SPOUTPLUGIN_API UScriptStruct* StaticStruct<FSenderStruct>()
{
	return FSenderStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSenderStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Lightweight struct for Blueprint interaction.\n * Heavy D3D resources are managed internally by the CPP file.\n */" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lightweight struct for Blueprint interaction.\nHeavy D3D resources are managed internally by the CPP file." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Spout sender name used for registry lookup and external discovery.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spout sender name used for registry lookup and external discovery." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAlive_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Best-effort status flag; true means the sender was found/created at query time.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Best-effort status flag; true means the sender was found/created at query time." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpoutType_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Whether this struct represents a Sender or Receiver flow.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this struct represents a Sender or Receiver flow." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cached texture dimensions reported by Spout.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached texture dimensions reported by Spout." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "Spout Struct" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextureColor_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Transient texture owned by this plugin; updated by receiver on the render thread.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transient texture owned by this plugin; updated by receiver on the render thread." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialInstanceColor_MetaData[] = {
		{ "Category", "Spout Struct" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Optional dynamic material instance that references TextureColor.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional dynamic material instance that references TextureColor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserBaseMaterial_MetaData[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Optional base material for auto-creating MaterialInstanceColor.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional base material for auto-creating MaterialInstanceColor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserTextureParameter_MetaData[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Parameter name used to bind TextureColor in the material.\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parameter name used to bind TextureColor in the material." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputRenderTarget_MetaData[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Optional output target for receiver copy (currently unused by the plugin).\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional output target for receiver copy (currently unused by the plugin)." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static void NewProp_bIsAlive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAlive;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpoutType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpoutType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextureColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialInstanceColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UserBaseMaterial;
	static const UECodeGen_Private::FNamePropertyParams NewProp_UserTextureParameter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutputRenderTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSenderStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
void Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_bIsAlive_SetBit(void* Obj)
{
	((FSenderStruct*)Obj)->bIsAlive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_bIsAlive = { "bIsAlive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSenderStruct), &Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_bIsAlive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAlive_MetaData), NewProp_bIsAlive_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_SpoutType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_SpoutType = { "SpoutType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, SpoutType), Z_Construct_UEnum_SpoutPlugin_ESpoutType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpoutType_MetaData), NewProp_SpoutType_MetaData) }; // 3981163334
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, Width), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Width_MetaData), NewProp_Width_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_TextureColor = { "TextureColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, TextureColor), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextureColor_MetaData), NewProp_TextureColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_MaterialInstanceColor = { "MaterialInstanceColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, MaterialInstanceColor), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialInstanceColor_MetaData), NewProp_MaterialInstanceColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_UserBaseMaterial = { "UserBaseMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, UserBaseMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserBaseMaterial_MetaData), NewProp_UserBaseMaterial_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_UserTextureParameter = { "UserTextureParameter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, UserTextureParameter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserTextureParameter_MetaData), NewProp_UserTextureParameter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_OutputRenderTarget = { "OutputRenderTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSenderStruct, OutputRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputRenderTarget_MetaData), NewProp_OutputRenderTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSenderStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_bIsAlive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_SpoutType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_SpoutType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Width,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_TextureColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_MaterialInstanceColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_UserBaseMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_UserTextureParameter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSenderStruct_Statics::NewProp_OutputRenderTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSenderStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSenderStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SpoutPlugin,
	nullptr,
	&NewStructOps,
	"SenderStruct",
	Z_Construct_UScriptStruct_FSenderStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSenderStruct_Statics::PropPointers),
	sizeof(FSenderStruct),
	alignof(FSenderStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSenderStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSenderStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSenderStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SenderStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SenderStruct.InnerSingleton, Z_Construct_UScriptStruct_FSenderStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SenderStruct.InnerSingleton;
}
// End ScriptStruct FSenderStruct

// Begin Class USpoutBPFunctionLibrary Function CloseSender
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics
{
	struct SpoutBPFunctionLibrary_eventCloseSender_Parms
	{
		FName SpoutName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpoutName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::NewProp_SpoutName = { "SpoutName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventCloseSender_Parms, SpoutName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::NewProp_SpoutName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "CloseSender", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::SpoutBPFunctionLibrary_eventCloseSender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::SpoutBPFunctionLibrary_eventCloseSender_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execCloseSender)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_SpoutName);
	P_FINISH;
	P_NATIVE_BEGIN;
	USpoutBPFunctionLibrary::CloseSender(Z_Param_SpoutName);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function CloseSender

// Begin Class USpoutBPFunctionLibrary Function CreateTextureRenderTarget2D
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics
{
	struct SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms
	{
		int32 Width;
		int32 Height;
		TEnumAsByte<EPixelFormat> Format;
		bool bForceLinearGamma;
		UTextureRenderTarget2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
		{ "CPP_Default_bForceLinearGamma", "true" },
		{ "CPP_Default_Format", "PF_B8G8R8A8" },
		{ "CPP_Default_Height", "768" },
		{ "CPP_Default_Width", "1024" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Format;
	static void NewProp_bForceLinearGamma_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceLinearGamma;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms, Width), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Format = { "Format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms, Format), Z_Construct_UEnum_CoreUObject_EPixelFormat, METADATA_PARAMS(0, nullptr) }; // 2051073252
void Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_bForceLinearGamma_SetBit(void* Obj)
{
	((SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms*)Obj)->bForceLinearGamma = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_bForceLinearGamma = { "bForceLinearGamma", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms), &Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_bForceLinearGamma_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms, ReturnValue), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Width,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_Format,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_bForceLinearGamma,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "CreateTextureRenderTarget2D", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::SpoutBPFunctionLibrary_eventCreateTextureRenderTarget2D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execCreateTextureRenderTarget2D)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Width);
	P_GET_PROPERTY(FIntProperty,Z_Param_Height);
	P_GET_PROPERTY(FByteProperty,Z_Param_Format);
	P_GET_UBOOL(Z_Param_bForceLinearGamma);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTextureRenderTarget2D**)Z_Param__Result=USpoutBPFunctionLibrary::CreateTextureRenderTarget2D(Z_Param_Width,Z_Param_Height,EPixelFormat(Z_Param_Format),Z_Param_bForceLinearGamma);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function CreateTextureRenderTarget2D

// Begin Class USpoutBPFunctionLibrary Function GetMaxSenders
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics
{
	struct SpoutBPFunctionLibrary_eventGetMaxSenders_Parms
	{
		int32 Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventGetMaxSenders_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "GetMaxSenders", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::SpoutBPFunctionLibrary_eventGetMaxSenders_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::SpoutBPFunctionLibrary_eventGetMaxSenders_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execGetMaxSenders)
{
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	USpoutBPFunctionLibrary::GetMaxSenders(Z_Param_Out_Max);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function GetMaxSenders

// Begin Class USpoutBPFunctionLibrary Function GetSenderInfo
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics
{
	struct SpoutBPFunctionLibrary_eventGetSenderInfo_Parms
	{
		FName SpoutName;
		FSenderStruct OutSenderStruct;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpoutName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSenderStruct;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_SpoutName = { "SpoutName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventGetSenderInfo_Parms, SpoutName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_OutSenderStruct = { "OutSenderStruct", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventGetSenderInfo_Parms, OutSenderStruct), Z_Construct_UScriptStruct_FSenderStruct, METADATA_PARAMS(0, nullptr) }; // 545293115
void Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SpoutBPFunctionLibrary_eventGetSenderInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SpoutBPFunctionLibrary_eventGetSenderInfo_Parms), &Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_SpoutName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_OutSenderStruct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "GetSenderInfo", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::SpoutBPFunctionLibrary_eventGetSenderInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::SpoutBPFunctionLibrary_eventGetSenderInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execGetSenderInfo)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_SpoutName);
	P_GET_STRUCT_REF(FSenderStruct,Z_Param_Out_OutSenderStruct);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USpoutBPFunctionLibrary::GetSenderInfo(Z_Param_SpoutName,Z_Param_Out_OutSenderStruct);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function GetSenderInfo

// Begin Class USpoutBPFunctionLibrary Function SetMaxSenders
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics
{
	struct SpoutBPFunctionLibrary_eventSetMaxSenders_Parms
	{
		int32 Max;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSetMaxSenders_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSetMaxSenders_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::NewProp_Max,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "SetMaxSenders", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::SpoutBPFunctionLibrary_eventSetMaxSenders_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::SpoutBPFunctionLibrary_eventSetMaxSenders_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execSetMaxSenders)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=USpoutBPFunctionLibrary::SetMaxSenders(Z_Param_Max);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function SetMaxSenders

// Begin Class USpoutBPFunctionLibrary Function SpoutInfo
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics
{
	struct SpoutBPFunctionLibrary_eventSpoutInfo_Parms
	{
		TArray<FSenderStruct> Senders;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Info / Utils ---\n" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Info / Utils ---" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Senders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Senders;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_Senders_Inner = { "Senders", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSenderStruct, METADATA_PARAMS(0, nullptr) }; // 545293115
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_Senders = { "Senders", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutInfo_Parms, Senders), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 545293115
void Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SpoutBPFunctionLibrary_eventSpoutInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SpoutBPFunctionLibrary_eventSpoutInfo_Parms), &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_Senders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_Senders,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "SpoutInfo", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::SpoutBPFunctionLibrary_eventSpoutInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::SpoutBPFunctionLibrary_eventSpoutInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execSpoutInfo)
{
	P_GET_TARRAY_REF(FSenderStruct,Z_Param_Out_Senders);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USpoutBPFunctionLibrary::SpoutInfo(Z_Param_Out_Senders);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function SpoutInfo

// Begin Class USpoutBPFunctionLibrary Function SpoutReceiver
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics
{
	struct SpoutBPFunctionLibrary_eventSpoutReceiver_Parms
	{
		FName SpoutName;
		UMaterialInterface* InputMaterial;
		FName TextureParameterName;
		UMaterialInstanceDynamic* OutMat;
		UTexture2D* OutTexture;
		UTextureRenderTarget2D* OptionalOutputRenderTarget;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "5" },
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Receivers ---\n" },
#endif
		{ "CPP_Default_OptionalOutputRenderTarget", "None" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Receivers ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpoutName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpoutName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMaterial;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TextureParameterName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OptionalOutputRenderTarget;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_SpoutName = { "SpoutName", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, SpoutName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpoutName_MetaData), NewProp_SpoutName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_InputMaterial = { "InputMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, InputMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_TextureParameterName = { "TextureParameterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, TextureParameterName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OutMat = { "OutMat", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, OutMat), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OutTexture = { "OutTexture", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, OutTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OptionalOutputRenderTarget = { "OptionalOutputRenderTarget", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms, OptionalOutputRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SpoutBPFunctionLibrary_eventSpoutReceiver_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SpoutBPFunctionLibrary_eventSpoutReceiver_Parms), &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_SpoutName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_InputMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_TextureParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OutMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OutTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_OptionalOutputRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "SpoutReceiver", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::SpoutBPFunctionLibrary_eventSpoutReceiver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::SpoutBPFunctionLibrary_eventSpoutReceiver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execSpoutReceiver)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_SpoutName);
	P_GET_OBJECT(UMaterialInterface,Z_Param_InputMaterial);
	P_GET_PROPERTY(FNameProperty,Z_Param_TextureParameterName);
	P_GET_OBJECT_REF(UMaterialInstanceDynamic,Z_Param_Out_OutMat);
	P_GET_OBJECT_REF(UTexture2D,Z_Param_Out_OutTexture);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_OptionalOutputRenderTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USpoutBPFunctionLibrary::SpoutReceiver(Z_Param_SpoutName,Z_Param_InputMaterial,Z_Param_TextureParameterName,P_ARG_GC_BARRIER(Z_Param_Out_OutMat),P_ARG_GC_BARRIER(Z_Param_Out_OutTexture),Z_Param_OptionalOutputRenderTarget);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function SpoutReceiver

// Begin Class USpoutBPFunctionLibrary Function SpoutSender
struct Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics
{
	struct SpoutBPFunctionLibrary_eventSpoutSender_Parms
	{
		FName SpoutName;
		ESpoutSendTextureFrom SendTextureFrom;
		UTextureRenderTarget2D* TextureRenderTarget2D;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sends a texture to Spout asynchronously via the render thread.\n\x09 * This does NOT stall the game thread, but does perform a GPU copy on the render thread.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sends a texture to Spout asynchronously via the render thread.\nThis does NOT stall the game thread, but does perform a GPU copy on the render thread." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpoutName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SendTextureFrom_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SendTextureFrom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextureRenderTarget2D;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SpoutName = { "SpoutName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutSender_Parms, SpoutName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SendTextureFrom_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SendTextureFrom = { "SendTextureFrom", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutSender_Parms, SendTextureFrom), Z_Construct_UEnum_SpoutPlugin_ESpoutSendTextureFrom, METADATA_PARAMS(0, nullptr) }; // 2873567281
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_TextureRenderTarget2D = { "TextureRenderTarget2D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpoutBPFunctionLibrary_eventSpoutSender_Parms, TextureRenderTarget2D), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SpoutBPFunctionLibrary_eventSpoutSender_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SpoutBPFunctionLibrary_eventSpoutSender_Parms), &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SpoutName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SendTextureFrom_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_SendTextureFrom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_TextureRenderTarget2D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpoutBPFunctionLibrary, nullptr, "SpoutSender", nullptr, nullptr, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::SpoutBPFunctionLibrary_eventSpoutSender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::SpoutBPFunctionLibrary_eventSpoutSender_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpoutBPFunctionLibrary::execSpoutSender)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_SpoutName);
	P_GET_ENUM(ESpoutSendTextureFrom,Z_Param_SendTextureFrom);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_TextureRenderTarget2D);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USpoutBPFunctionLibrary::SpoutSender(Z_Param_SpoutName,ESpoutSendTextureFrom(Z_Param_SendTextureFrom),Z_Param_TextureRenderTarget2D);
	P_NATIVE_END;
}
// End Class USpoutBPFunctionLibrary Function SpoutSender

// Begin Class USpoutBPFunctionLibrary
void USpoutBPFunctionLibrary::StaticRegisterNativesUSpoutBPFunctionLibrary()
{
	UClass* Class = USpoutBPFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CloseSender", &USpoutBPFunctionLibrary::execCloseSender },
		{ "CreateTextureRenderTarget2D", &USpoutBPFunctionLibrary::execCreateTextureRenderTarget2D },
		{ "GetMaxSenders", &USpoutBPFunctionLibrary::execGetMaxSenders },
		{ "GetSenderInfo", &USpoutBPFunctionLibrary::execGetSenderInfo },
		{ "SetMaxSenders", &USpoutBPFunctionLibrary::execSetMaxSenders },
		{ "SpoutInfo", &USpoutBPFunctionLibrary::execSpoutInfo },
		{ "SpoutReceiver", &USpoutBPFunctionLibrary::execSpoutReceiver },
		{ "SpoutSender", &USpoutBPFunctionLibrary::execSpoutSender },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpoutBPFunctionLibrary);
UClass* Z_Construct_UClass_USpoutBPFunctionLibrary_NoRegister()
{
	return USpoutBPFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_USpoutBPFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Spout" },
		{ "IncludePath", "SpoutBPFunctionLibrary.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SpoutBPFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_CloseSender, "CloseSender" }, // 120151596
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_CreateTextureRenderTarget2D, "CreateTextureRenderTarget2D" }, // 3503458951
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_GetMaxSenders, "GetMaxSenders" }, // 954338033
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_GetSenderInfo, "GetSenderInfo" }, // 3175067769
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_SetMaxSenders, "SetMaxSenders" }, // 270679674
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutInfo, "SpoutInfo" }, // 1683882596
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutReceiver, "SpoutReceiver" }, // 1951518958
		{ &Z_Construct_UFunction_USpoutBPFunctionLibrary_SpoutSender, "SpoutSender" }, // 791584160
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USpoutBPFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_SpoutPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::ClassParams = {
	&USpoutBPFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USpoutBPFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_USpoutBPFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpoutBPFunctionLibrary.OuterSingleton, Z_Construct_UClass_USpoutBPFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USpoutBPFunctionLibrary.OuterSingleton;
}
template<> SPOUTPLUGIN_API UClass* StaticClass<USpoutBPFunctionLibrary>()
{
	return USpoutBPFunctionLibrary::StaticClass();
}
USpoutBPFunctionLibrary::USpoutBPFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USpoutBPFunctionLibrary);
USpoutBPFunctionLibrary::~USpoutBPFunctionLibrary() {}
// End Class USpoutBPFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESpoutType_StaticEnum, TEXT("ESpoutType"), &Z_Registration_Info_UEnum_ESpoutType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3981163334U) },
		{ ESpoutSendTextureFrom_StaticEnum, TEXT("ESpoutSendTextureFrom"), &Z_Registration_Info_UEnum_ESpoutSendTextureFrom, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2873567281U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSenderStruct::StaticStruct, Z_Construct_UScriptStruct_FSenderStruct_Statics::NewStructOps, TEXT("SenderStruct"), &Z_Registration_Info_UScriptStruct_SenderStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSenderStruct), 545293115U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USpoutBPFunctionLibrary, USpoutBPFunctionLibrary::StaticClass, TEXT("USpoutBPFunctionLibrary"), &Z_Registration_Info_UClass_USpoutBPFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpoutBPFunctionLibrary), 170571690U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_424001592(TEXT("/Script/SpoutPlugin"),
	Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_pinta_tu_mic_Plugins_Spout_UE5_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
