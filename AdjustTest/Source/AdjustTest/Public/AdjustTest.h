//
//  AdjustTest.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdjustTest.generated.h"

UCLASS()
class ADJUSTTEST_API UAdjustTest : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, Category = "AdjustTest")
    static void StartTestSession(const FString& BaseUrl, const FString& ControlUrl, const FString& ClientSdk);

    UFUNCTION(BlueprintCallable, Category = "AdjustTest")
    static void AddTest(const FString& TestName);

    UFUNCTION(BlueprintCallable, Category = "AdjustTest")
    static void AddTestDirectory(const FString& TestDirectory);

    UFUNCTION(BlueprintCallable, Category = "AdjustTest")
    static void AddInfoToSend(const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable, Category = "AdjustTest")
    static void SendInfoToServer(const FString& BasePath);
};
