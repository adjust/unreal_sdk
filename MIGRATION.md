# Unreal SDK v5 migration guide

The [Adjust Unreal SDK](https://github.com/adjust/unreal_sdk) has been updated to v5. Follow this guide to migrate from v4 to the latest version.

## Before you begin

The Adjust SDK v4 was compatible with Unreal Engine 4, but due to some breaking changes that were introduced, it is no longer compatible with Unreal Engine 5. Adjust SDK v5 is now compatible with Unreal Engine 5. **Adjust SDK v5 is not compatible with Unreal Engine 4**.

The minimum supported iOS and Android versions have been updated. If your app targets a lower version, update it first.

- iOS: **12.0**
- Android: **API 21**

### Update the initialization method

In Unreal SDK v5, the initialization method has changed from `UAdjust::Initialize` to `UAdjust::InitSdk`.

```cpp
UAdjust::InitSdk(adjustConfig);
```

### Android permissions

In Unreal SDK v5, all the Android permissions are added automatically via underlying native Android SDK v5. Those permissions are:

- `android.permission.INTERNET`
- `com.google.android.gms.permission.AD_ID` for allowing access to Google advertising ID.

Depending on your app and preferences, the access to Google advertising ID might be something you would like to revoke. You can remove this permission with the following snippet to your `AndroidManifest.xml` file:

```xml
<uses-permission android:name="com.google.android.gms.permission.AD_ID" tools:node="remove"/>
```

Learn more about [Adjust's COPPA compliance](https://help.adjust.com/en/article/coppa-compliance).

## Changes and removals

Below is the complete list of changed, renamed, and removed APIs in Unreal SDK v5.

Each section includes a reference to the previous and current API implementations, as well as a minimal code snippet that illustrates how to use the latest version.

## Changed APIs

The following APIs have changed in Unreal SDK v5.

### Disable and enable the SDK

The `SetEnabled` method has been renamed. Unreal SDK v5 introduces two separate methods, for clarity:

- Call `Adjust::Disable` to disable the SDK.
- Call `Adjust::Enable` to enable the SDK.

```cpp
Adjust::Disable(); // disable SDK
Adjust::Enable(); // enable SDK
```

In addition to this, `IsEnabled` getter of the `UAdjust` class is no longer returning `bool` value, but is asynchronous instead. Before invoking `Adjust::IsEnabled` which no longer returns any value, you need to declare a callback to which the SDK enabled status will be reported.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsEnabledGetterDelegate, bool, IsEnabled);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnIsEnabledGetterDelegate OnIsEnabledGetterDelegate;
```

### Offline mode

The `SetOfflineMode` method has been renamed. Unreal SDK v5 introduces two separate methods, for clarity:

- Call `UAdjust::SwitchToOfflineMode` to set the SDK to offline mode.
- Call `UAdjust::SwitchBackToOnlineMode` to set the SDK back to online mode.

### Send from background

The `SendInBackground` field of the `FAdjustConfig` structure has been renamed to `IsSendingInBackgroundEnabled`.

### Attribution structure

In Unreal SDK v5, `Adid` field has been removed from `FAdjustAttribution` structure.

### Event deduplication

In Unreal SDK v5, event deduplication is decoupled from the `TransactionId` field of the `FAdjustEvent` structure. To prevent measuring duplicated events, use the `DeduplicationId` ID field.

### Session callback parameters

In Unreal SDK v5, the session callback parameters have been renamed to global callback parameters together with corresponding methods.

```cpp
UAdjust::AddGlobalCallbackParameter("user_id", "855");
UAdjust::RemoveGlobalCallbackParameter("user_id");
UAdjust::RemoveGlobalCallbackParameters();
```

### Session partner parameters

In Unreal SDK v5, the session partner parameters have been renamed to global partner parameters together with corresponding methods.

```cpp
UAdjust::AddGlobalPartnerParameter("user_id", "855");
UAdjust::RemoveGlobalPartnerParameter("user_id");
UAdjust::RemoveGlobalPartnerParameters();
```

## Deep linking

### Reattribution via deep links

In Unreal SDK v5, the `AppWillOpenUrl` method of the `UAdjust` class has been renamed to `ProcessDeeplink`.

To process a deep link, you now need to create a new `FAdjustDeeplink` structure, assign the deep link string to `Deeplink` field of the structure and pass the structure to the `UAdjust::ProcessDeeplink` method.

```cpp
FAdjustDeeplink adjustDeeplink;
adjustDeeplink.Deeplink = "your-app-scheme://link-content";
UAdjust::ProcessDeeplink(adjustDeeplink);
```

### Disable opening deferred deep links

In Unreal SDK v5, the `OpenDeferredDeeplink` field of the `FAdjustConfig` structure has been renamed to `IsDeferredDeeplinkOpeningEnabled`.

## iOS only API

### SKAdNetwork handling

In Unreal SDK v5, the `HandleSkAdNetwork` field from the `FAdjustConfig` structure has been renamed to `IsSkanAttributionEnabled`.

### App Tracking Transparency authorization wrapper 

In Unreal SDK v5, the `RequestTrackingAuthorizationWithCompletionHandler` method of the `UAdjust` class has been renamed to `RequestAppTrackingAuthorization` for clarity.

### AdServices handling

In unreal SDK v5, the `AllowAdServicesInfoReading` field from the `FAdjustConfig` structure has been renamed to `IsAdServicesEnabled`.

## Get device information

### Adjust ID

Obtaining of the Adjust ID is now asynchronous. `GetAdid` method of the `UAdjust` class no longer returns `FString`, but `void` instead. In order to obtain Adjust ID, you need to declare a callback method on the `UAdjustDelegates` object where the results will be returned and invoke `UAdjust::GetAdid` afterwards.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAdidGetterDelegate, const FString&, Adid);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAdidGetterDelegate OnAdidGetterDelegate;
```

### IDFA

Getter for IDFA has been changed in the same way as Adjust ID getter. Before invoking `UAdjust::GetIdfa` (which returns no value in Unreal SDK v5), you need to declare a callback method on the `UAdjustDelegates` object where the IDFA value will be returned.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIdfaGetterDelegate, const FString&, Idfa);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnIdfaGetterDelegate OnIdfaGetterDelegate;
```

### Amazon advertising ID

Getter for Amazon advertising ID has been changed in the same way as IDFA getter. Before invoking `UAdjust::GetAmazonAdId` (which returns no value in Unreal SDK v5), you need to declare a callback method on the `UAdjustDelegates` object where the Amazon advertising ID value will be returned.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmazonAdIdGetterDelegate, const FString&, AmazonAdId);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAmazonAdIdGetterDelegate OnAmazonAdIdGetterDelegate;
```

### Get attribution information

Similar to getters above, attribution getter is also asynchronous in Unreal SDK v5. Before invoking `UAdjust::GetAttribution`, you should set your callback method on `UAdjustDelegates` object.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionGetterDelegate, const FAdjustAttribution&, Attribution);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAttributionGetterDelegate OnAttributionGetterDelegate;
```

## Removed APIs

The following APIs have been removed from Unreal SDK v5.

- The `DelayStart` field of the `FAdjustConfig` structure has been removed.
- The `SendFirstPackages` method of the `UAdjust` class has been removed.
- The `EventBuffering` field of the `FAdjustConfig` structure has been removed.
- The `IsDeviceKnown` field of the `FAdjustConfig` structure has been removed.
- The `PreinstallTracking` field of the `FAdjustConfig` structure has been removed.
- The `AllowiAdInfoReading` field of the `FAdjustConfig` structure has been removed.
- The `UserAgent` field of the `FAdjustConfig` structure has been removed.
- The `UrlStrategy` field of the `FAdjustConfig` structure has been removed (temporarily).

### Disable third party sharing globally

The `DisableThirdPartySharing` method of the `UAdjust` class has been removed.

To disable all third-party sharing in Unreal SDK v5, use the `TrackThirdPartySharing` method of the `UAdjust` class.

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Disable;

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

### Set an app secret

The `SecretId`, `Info1`, `Info2`, `Info3` and `Info4` fields of the `FAdjustConfig` structure have been removed.

The SDK signature library is bundled in Adjust SDKs v5 and enabled by default. To configure the anti-spoofing solution in the Adjust Dashboard, follow the integration guide for your platform.

### Huawei referrer API

This feature has been removed. If your Unreal app uses the Huawei referrer API, contact your Adjust representative or email support@adjust.com before you upgrade.
