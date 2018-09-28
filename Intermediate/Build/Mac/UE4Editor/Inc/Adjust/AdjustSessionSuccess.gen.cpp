// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustSessionSuccess.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustSessionSuccess() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionSuccess();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustSessionSuccess::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionSuccess_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustSessionSuccess, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustSessionSuccess"), sizeof(FAdjustSessionSuccess), Get_Z_Construct_UScriptStruct_FAdjustSessionSuccess_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustSessionSuccess(FAdjustSessionSuccess::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustSessionSuccess"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionSuccess
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionSuccess()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustSessionSuccess")),new UScriptStruct::TCppStructOps<FAdjustSessionSuccess>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionSuccess;
	struct Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics
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
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustSessionSuccess.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustSessionSuccess>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_JsonResponse_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_JsonResponse = { UE4CodeGen_Private::EPropertyClass::Str, "JsonResponse", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionSuccess, JsonResponse), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_JsonResponse_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_JsonResponse_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Adid_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Adid = { UE4CodeGen_Private::EPropertyClass::Str, "Adid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionSuccess, Adid), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Adid_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Adid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Timestamp = { UE4CodeGen_Private::EPropertyClass::Str, "Timestamp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionSuccess, Timestamp), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Timestamp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Timestamp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Message_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionSuccess.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionSuccess, Message), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_JsonResponse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Adid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Timestamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::NewProp_Message,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustSessionSuccess",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustSessionSuccess),
		alignof(FAdjustSessionSuccess),
		Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionSuccess()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionSuccess_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustSessionSuccess"), sizeof(FAdjustSessionSuccess), Get_Z_Construct_UScriptStruct_FAdjustSessionSuccess_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustSessionSuccess_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionSuccess_CRC() { return 656824399U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
