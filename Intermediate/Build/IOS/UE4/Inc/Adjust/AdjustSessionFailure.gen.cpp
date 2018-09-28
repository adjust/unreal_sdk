// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustSessionFailure.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustSessionFailure() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionFailure();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustSessionFailure::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionFailure_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustSessionFailure, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustSessionFailure"), sizeof(FAdjustSessionFailure), Get_Z_Construct_UScriptStruct_FAdjustSessionFailure_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustSessionFailure(FAdjustSessionFailure::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustSessionFailure"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionFailure
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionFailure()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustSessionFailure")),new UScriptStruct::TCppStructOps<FAdjustSessionFailure>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustSessionFailure;
	struct Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics
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
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustSessionFailure>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry_SetBit(void* Obj)
	{
		((FAdjustSessionFailure*)Obj)->WillRetry = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry = { UE4CodeGen_Private::EPropertyClass::Bool, "WillRetry", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FAdjustSessionFailure), &Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_JsonResponse_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_JsonResponse = { UE4CodeGen_Private::EPropertyClass::Str, "JsonResponse", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionFailure, JsonResponse), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_JsonResponse_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_JsonResponse_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Adid_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Adid = { UE4CodeGen_Private::EPropertyClass::Str, "Adid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionFailure, Adid), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Adid_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Adid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Timestamp = { UE4CodeGen_Private::EPropertyClass::Str, "Timestamp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionFailure, Timestamp), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Timestamp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Timestamp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Message_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustSessionFailure.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustSessionFailure, Message), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_WillRetry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_JsonResponse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Adid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Timestamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::NewProp_Message,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustSessionFailure",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustSessionFailure),
		alignof(FAdjustSessionFailure),
		Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionFailure()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionFailure_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustSessionFailure"), sizeof(FAdjustSessionFailure), Get_Z_Construct_UScriptStruct_FAdjustSessionFailure_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustSessionFailure_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustSessionFailure_CRC() { return 2179427879U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
