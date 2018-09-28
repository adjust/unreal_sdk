// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustEventSuccess.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustEventSuccess() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventSuccess();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustEventSuccess::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustEventSuccess_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustEventSuccess, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustEventSuccess"), sizeof(FAdjustEventSuccess), Get_Z_Construct_UScriptStruct_FAdjustEventSuccess_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustEventSuccess(FAdjustEventSuccess::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustEventSuccess"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustEventSuccess
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustEventSuccess()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustEventSuccess")),new UScriptStruct::TCppStructOps<FAdjustEventSuccess>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustEventSuccess;
	struct Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustEventSuccess>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_JsonResponse_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_JsonResponse = { UE4CodeGen_Private::EPropertyClass::Str, "JsonResponse", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, JsonResponse), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_JsonResponse_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_JsonResponse_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Adid_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Adid = { UE4CodeGen_Private::EPropertyClass::Str, "Adid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, Adid), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Adid_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Adid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Timestamp = { UE4CodeGen_Private::EPropertyClass::Str, "Timestamp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, Timestamp), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Timestamp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Timestamp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Message_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, Message), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Message_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_CallbackId_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_CallbackId = { UE4CodeGen_Private::EPropertyClass::Str, "CallbackId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, CallbackId), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_CallbackId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_CallbackId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_EventToken_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEventSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_EventToken = { UE4CodeGen_Private::EPropertyClass::Str, "EventToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEventSuccess, EventToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_EventToken_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_EventToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_JsonResponse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Adid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Timestamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_Message,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_CallbackId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::NewProp_EventToken,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustEventSuccess",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustEventSuccess),
		alignof(FAdjustEventSuccess),
		Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventSuccess()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustEventSuccess_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustEventSuccess"), sizeof(FAdjustEventSuccess), Get_Z_Construct_UScriptStruct_FAdjustEventSuccess_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustEventSuccess_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustEventSuccess_CRC() { return 794895891U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
