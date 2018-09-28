// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustEvent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustEvent() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEvent();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustEvent::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustEvent_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustEvent, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustEvent"), sizeof(FAdjustEvent), Get_Z_Construct_UScriptStruct_FAdjustEvent_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustEvent(FAdjustEvent::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustEvent"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustEvent
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustEvent()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustEvent")),new UScriptStruct::TCppStructOps<FAdjustEvent>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustEvent;
	struct Z_Construct_UScriptStruct_FAdjustEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PartnerParameters_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_PartnerParameters;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PartnerParameters_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PartnerParameters_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CallbackParameters_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_CallbackParameters;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CallbackParameters_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CallbackParameters_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CallbackId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CallbackId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransactionId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TransactionId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Currency_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Currency;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Revenue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Revenue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventToken_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventToken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustEvent>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters = { UE4CodeGen_Private::EPropertyClass::Map, "PartnerParameters", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, PartnerParameters), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "PartnerParameters_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_ValueProp = { UE4CodeGen_Private::EPropertyClass::Str, "PartnerParameters", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters = { UE4CodeGen_Private::EPropertyClass::Map, "CallbackParameters", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, CallbackParameters), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "CallbackParameters_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_ValueProp = { UE4CodeGen_Private::EPropertyClass::Str, "CallbackParameters", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackId_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackId = { UE4CodeGen_Private::EPropertyClass::Str, "CallbackId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, CallbackId), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_TransactionId_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_TransactionId = { UE4CodeGen_Private::EPropertyClass::Str, "TransactionId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, TransactionId), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_TransactionId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_TransactionId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Currency_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Currency = { UE4CodeGen_Private::EPropertyClass::Str, "Currency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, Currency), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Currency_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Currency_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Revenue_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Revenue = { UE4CodeGen_Private::EPropertyClass::Float, "Revenue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, Revenue), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Revenue_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Revenue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_EventToken_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_EventToken = { UE4CodeGen_Private::EPropertyClass::Str, "EventToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustEvent, EventToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_EventToken_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_EventToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_PartnerParameters_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackParameters_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_CallbackId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_TransactionId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Currency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_Revenue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustEvent_Statics::NewProp_EventToken,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustEvent_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustEvent",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustEvent),
		alignof(FAdjustEvent),
		Z_Construct_UScriptStruct_FAdjustEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustEvent_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustEvent_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustEvent()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustEvent_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustEvent"), sizeof(FAdjustEvent), Get_Z_Construct_UScriptStruct_FAdjustEvent_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustEvent_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustEvent_CRC() { return 1031985265U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
