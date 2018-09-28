// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustEventFailure.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustEventFailure() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventFailure();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustEventFailure::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustEventFailure_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustEventFailure, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustEventFailure"), sizeof(FAdjustEventFailure), Get_Z_Construct_UScriptStruct_FAdjustEventFailure_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustEventFailure(FAdjustEventFailure::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustEventFailure"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustEventFailure
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustEventFailure()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustEventFailure")),new UScriptStruct::TCppStructOps<FAdjustEventFailure>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustEventFailure;
	struct Z_Construct_UScriptStruct_FAdjustEventFailure_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WillRetry_MetaData[];
#endif
		static void NewProp_WillRetry_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_WillRetry;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JsonResponse_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_JsonResponse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Adid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Adid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Timestamp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CallbackId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CallbackId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventToken_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventToken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustEventFailure>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry_SetBit(void* Obj)
	{
		((FAdjustEventFailure*)Obj)->WillRetry = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry = { UE4CodeGen_Private::EPropertyClass::Bool, "WillRetry", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustEventFailure), &Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_JsonResponse_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_JsonResponse = { UE4CodeGen_Private::EPropertyClass::Str, "JsonResponse", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, JsonResponse), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_JsonResponse_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_JsonResponse_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Adid_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Adid = { UE4CodeGen_Private::EPropertyClass::Str, "Adid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, Adid), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Adid_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Adid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Timestamp = { UE4CodeGen_Private::EPropertyClass::Str, "Timestamp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, Timestamp), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Timestamp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Timestamp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Message_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, Message), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Message_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_CallbackId_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_CallbackId = { UE4CodeGen_Private::EPropertyClass::Str, "CallbackId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, CallbackId), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_CallbackId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_CallbackId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_EventToken_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_EventToken = { UE4CodeGen_Private::EPropertyClass::Str, "EventToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventFailure, EventToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_EventToken_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_EventToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_WillRetry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_JsonResponse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Adid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Timestamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_Message,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_CallbackId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::NewProp_EventToken,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustEventFailure",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustEventFailure),
		alignof(FAdjustEventFailure),
		Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventFailure()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustEventFailure_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustEventFailure"), sizeof(FAdjustEventFailure), Get_Z_Construct_UScriptStruct_FAdjustEventFailure_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustEventFailure_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustEventFailure_CRC() { return 976077148U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
