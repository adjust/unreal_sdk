// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAdjustAttribution;
struct FAdjustEvent;
struct FAdjustConfig;
#ifdef ADJUST_Adjust_generated_h
#error "Adjust.generated.h already included, missing '#pragma once' in Adjust.h"
#endif
#define ADJUST_Adjust_generated_h

#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGdprForgetMe) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::GdprForgetMe(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetPartnerCallbackParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::ResetPartnerCallbackParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetSessionCallbackParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::ResetSessionCallbackParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSessionPartnerParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::RemoveSessionPartnerParameter(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSessionCallbackParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::RemoveSessionCallbackParameter(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSessionPartnerParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AddSessionPartnerParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSessionCallbackParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AddSessionCallbackParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttribution) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAdjustAttribution*)Z_Param__Result=UAdjust::GetAttribution(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAmazonAdId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetAmazonAdId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGoogleAdId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetGoogleAdId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIdfa) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetIdfa(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAdid) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetAdid(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOfflineMode) \
	{ \
		P_GET_UBOOL(Z_Param_Offline); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetOfflineMode(Z_Param_Offline); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPushToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_PushToken); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetPushToken(Z_Param_PushToken); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAppWillOpenUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AppWillOpenUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsEnabled) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAdjust::IsEnabled(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetEnabled(Z_Param_Enable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrackEvent) \
	{ \
		P_GET_STRUCT_REF(FAdjustEvent,Z_Param_Out_Event); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::TrackEvent(Z_Param_Out_Event); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_GET_STRUCT_REF(FAdjustConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::Initialize(Z_Param_Out_Config); \
		P_NATIVE_END; \
	}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGdprForgetMe) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::GdprForgetMe(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetPartnerCallbackParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::ResetPartnerCallbackParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetSessionCallbackParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::ResetSessionCallbackParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSessionPartnerParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::RemoveSessionPartnerParameter(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveSessionCallbackParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::RemoveSessionCallbackParameter(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSessionPartnerParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AddSessionPartnerParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddSessionCallbackParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AddSessionCallbackParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttribution) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FAdjustAttribution*)Z_Param__Result=UAdjust::GetAttribution(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAmazonAdId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetAmazonAdId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGoogleAdId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetGoogleAdId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIdfa) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetIdfa(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAdid) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UAdjust::GetAdid(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOfflineMode) \
	{ \
		P_GET_UBOOL(Z_Param_Offline); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetOfflineMode(Z_Param_Offline); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPushToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_PushToken); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetPushToken(Z_Param_PushToken); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAppWillOpenUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::AppWillOpenUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsEnabled) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UAdjust::IsEnabled(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::SetEnabled(Z_Param_Enable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrackEvent) \
	{ \
		P_GET_STRUCT_REF(FAdjustEvent,Z_Param_Out_Event); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::TrackEvent(Z_Param_Out_Event); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_GET_STRUCT_REF(FAdjustConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAdjust::Initialize(Z_Param_Out_Config); \
		P_NATIVE_END; \
	}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdjust(); \
	friend struct Z_Construct_UClass_UAdjust_Statics; \
public: \
	DECLARE_CLASS(UAdjust, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Adjust"), NO_API) \
	DECLARE_SERIALIZER(UAdjust)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUAdjust(); \
	friend struct Z_Construct_UClass_UAdjust_Statics; \
public: \
	DECLARE_CLASS(UAdjust, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Adjust"), NO_API) \
	DECLARE_SERIALIZER(UAdjust)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdjust(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdjust) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdjust); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdjust); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAdjust(UAdjust&&); \
	NO_API UAdjust(const UAdjust&); \
public:


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdjust(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAdjust(UAdjust&&); \
	NO_API UAdjust(const UAdjust&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdjust); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdjust); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdjust)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_PRIVATE_PROPERTY_OFFSET
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_9_PROLOG
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_PRIVATE_PROPERTY_OFFSET \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_RPC_WRAPPERS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_INCLASS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_PRIVATE_PROPERTY_OFFSET \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_INCLASS_NO_PURE_DECLS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h_12_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class Adjust."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdjustExample_Plugins_Adjust_Source_Adjust_Public_Adjust_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
