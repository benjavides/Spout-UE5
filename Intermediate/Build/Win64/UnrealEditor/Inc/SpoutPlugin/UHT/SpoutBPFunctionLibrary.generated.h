// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpoutBPFunctionLibrary.h"

#ifdef SPOUTPLUGIN_SpoutBPFunctionLibrary_generated_h
#error "SpoutBPFunctionLibrary.generated.h already included, missing '#pragma once' in SpoutBPFunctionLibrary.h"
#endif
#define SPOUTPLUGIN_SpoutBPFunctionLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMaterialInstanceDynamic;
class UTexture2D;
class UTextureRenderTarget2D;
enum class ESpoutSendTextureFrom : uint8;
struct FSenderStruct;

// ********** Begin ScriptStruct FSenderStruct *****************************************************
struct Z_Construct_UScriptStruct_FSenderStruct_Statics;
#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_51_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSenderStruct_Statics; \
	SPOUTPLUGIN_API static class UScriptStruct* StaticStruct();


struct FSenderStruct;
// ********** End ScriptStruct FSenderStruct *******************************************************

// ********** Begin Class USpoutBPFunctionLibrary **************************************************
#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetMaxSenders); \
	DECLARE_FUNCTION(execCreateTextureRenderTarget2D); \
	DECLARE_FUNCTION(execSetMaxSenders); \
	DECLARE_FUNCTION(execGetSenderInfo); \
	DECLARE_FUNCTION(execSpoutInfo); \
	DECLARE_FUNCTION(execSpoutReceiver); \
	DECLARE_FUNCTION(execCloseSender); \
	DECLARE_FUNCTION(execSpoutSender);


struct Z_Construct_UClass_USpoutBPFunctionLibrary_Statics;
SPOUTPLUGIN_API UClass* Z_Construct_UClass_USpoutBPFunctionLibrary_NoRegister();

#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSpoutBPFunctionLibrary(); \
	friend struct ::Z_Construct_UClass_USpoutBPFunctionLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SPOUTPLUGIN_API UClass* ::Z_Construct_UClass_USpoutBPFunctionLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(USpoutBPFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SpoutPlugin"), Z_Construct_UClass_USpoutBPFunctionLibrary_NoRegister) \
	DECLARE_SERIALIZER(USpoutBPFunctionLibrary)


#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USpoutBPFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USpoutBPFunctionLibrary(USpoutBPFunctionLibrary&&) = delete; \
	USpoutBPFunctionLibrary(const USpoutBPFunctionLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USpoutBPFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpoutBPFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpoutBPFunctionLibrary) \
	NO_API virtual ~USpoutBPFunctionLibrary();


#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_95_PROLOG
#define FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_INCLASS_NO_PURE_DECLS \
	FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h_98_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USpoutBPFunctionLibrary;

// ********** End Class USpoutBPFunctionLibrary ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Experiments_55_Plugins_SpoutPlugin_Source_SpoutPlugin_Public_SpoutBPFunctionLibrary_h

// ********** Begin Enum ESpoutType ****************************************************************
#define FOREACH_ENUM_ESPOUTTYPE(op) \
	op(ESpoutType::Sender) \
	op(ESpoutType::Receiver) 

enum class ESpoutType : uint8;
template<> struct TIsUEnumClass<ESpoutType> { enum { Value = true }; };
template<> SPOUTPLUGIN_NON_ATTRIBUTED_API UEnum* StaticEnum<ESpoutType>();
// ********** End Enum ESpoutType ******************************************************************

// ********** Begin Enum ESpoutState ***************************************************************
#define FOREACH_ENUM_ESPOUTSTATE(op) \
	op(ESpoutState::ExistsRegistered) \
	op(ESpoutState::ExistsNotRegistered) \
	op(ESpoutState::NotExistsRegistered) \
	op(ESpoutState::NotExistsNotRegistered) 

enum class ESpoutState : uint8;
template<> struct TIsUEnumClass<ESpoutState> { enum { Value = true }; };
template<> SPOUTPLUGIN_NON_ATTRIBUTED_API UEnum* StaticEnum<ESpoutState>();
// ********** End Enum ESpoutState *****************************************************************

// ********** Begin Enum ESpoutSendTextureFrom *****************************************************
#define FOREACH_ENUM_ESPOUTSENDTEXTUREFROM(op) \
	op(ESpoutSendTextureFrom::GameViewport) \
	op(ESpoutSendTextureFrom::TextureRenderTarget2D) 

enum class ESpoutSendTextureFrom : uint8;
template<> struct TIsUEnumClass<ESpoutSendTextureFrom> { enum { Value = true }; };
template<> SPOUTPLUGIN_NON_ATTRIBUTED_API UEnum* StaticEnum<ESpoutSendTextureFrom>();
// ********** End Enum ESpoutSendTextureFrom *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
