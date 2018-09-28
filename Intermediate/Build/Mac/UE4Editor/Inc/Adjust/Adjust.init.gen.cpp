// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdjust_init() {}
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature();
	ADJUST_API UFunction* Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_Adjust()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnAttributionChangedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnSessionSuccessDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnSessionFailureDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnEventSuccessDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnEventFailureDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Adjust_OnDeferredDeeplinkDelegate__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/Adjust",
				PKG_CompiledIn | 0x00000000,
				0x687130D6,
				0x28B8F398,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
