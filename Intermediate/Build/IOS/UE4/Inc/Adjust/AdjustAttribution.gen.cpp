// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustAttribution.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustAttribution() {}
// Cross Module References
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustAttribution();
	UPackage* Z_Construct_UPackage__Script_Adjust();
// End Cross Module References
class UScriptStruct* FAdjustAttribution::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ADJUST_API uint32 Get_Z_Construct_UScriptStruct_FAdjustAttribution_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdjustAttribution, Z_Construct_UPackage__Script_Adjust(), TEXT("AdjustAttribution"), sizeof(FAdjustAttribution), Get_Z_Construct_UScriptStruct_FAdjustAttribution_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAdjustAttribution(FAdjustAttribution::StaticStruct, TEXT("/Script/Adjust"), TEXT("AdjustAttribution"), false, nullptr, nullptr);
static struct FScriptStruct_Adjust_StaticRegisterNativesFAdjustAttribution
{
	FScriptStruct_Adjust_StaticRegisterNativesFAdjustAttribution()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AdjustAttribution")),new UScriptStruct::TCppStructOps<FAdjustAttribution>);
	}
} ScriptStruct_Adjust_StaticRegisterNativesFAdjustAttribution;
	struct Z_Construct_UScriptStruct_FAdjustAttribution_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Adid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Adid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClickLabel_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ClickLabel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Creative_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Creative;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Adgroup_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Adgroup;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Campaign_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Campaign;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Network_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Network;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrackerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TrackerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrackerToken_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TrackerToken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdjustAttribution>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adid_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adid = { UE4CodeGen_Private::EPropertyClass::Str, "Adid", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, Adid), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adid_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_ClickLabel_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_ClickLabel = { UE4CodeGen_Private::EPropertyClass::Str, "ClickLabel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, ClickLabel), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_ClickLabel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_ClickLabel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Creative_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Creative = { UE4CodeGen_Private::EPropertyClass::Str, "Creative", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, Creative), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Creative_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Creative_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adgroup_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adgroup = { UE4CodeGen_Private::EPropertyClass::Str, "Adgroup", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, Adgroup), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adgroup_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adgroup_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Campaign_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Campaign = { UE4CodeGen_Private::EPropertyClass::Str, "Campaign", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, Campaign), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Campaign_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Campaign_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Network_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Network = { UE4CodeGen_Private::EPropertyClass::Str, "Network", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, Network), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Network_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Network_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerName_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerName = { UE4CodeGen_Private::EPropertyClass::Str, "TrackerName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, TrackerName), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerName_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerToken_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustAttribution.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerToken = { UE4CodeGen_Private::EPropertyClass::Str, "TrackerToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FAdjustAttribution, TrackerToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerToken_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdjustAttribution_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_ClickLabel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Creative,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Adgroup,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Campaign,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_Network,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdjustAttribution_Statics::NewProp_TrackerToken,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdjustAttribution_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
		nullptr,
		&NewStructOps,
		"AdjustAttribution",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FAdjustAttribution),
		alignof(FAdjustAttribution),
		Z_Construct_UScriptStruct_FAdjustAttribution_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FAdjustAttribution_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAdjustAttribution()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAdjustAttribution_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Adjust();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AdjustAttribution"), sizeof(FAdjustAttribution), Get_Z_Construct_UScriptStruct_FAdjustAttribution_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAdjustAttribution_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAdjustAttribution_CRC() { return 1966160234U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
