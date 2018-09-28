// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustConfig.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustConfig() {}
// Cross Module References
	ADJUST_API UEnum* Z_Construct_UEnum_Adjust_EAdjustLogLevel();
	UPackage* Z_Construct_UPackage__Script_Adjust();
	ADJUST_API UEnum* Z_Construct_UEnum_Adjust_EAdjustEnvironment();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustConfig();
// End Cross Module References
	static UEnum* EAdjustLogLevel_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Adjust_EAdjustLogLevel, Z_Construct_UPackage__Script_Adjust(), TEXT("EAdjustLogLevel"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAdjustLogLevel(EAdjustLogLevel_StaticEnum, TEXT("/Script/Adjust"), TEXT("EAdjustLogLevel"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Adjust_EAdjustLogLevel_CRC() { return 3022824950U; }
	UEnum* Z_Construct_UEnum_Adjust_EAdjustLogLevel()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAdjustLogLevel"), 0, Get_Z_Construct_UEnum_Adjust_EAdjustLogLevel_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAdjustLogLevel::Verbose", (int64)EAdjustLogLevel::Verbose },
				{ "EAdjustLogLevel::Debug", (int64)EAdjustLogLevel::Debug },
				{ "EAdjustLogLevel::Info", (int64)EAdjustLogLevel::Info },
				{ "EAdjustLogLevel::Warn", (int64)EAdjustLogLevel::Warn },
				{ "EAdjustLogLevel::Error", (int64)EAdjustLogLevel::Error },
				{ "EAdjustLogLevel::Assert", (int64)EAdjustLogLevel::Assert },
				{ "EAdjustLogLevel::Suppress", (int64)EAdjustLogLevel::Suppress },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/AdjustConfig.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Adjust,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EAdjustLogLevel",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EAdjustLogLevel",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EAdjustEnvironment_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Adjust_EAdjustEnvironment, Z_Construct_UPackage__Script_Adjust(), TEXT("EAdjustEnvironment"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAdjustEnvironment(EAdjustEnvironment_StaticEnum, TEXT("/Script/Adjust"), TEXT("EAdjustEnvironment"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Adjust_EAdjustEnvironment_CRC() { return 1434260126U; }
	UEnum* Z_Construct_UEnum_Adjust_EAdjustEnvironment()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAdjustEnvironment"), 0, Get_Z_Construct_UEnum_Adjust_EAdjustEnvironment_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAdjustEnvironment::Sandbox", (int64)EAdjustEnvironment::Sandbox },
				{ "EAdjustEnvironment::Production", (int64)EAdjustEnvironment::Production },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/AdjustConfig.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Adjust,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EAdjustEnvironment",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EAdjustEnvironment",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FAdjustConfig::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustConfig_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustConfig, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustConfig"), sizeof(FAdjustConfig), Get_Z_Construct_UScriptStruct_FAdjustConfig_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustConfig(FAdjustConfig::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustConfig"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustConfig
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustConfig()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustConfig")),new UScriptStruct::TCppStructOps<FAdjustConfig>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustConfig;
	struct Z_Construct_UScriptStruct_FAdjustConfig_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OpenDeferredDeeplink_MetaData[];
#endif
		static void NewProp_OpenDeferredDeeplink_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_OpenDeferredDeeplink;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsDeviceKnown_MetaData[];
#endif
		static void NewProp_IsDeviceKnown_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsDeviceKnown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SendInBackground_MetaData[];
#endif
		static void NewProp_SendInBackground_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SendInBackground;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventBuffering_MetaData[];
#endif
		static void NewProp_EventBuffering_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EventBuffering;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Info4_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Info4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Info3_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Info3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Info2_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Info2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Info1_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Info1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SecretId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SecretId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelayStart_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DelayStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultTracker_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DefaultTracker;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UserAgent_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_UserAgent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LogLevel_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LogLevel;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_LogLevel_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Environment_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Environment;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Environment_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AppToken_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AppToken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustConfig>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink_SetBit(void* Obj)
	{
		((FAdjustConfig*)Obj)->OpenDeferredDeeplink = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink = { UE4CodeGen_Private::EPropertyClass::Bool, "OpenDeferredDeeplink", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustConfig), &Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown_SetBit(void* Obj)
	{
		((FAdjustConfig*)Obj)->IsDeviceKnown = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown = { UE4CodeGen_Private::EPropertyClass::Bool, "IsDeviceKnown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustConfig), &Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground_SetBit(void* Obj)
	{
		((FAdjustConfig*)Obj)->SendInBackground = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground = { UE4CodeGen_Private::EPropertyClass::Bool, "SendInBackground", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustConfig), &Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering_SetBit(void* Obj)
	{
		((FAdjustConfig*)Obj)->EventBuffering = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering = { UE4CodeGen_Private::EPropertyClass::Bool, "EventBuffering", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustConfig), &Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info4_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info4 = { UE4CodeGen_Private::EPropertyClass::Str, "Info4", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, Info4), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info4_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info3_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info3 = { UE4CodeGen_Private::EPropertyClass::Str, "Info3", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, Info3), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info3_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info2_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info2 = { UE4CodeGen_Private::EPropertyClass::Str, "Info2", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, Info2), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info2_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info1_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info1 = { UE4CodeGen_Private::EPropertyClass::Str, "Info1", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, Info1), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info1_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SecretId_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SecretId = { UE4CodeGen_Private::EPropertyClass::Str, "SecretId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, SecretId), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SecretId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SecretId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DelayStart_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DelayStart = { UE4CodeGen_Private::EPropertyClass::Str, "DelayStart", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, DelayStart), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DelayStart_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DelayStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DefaultTracker_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DefaultTracker = { UE4CodeGen_Private::EPropertyClass::Str, "DefaultTracker", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, DefaultTracker), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DefaultTracker_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DefaultTracker_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_UserAgent_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_UserAgent = { UE4CodeGen_Private::EPropertyClass::Str, "UserAgent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, UserAgent), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_UserAgent_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_UserAgent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel = { UE4CodeGen_Private::EPropertyClass::Enum, "LogLevel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, LogLevel), Z_Construct_UEnum_Adjust_EAdjustLogLevel, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment = { UE4CodeGen_Private::EPropertyClass::Enum, "Environment", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, Environment), Z_Construct_UEnum_Adjust_EAdjustEnvironment, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_AppToken_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustConfig.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_AppToken = { UE4CodeGen_Private::EPropertyClass::Str, "AppToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustConfig, AppToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_AppToken_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_AppToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustConfig_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_OpenDeferredDeeplink,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_IsDeviceKnown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SendInBackground,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_EventBuffering,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Info1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_SecretId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DelayStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_DefaultTracker,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_UserAgent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_LogLevel_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_Environment_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustConfig_Statics::NewProp_AppToken,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustConfig_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustConfig",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustConfig),
		alignof(FAdjustConfig),
		Z_Construct_UScriptStruct_FAdjustConfig_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustConfig_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustConfig_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustConfig()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustConfig_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustConfig"), sizeof(FAdjustConfig), Get_Z_Construct_UScriptStruct_FAdjustConfig_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustConfig_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustConfig_CRC() { return 3438860206U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
