// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAdjustEventFailure;
struct FAdjustEventSuccess;
struct FAdjustSessionFailure;
struct FAdjustSessionSuccess;
struct FAdjustAttribution;
#ifdef ADJUST_AdjustDelegates_generated_h
#error "AdjustDelegates.generated.h already included, missing '#pragma once' in AdjustDelegates.h"
#endif
#define ADJUST_AdjustDelegates_generated_h

#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_17_DELEGATE \
struct _Script_Adjust_eventOnDeferredDeeplinkDelegate_Parms \
{ \
	FString Deeplink; \
}; \
static inline void FOnDeferredDeeplinkDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnDeferredDeeplinkDelegate, const FString& Deeplink) \
{ \
	_Script_Adjust_eventOnDeferredDeeplinkDelegate_Parms Parms; \
	Parms.Deeplink=Deeplink; \
	OnDeferredDeeplinkDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_16_DELEGATE \
struct _Script_Adjust_eventOnEventFailureDelegate_Parms \
{ \
	FAdjustEventFailure EventFailure; \
}; \
static inline void FOnEventFailureDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnEventFailureDelegate, FAdjustEventFailure const& EventFailure) \
{ \
	_Script_Adjust_eventOnEventFailureDelegate_Parms Parms; \
	Parms.EventFailure=EventFailure; \
	OnEventFailureDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_15_DELEGATE \
struct _Script_Adjust_eventOnEventSuccessDelegate_Parms \
{ \
	FAdjustEventSuccess EventSuccess; \
}; \
static inline void FOnEventSuccessDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnEventSuccessDelegate, FAdjustEventSuccess const& EventSuccess) \
{ \
	_Script_Adjust_eventOnEventSuccessDelegate_Parms Parms; \
	Parms.EventSuccess=EventSuccess; \
	OnEventSuccessDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_14_DELEGATE \
struct _Script_Adjust_eventOnSessionFailureDelegate_Parms \
{ \
	FAdjustSessionFailure SessionFailure; \
}; \
static inline void FOnSessionFailureDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnSessionFailureDelegate, FAdjustSessionFailure const& SessionFailure) \
{ \
	_Script_Adjust_eventOnSessionFailureDelegate_Parms Parms; \
	Parms.SessionFailure=SessionFailure; \
	OnSessionFailureDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_13_DELEGATE \
struct _Script_Adjust_eventOnSessionSuccessDelegate_Parms \
{ \
	FAdjustSessionSuccess SessionSuccess; \
}; \
static inline void FOnSessionSuccessDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnSessionSuccessDelegate, FAdjustSessionSuccess const& SessionSuccess) \
{ \
	_Script_Adjust_eventOnSessionSuccessDelegate_Parms Parms; \
	Parms.SessionSuccess=SessionSuccess; \
	OnSessionSuccessDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_12_DELEGATE \
struct _Script_Adjust_eventOnAttributionChangedDelegate_Parms \
{ \
	FAdjustAttribution Attribution; \
}; \
static inline void FOnAttributionChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnAttributionChangedDelegate, FAdjustAttribution const& Attribution) \
{ \
	_Script_Adjust_eventOnAttributionChangedDelegate_Parms Parms; \
	Parms.Attribution=Attribution; \
	OnAttributionChangedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_RPC_WRAPPERS
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdjustDelegates(); \
	friend struct Z_Construct_UClass_UAdjustDelegates_Statics; \
public: \
	DECLARE_CLASS(UAdjustDelegates, USceneComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Adjust"), NO_API) \
	DECLARE_SERIALIZER(UAdjustDelegates)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUAdjustDelegates(); \
	friend struct Z_Construct_UClass_UAdjustDelegates_Statics; \
public: \
	DECLARE_CLASS(UAdjustDelegates, USceneComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Adjust"), NO_API) \
	DECLARE_SERIALIZER(UAdjustDelegates)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdjustDelegates(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdjustDelegates) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdjustDelegates); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdjustDelegates); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAdjustDelegates(UAdjustDelegates&&); \
	NO_API UAdjustDelegates(const UAdjustDelegates&); \
public:


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAdjustDelegates(UAdjustDelegates&&); \
	NO_API UAdjustDelegates(const UAdjustDelegates&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdjustDelegates); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdjustDelegates); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdjustDelegates)


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_PRIVATE_PROPERTY_OFFSET
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_19_PROLOG
#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_PRIVATE_PROPERTY_OFFSET \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_RPC_WRAPPERS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_INCLASS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_PRIVATE_PROPERTY_OFFSET \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_INCLASS_NO_PURE_DECLS \
	AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdjustExample_Plugins_Adjust_Source_Adjust_Public_AdjustDelegates_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
