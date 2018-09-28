// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/Adjust.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjust() {}
// Cross Module References
	ADJUST_API UClass* Z_Construct_UClass_UAdjust_NoRegister();
	ADJUST_API UClass* Z_Construct_UClass_UAdjust();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Adjust();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_AppWillOpenUrl();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GdprForgetMe();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GetAdid();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GetAmazonAdId();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GetAttribution();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustAttribution();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GetGoogleAdId();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_GetIdfa();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_Initialize();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustConfig();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_IsEnabled();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_SetEnabled();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_SetOfflineMode();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_SetPushToken();
	ADJUST_API UFunction* Z_Construct_UFunction_UAdjust_TrackEvent();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEvent();
// End Cross Module References
	void UAdjust::StaticRegisterNativesUAdjust()
	{
		UClass* Class = UAdjust::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddSessionCallbackParameter", &UAdjust::execAddSessionCallbackParameter },
			{ "AddSessionPartnerParameter", &UAdjust::execAddSessionPartnerParameter },
			{ "AppWillOpenUrl", &UAdjust::execAppWillOpenUrl },
			{ "GdprForgetMe", &UAdjust::execGdprForgetMe },
			{ "GetAdid", &UAdjust::execGetAdid },
			{ "GetAmazonAdId", &UAdjust::execGetAmazonAdId },
			{ "GetAttribution", &UAdjust::execGetAttribution },
			{ "GetGoogleAdId", &UAdjust::execGetGoogleAdId },
			{ "GetIdfa", &UAdjust::execGetIdfa },
			{ "Initialize", &UAdjust::execInitialize },
			{ "IsEnabled", &UAdjust::execIsEnabled },
			{ "RemoveSessionCallbackParameter", &UAdjust::execRemoveSessionCallbackParameter },
			{ "RemoveSessionPartnerParameter", &UAdjust::execRemoveSessionPartnerParameter },
			{ "ResetPartnerCallbackParameters", &UAdjust::execResetPartnerCallbackParameters },
			{ "ResetSessionCallbackParameters", &UAdjust::execResetSessionCallbackParameters },
			{ "SetEnabled", &UAdjust::execSetEnabled },
			{ "SetOfflineMode", &UAdjust::execSetOfflineMode },
			{ "SetPushToken", &UAdjust::execSetPushToken },
			{ "TrackEvent", &UAdjust::execTrackEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics
	{
		struct Adjust_eventAddSessionCallbackParameter_Parms
		{
			FString Key;
			FString Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventAddSessionCallbackParameter_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Str, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventAddSessionCallbackParameter_Parms, Key), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Key_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Key_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "AddSessionCallbackParameter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventAddSessionCallbackParameter_Parms), Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics
	{
		struct Adjust_eventAddSessionPartnerParameter_Parms
		{
			FString Key;
			FString Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventAddSessionPartnerParameter_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Str, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventAddSessionPartnerParameter_Parms, Key), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Key_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Key_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "AddSessionPartnerParameter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventAddSessionPartnerParameter_Parms), Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics
	{
		struct Adjust_eventAppWillOpenUrl_Parms
		{
			FString Url;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Url_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Url;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::NewProp_Url_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::NewProp_Url = { UE4CodeGen_Private::EPropertyClass::Str, "Url", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventAppWillOpenUrl_Parms, Url), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::NewProp_Url_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::NewProp_Url_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::NewProp_Url,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "AppWillOpenUrl", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventAppWillOpenUrl_Parms), Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_AppWillOpenUrl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_AppWillOpenUrl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GdprForgetMe", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GdprForgetMe()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GdprForgetMe_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GetAdid_Statics
	{
		struct Adjust_eventGetAdid_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_GetAdid_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Adjust_eventGetAdid_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_GetAdid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_GetAdid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GetAdid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GetAdid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GetAdid", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventGetAdid_Parms), Z_Construct_UFunction_UAdjust_GetAdid_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAdid_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GetAdid_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAdid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GetAdid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GetAdid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics
	{
		struct Adjust_eventGetAmazonAdId_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Adjust_eventGetAmazonAdId_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GetAmazonAdId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventGetAmazonAdId_Parms), Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GetAmazonAdId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GetAmazonAdId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GetAttribution_Statics
	{
		struct Adjust_eventGetAttribution_Parms
		{
			FAdjustAttribution ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdjust_GetAttribution_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Adjust_eventGetAttribution_Parms, ReturnValue), Z_Construct_UScriptStruct_FAdjustAttribution, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_GetAttribution_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_GetAttribution_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GetAttribution_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GetAttribution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GetAttribution", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventGetAttribution_Parms), Z_Construct_UFunction_UAdjust_GetAttribution_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAttribution_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GetAttribution_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetAttribution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GetAttribution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GetAttribution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics
	{
		struct Adjust_eventGetGoogleAdId_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Adjust_eventGetGoogleAdId_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GetGoogleAdId", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventGetGoogleAdId_Parms), Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GetGoogleAdId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GetGoogleAdId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_GetIdfa_Statics
	{
		struct Adjust_eventGetIdfa_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_GetIdfa_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Adjust_eventGetIdfa_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_GetIdfa_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_GetIdfa_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_GetIdfa_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_GetIdfa_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "GetIdfa", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventGetIdfa_Parms), Z_Construct_UFunction_UAdjust_GetIdfa_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetIdfa_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_GetIdfa_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_GetIdfa_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_GetIdfa()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_GetIdfa_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_Initialize_Statics
	{
		struct Adjust_eventInitialize_Parms
		{
			FAdjustConfig Config;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Config;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_Initialize_Statics::NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdjust_Initialize_Statics::NewProp_Config = { UE4CodeGen_Private::EPropertyClass::Struct, "Config", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(Adjust_eventInitialize_Parms, Config), Z_Construct_UScriptStruct_FAdjustConfig, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_Initialize_Statics::NewProp_Config_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_Initialize_Statics::NewProp_Config_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_Initialize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_Initialize_Statics::NewProp_Config,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_Initialize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "Initialize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(Adjust_eventInitialize_Parms), Z_Construct_UFunction_UAdjust_Initialize_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_Initialize_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_Initialize_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_Initialize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_Initialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_Initialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_IsEnabled_Statics
	{
		struct Adjust_eventIsEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAdjust_IsEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Adjust_eventIsEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdjust_IsEnabled_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Adjust_eventIsEnabled_Parms), &Z_Construct_UFunction_UAdjust_IsEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_IsEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_IsEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_IsEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_IsEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "IsEnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventIsEnabled_Parms), Z_Construct_UFunction_UAdjust_IsEnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_IsEnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_IsEnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_IsEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_IsEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_IsEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics
	{
		struct Adjust_eventRemoveSessionCallbackParameter_Parms
		{
			FString Key;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Str, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventRemoveSessionCallbackParameter_Parms, Key), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::NewProp_Key_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::NewProp_Key_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "RemoveSessionCallbackParameter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventRemoveSessionCallbackParameter_Parms), Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics
	{
		struct Adjust_eventRemoveSessionPartnerParameter_Parms
		{
			FString Key;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Str, "Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventRemoveSessionPartnerParameter_Parms, Key), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::NewProp_Key_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::NewProp_Key_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "RemoveSessionPartnerParameter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventRemoveSessionPartnerParameter_Parms), Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "ResetPartnerCallbackParameters", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "ResetSessionCallbackParameters", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_SetEnabled_Statics
	{
		struct Adjust_eventSetEnabled_Parms
		{
			bool Enable;
		};
		static void NewProp_Enable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAdjust_SetEnabled_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((Adjust_eventSetEnabled_Parms*)Obj)->Enable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdjust_SetEnabled_Statics::NewProp_Enable = { UE4CodeGen_Private::EPropertyClass::Bool, "Enable", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Adjust_eventSetEnabled_Parms), &Z_Construct_UFunction_UAdjust_SetEnabled_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_SetEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_SetEnabled_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_SetEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_SetEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "SetEnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventSetEnabled_Parms), Z_Construct_UFunction_UAdjust_SetEnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetEnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_SetEnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_SetEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_SetEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics
	{
		struct Adjust_eventSetOfflineMode_Parms
		{
			bool Offline;
		};
		static void NewProp_Offline_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Offline;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::NewProp_Offline_SetBit(void* Obj)
	{
		((Adjust_eventSetOfflineMode_Parms*)Obj)->Offline = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::NewProp_Offline = { UE4CodeGen_Private::EPropertyClass::Bool, "Offline", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Adjust_eventSetOfflineMode_Parms), &Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::NewProp_Offline_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::NewProp_Offline,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "SetOfflineMode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventSetOfflineMode_Parms), Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_SetOfflineMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_SetOfflineMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_SetPushToken_Statics
	{
		struct Adjust_eventSetPushToken_Parms
		{
			FString PushToken;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PushToken_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PushToken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_SetPushToken_Statics::NewProp_PushToken_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdjust_SetPushToken_Statics::NewProp_PushToken = { UE4CodeGen_Private::EPropertyClass::Str, "PushToken", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Adjust_eventSetPushToken_Parms, PushToken), METADATA_PARAMS(Z_Construct_UFunction_UAdjust_SetPushToken_Statics::NewProp_PushToken_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetPushToken_Statics::NewProp_PushToken_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_SetPushToken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_SetPushToken_Statics::NewProp_PushToken,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_SetPushToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_SetPushToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "SetPushToken", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(Adjust_eventSetPushToken_Parms), Z_Construct_UFunction_UAdjust_SetPushToken_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetPushToken_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_SetPushToken_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_SetPushToken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_SetPushToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_SetPushToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAdjust_TrackEvent_Statics
	{
		struct Adjust_eventTrackEvent_Parms
		{
			FAdjustEvent Event;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Event_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Event;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_TrackEvent_Statics::NewProp_Event_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdjust_TrackEvent_Statics::NewProp_Event = { UE4CodeGen_Private::EPropertyClass::Struct, "Event", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(Adjust_eventTrackEvent_Parms, Event), Z_Construct_UScriptStruct_FAdjustEvent, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_TrackEvent_Statics::NewProp_Event_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_TrackEvent_Statics::NewProp_Event_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdjust_TrackEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdjust_TrackEvent_Statics::NewProp_Event,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdjust_TrackEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdjust_TrackEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdjust, "TrackEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(Adjust_eventTrackEvent_Parms), Z_Construct_UFunction_UAdjust_TrackEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_TrackEvent_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAdjust_TrackEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAdjust_TrackEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAdjust_TrackEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAdjust_TrackEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAdjust_NoRegister()
	{
		return UAdjust::StaticClass();
	}
	struct Z_Construct_UClass_UAdjust_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdjust_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdjust_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdjust_AddSessionCallbackParameter, "AddSessionCallbackParameter" }, // 247807710
		{ &Z_Construct_UFunction_UAdjust_AddSessionPartnerParameter, "AddSessionPartnerParameter" }, // 3468359092
		{ &Z_Construct_UFunction_UAdjust_AppWillOpenUrl, "AppWillOpenUrl" }, // 2751911967
		{ &Z_Construct_UFunction_UAdjust_GdprForgetMe, "GdprForgetMe" }, // 2795211012
		{ &Z_Construct_UFunction_UAdjust_GetAdid, "GetAdid" }, // 641650899
		{ &Z_Construct_UFunction_UAdjust_GetAmazonAdId, "GetAmazonAdId" }, // 1710595513
		{ &Z_Construct_UFunction_UAdjust_GetAttribution, "GetAttribution" }, // 4064287050
		{ &Z_Construct_UFunction_UAdjust_GetGoogleAdId, "GetGoogleAdId" }, // 1155613539
		{ &Z_Construct_UFunction_UAdjust_GetIdfa, "GetIdfa" }, // 3121445057
		{ &Z_Construct_UFunction_UAdjust_Initialize, "Initialize" }, // 3962178790
		{ &Z_Construct_UFunction_UAdjust_IsEnabled, "IsEnabled" }, // 528508668
		{ &Z_Construct_UFunction_UAdjust_RemoveSessionCallbackParameter, "RemoveSessionCallbackParameter" }, // 3051492895
		{ &Z_Construct_UFunction_UAdjust_RemoveSessionPartnerParameter, "RemoveSessionPartnerParameter" }, // 1054339051
		{ &Z_Construct_UFunction_UAdjust_ResetPartnerCallbackParameters, "ResetPartnerCallbackParameters" }, // 1110376182
		{ &Z_Construct_UFunction_UAdjust_ResetSessionCallbackParameters, "ResetSessionCallbackParameters" }, // 2434240708
		{ &Z_Construct_UFunction_UAdjust_SetEnabled, "SetEnabled" }, // 2083300789
		{ &Z_Construct_UFunction_UAdjust_SetOfflineMode, "SetOfflineMode" }, // 386760978
		{ &Z_Construct_UFunction_UAdjust_SetPushToken, "SetPushToken" }, // 1604030181
		{ &Z_Construct_UFunction_UAdjust_TrackEvent, "TrackEvent" }, // 123239381
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjust_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Adjust.h" },
		{ "ModuleRelativePath", "Public/Adjust.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdjust_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdjust>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdjust_Statics::ClassParams = {
		&UAdjust::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdjust_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdjust_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdjust()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdjust_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdjust, 3690175082);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdjust(Z_Construct_UClass_UAdjust, &UAdjust::StaticClass, TEXT("/Script/Adjust"), TEXT("UAdjust"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdjust);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
