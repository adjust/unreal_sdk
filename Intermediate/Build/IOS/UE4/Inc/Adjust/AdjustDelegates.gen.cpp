// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Adjust/Public/AdjustDelegates.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjustDelegates() {}
// Cross Module References
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_Adjust();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventFailure();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustEventSuccess();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionFailure();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustSessionSuccess();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature();
	ADJUST_API UScriptStruct* Z_Construct_UScriptStruct_FAdjustAttribution();
	ADJUST_API UClass* Z_Construct_UClass_UAdjustDelegates_NoRegister();
	ADJUST_API UClass* Z_Construct_UClass_UAdjustDelegates();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnDeferredDeeplinkDelegate_Parms
		{
			FString Deeplink;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Deeplink_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Deeplink;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::NewProp_Deeplink_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::NewProp_Deeplink = { UE4CodeGen_Private::EPropertyClass::Str, "Deeplink", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnDeferredDeeplinkDelegate_Parms, Deeplink), METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::NewProp_Deeplink_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::NewProp_Deeplink_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::NewProp_Deeplink,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnDeferredDeeplinkDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnDeferredDeeplinkDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnEventFailureDelegate_Parms
		{
			FAdjustEventFailure EventFailure;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventFailure_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EventFailure;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::NewProp_EventFailure_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::NewProp_EventFailure = { UE4CodeGen_Private::EPropertyClass::Struct, "EventFailure", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnEventFailureDelegate_Parms, EventFailure), Z_Construct_UScriptStruct_FAdjustEventFailure, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::NewProp_EventFailure_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::NewProp_EventFailure_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::NewProp_EventFailure,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnEventFailureDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnEventFailureDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnEventSuccessDelegate_Parms
		{
			FAdjustEventSuccess EventSuccess;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventSuccess_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EventSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::NewProp_EventSuccess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::NewProp_EventSuccess = { UE4CodeGen_Private::EPropertyClass::Struct, "EventSuccess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnEventSuccessDelegate_Parms, EventSuccess), Z_Construct_UScriptStruct_FAdjustEventSuccess, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::NewProp_EventSuccess_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::NewProp_EventSuccess_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::NewProp_EventSuccess,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnEventSuccessDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnEventSuccessDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnSessionFailureDelegate_Parms
		{
			FAdjustSessionFailure SessionFailure;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SessionFailure_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SessionFailure;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::NewProp_SessionFailure_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::NewProp_SessionFailure = { UE4CodeGen_Private::EPropertyClass::Struct, "SessionFailure", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnSessionFailureDelegate_Parms, SessionFailure), Z_Construct_UScriptStruct_FAdjustSessionFailure, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::NewProp_SessionFailure_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::NewProp_SessionFailure_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::NewProp_SessionFailure,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnSessionFailureDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnSessionFailureDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnSessionSuccessDelegate_Parms
		{
			FAdjustSessionSuccess SessionSuccess;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SessionSuccess_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SessionSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::NewProp_SessionSuccess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::NewProp_SessionSuccess = { UE4CodeGen_Private::EPropertyClass::Struct, "SessionSuccess", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnSessionSuccessDelegate_Parms, SessionSuccess), Z_Construct_UScriptStruct_FAdjustSessionSuccess, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::NewProp_SessionSuccess_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::NewProp_SessionSuccess_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::NewProp_SessionSuccess,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnSessionSuccessDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnSessionSuccessDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics
	{
		struct _Script_Adjust_eventOnAttributionChangedDelegate_Parms
		{
			FAdjustAttribution Attribution;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Attribution_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Attribution;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::NewProp_Attribution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::NewProp_Attribution = { UE4CodeGen_Private::EPropertyClass::Struct, "Attribution", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_Adjust_eventOnAttributionChangedDelegate_Parms, Attribution), Z_Construct_UScriptStruct_FAdjustAttribution, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::NewProp_Attribution_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::NewProp_Attribution_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::NewProp_Attribution,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Adjust, "OnAttributionChangedDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_Adjust_eventOnAttributionChangedDelegate_Parms), Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UAdjustDelegates::StaticRegisterNativesUAdjustDelegates()
	{
	}
	UClass* Z_Construct_UClass_UAdjustDelegates_NoRegister()
	{
		return UAdjustDelegates::StaticClass();
	}
	struct Z_Construct_UClass_UAdjustDelegates_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnDeferredDeeplinkDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDeferredDeeplinkDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnEventFailureDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEventFailureDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnEventSuccessDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEventSuccessDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSessionFailureDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionFailureDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSessionSuccessDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionSuccessDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnAttributionChangedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAttributionChangedDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdjustDelegates_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Adjust,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Adjust" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "AdjustDelegates.h" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnDeferredDeeplinkDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnDeferredDeeplinkDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnDeferredDeeplinkDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnDeferredDeeplinkDelegate), Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnDeferredDeeplinkDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnDeferredDeeplinkDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventFailureDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventFailureDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnEventFailureDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnEventFailureDelegate), Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventFailureDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventFailureDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventSuccessDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventSuccessDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnEventSuccessDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnEventSuccessDelegate), Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventSuccessDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventSuccessDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionFailureDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionFailureDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnSessionFailureDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnSessionFailureDelegate), Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionFailureDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionFailureDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionSuccessDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionSuccessDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnSessionSuccessDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnSessionSuccessDelegate), Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionSuccessDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionSuccessDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnAttributionChangedDelegate_MetaData[] = {
		{ "Category", "Adjust" },
		{ "ModuleRelativePath", "Public/AdjustDelegates.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnAttributionChangedDelegate = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnAttributionChangedDelegate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UAdjustDelegates, OnAttributionChangedDelegate), Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnAttributionChangedDelegate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnAttributionChangedDelegate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdjustDelegates_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnDeferredDeeplinkDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventFailureDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnEventSuccessDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionFailureDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnSessionSuccessDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdjustDelegates_Statics::NewProp_OnAttributionChangedDelegate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdjustDelegates_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdjustDelegates>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAdjustDelegates_Statics::ClassParams = {
		&UAdjustDelegates::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		nullptr, 0,
		Z_Construct_UClass_UAdjustDelegates_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAdjustDelegates_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAdjustDelegates_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAdjustDelegates()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAdjustDelegates_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAdjustDelegates, 3015928967);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAdjustDelegates(Z_Construct_UClass_UAdjustDelegates, &UAdjustDelegates::StaticClass, TEXT("/Script/Adjust"), TEXT("UAdjustDelegates"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdjustDelegates);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
