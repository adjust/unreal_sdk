## Summary

This is the Unreal Engine SDK of Adjust™. You can read more about Adjust™ at [Adjust.com].

## Table of contents

* [Basic integration](#basic-integration)
   * [Get the SDK](#sdk-get)
   * [Add the SDK to your project](#sdk-add)
   * [Integrate the SDK into your app](#sdk-integrate)
   * [Adjust logging](#sdk-logging)
* [Additional features](#additional-features)
   * [Event tracking](#event-tracking)
      * [Revenue tracking](#revenue-tracking)
      * [Revenue deduplication](#revenue-deduplication)
      * [Callback parameters](#callback-parameters)
      * [Partner parameters](#partner-parameters)
      * [Callback identifier](#callback-id)
   * [Session parameters](#session-parameters)
      * [Session callback parameters](#session-callback-parameters)
      * [Session partner parameters](#session-partner-parameters)
      * [Delay start](#delay-start)
   * [Attribution callback](#attribution-callback)
   * [Session and event callbacks](#session-event-callbacks)
   * [AppTrackingTransparency framework](#att-framework)
      * [App-tracking authorisation wrapper](#ata-wrapper)
      * [Get current authorisation status](#ata-getter)
   * [SKAdNetwork framework](#skadn-framework)
      * [Update SKAdNetwork conversion value](#skadn-update-conversion-value)
   * [Disable tracking](#disable-tracking)
   * [Offline mode](#offline-mode)
   * [Event buffering](#event-buffering)
   * [GDPR right to be forgotten](#gdpr-forget-me)
   * [SDK signature](#sdk-signature)
   * [Background tracking](#background-tracking)
   * [Device IDs](#device-ids)
      * [iOS advertising identifier](#di-idfa)
      * [Google Play Services advertising identifier](#di-gps-adid)
      * [Amazon advertising identifier](#di-fire-adid)
      * [Adjust device identifier](#di-adid)
   * [User attribution](#user-attribution)
   * [Push token](#push-token)
   * [Pre-installed trackers](#pre-installed-trackers)
* [License](#license)

## <a id="basic-integration"></a>Basic integration

These are the minimal steps required to integrate the Adjust SDK into your Unreal Engine project.

### <a id="sdk-get"></a>Get the SDK

Download the latest version from our [releases page][releases].

### <a id="sdk-add"></a>Add the SDK to your project

Adjust SDK plugin is located inside of the `Adjust` folder inside the archive you just downloaded. Copy `Adjust` folder inside of your app `Plugins` folder.

Add `Adjust` as a dependency to `PublicDependencyModuleNames` array inside of your app's `APPNAME.Build.cs` file:

```
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Adjust" });
```

### <a id="sdk-integrate"></a>Integrate the SDK into your app

It is recommended that you initialise Adjust SDK as soon as possible inside of your app. You can do this by invoking `Initialize` method of the `Adjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void Initialize(const FAdjustConfig& Config);
```

In order to successfully initialise SDK, it is mandatory that you set at least following properties of `FAdjustConfig` structure:
- `AppToken` - Your app token which you can obtain from Adjust dashboard.
- `Environment` - Environment in which you want to start Adjust SDK (either `Sandbox` or `Production`).

**Important:** Environment value should only ever be set to `Sandbox` if you or someone else is testing your app. Make sure to set the environment to `Production` before you publish your app. Set it back to `Sandbox` again when you start developing and testing your app. We use this environment to distinguish between real traffic and test traffic from test devices. It is imperative that you keep this value meaningful at all times.

### <a id="sdk-logging"></a>Adjust logging

You can increase or decrease the amount of logs you see in tests by setting `LogLevel` field on your `FAdjustConfig` structure instance with one of the following values:

```
Verbose   // enable all logging
Debug     // enable more logging
Info      // default
Warn      // disable info logging and below
Error     // disable warnings as well
Assert    // disable errors as well
Suppress  // disable all log output
```

In Android, you can check for log output from Adjust SDK by seaching for lines with tag `Adjust`. In iOS, you can find Adjust SDK log lines by looking the ones that start with `[Adjust]` string.

## <a id="additional-features"></a>Additional features

Once you integrate the Adjust SDK into your project, you can take advantage of the following features.

### <a id="event-tracking"></a>Event tracking

With Adjust, you can track any event that you want. 

If you create a new event token in your [dashboard] - let's say that event token is `abc123` - you can assign that token to `EventToken` field of the `FAdjustEvent` structure and invoke `TrackEvent` method of the `Adjust` class:

```cpp
// Adjust method to invoke for event tracking.
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void TrackEvent(const FAdjustEvent& Event);
```

```cpp
// FAdjustEvent structure EventToken member.
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString EventToken;
```

### <a id="revenue-tracking"></a>Revenue tracking

If your users can generate revenue by tapping on advertisements or making in-app purchases, then you can track that revenue as well. Let's say a tap is worth €0.01. You could track the revenue by setting this info on `Revenue` and `Currency` fields on the `FAdjustEvent` structure:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
float Revenue;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Currency;
```

When you set a currency token, Adjust will automatically convert the incoming revenues into a reporting revenue of your choice. Read more about currency conversion [here][currency-conversion].

You can read more about revenue and event tracking in the [event tracking guide][event-tracking].

### <a id="revenue-deduplication"></a>Revenue deduplication

You can also add an optional transaction ID to avoid tracking duplicate revenues. The last ten transaction IDs are remembered, and revenue events with duplicate transaction IDs are skipped. This is especially useful for in-app purchase tracking. Transaction ID can be assigned to `TransactionId` member of the `FAdjustEvent` structure.

If you want to track in-app purchases, please make sure to call `TrackEvent` only when the transaction has been completed. That way you can avoid tracking revenue that is not actually being generated.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString TransactionId;
```

**Note**: Transaction ID is the iOS term; the unique identifier for successfully completed Android in-app purchases is **Order ID**.

### <a id="callback-parameters"></a>Callback parameters

You can register a callback URL for an event in your [dashboard]. We will send a GET request to that URL whenever the event is tracked. You can add callback parameters to an event by adding key-value pairs to `CallbackParameters` map member of the `FAdjustEvent` structure before tracking the event. We will then append these parameters to your callback URL.

For example, suppose you have registered the URL `http://www.adjust.com/callback` for your event and that you add two key-value pairs (`("key", "value")` and `("foo", "bar")`) to `CallbackParameters` member:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
TMap<FString, FString> CallbackParameters;
```

In this case, we would track the event and send a request to:

```
http://www.adjust.com/callback?key=value&foo=bar
```

It should be mentioned that we support a variety of placeholders, like `{idfa}` for iOS or `{gps_adid}` for Android, that can be used as parameter values.  In the resulting callback, the `{idfa}` placeholder would be replaced with the ID for advertisers of the current device for iOS and the `{gps_adid}` would be replaced with the Google advertising ID of the current device for Android. Also note that we don't store any of your custom parameters, but only append them to your callbacks. If you haven't registered a callback for an event, these parameters won't even be read.

You can read more about using URL callbacks, including a full list of available values, in our [callbacks guide][callbacks-guide].

### <a id="partner-parameters"></a>Partner parameters

For any integrations that you have activated in your Adjust dashboard, you can add parameters to send to these network partners.

Partner parameters work similarly to the callback parameters mentioned above, by adding key-value pairs to `PartnerParameters` map member of the `FAdjustEvent` structure.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
TMap<FString, FString> PartnerParameters;
```

You can read more about special partners and how to integrate them in our [guide to special partners][special-partners].

### <a id="callback-id"></a>Callback identifier

You can also add custom string identifier to each event you want to track. This identifier will later be reported in event success and/or event failure callbacks to enable you to keep track on which event was successfully tracked or not. You can set this identifier by assigning the value to `CallbackId` member of `FAdjustEvent` structure:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString CallbackId;
```

### <a id="session-parameters"></a>Session parameters

Some parameters are saved to be sent in every event and session of the Adjust SDK. Once you have added any of these parameters, you don't need to add them again, since they will be saved locally. If you add the same parameter twice, there will be no effect.

These session parameters can be called before the Adjust SDK is launched to make sure they are sent even on install. If you need to send them with an install, but can only obtain the needed values after launch, it's possible to [delay](#delay-start) the first launch of the Adjust SDK to allow for this.

### <a id="session-callback-parameters"></a>Session callback parameters

You can save the same callback parameters that are registered for [events](#callback-parameters) to be sent in every event or session of the Adjust SDK.

Session callback parameters have a similar interface to event callback parameters, except that, instead of adding the key and its value to an event, they are added through a call to the `AddSessionCallbackParameter` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void AddSessionCallbackParameter(const FString& Key, const FString& Value);
```

Session callback parameters will be merged with the callback parameters you have added to an event. Callback parameters that have been added to an event take precedence over session callback parameters. If you add a callback parameter to an event with the same key as one added from the session, the callback parameter added to the event will prevail.

It's possible to remove a specific session callback parameter by passing the desired key to the `RemoveSessionCallbackParameter` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveSessionCallbackParameter(const FString& Key);
```

If you wish to remove all keys and values from the session callback parameters, you can reset them with the `ResetSessionCallbackParameters` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void ResetSessionCallbackParameters();
```

### <a id="session-partner-parameters"></a>Session partner parameters

In the same way that there are [session callback parameters](#session-callback-parameters) that are sent for every event or session of the Adjust SDK, there are also session partner parameters. These will be transmitted to any network partners that have been integrated and activated in your Adjust [dashboard].

Session partner parameters have a similar interface to event partner parameters, except that, instead of adding the key and its value to an event, they are added through a call to the `AddSessionPartnerParameter` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void AddSessionPartnerParameter(const FString& Key, const FString& Value);
```

Session partner parameters will be merged with the partner parameters that you have added to an event. The partner parameters that have been added to an event take precedence over session partner parameters. This means that if you add a partner parameter to an event with the same key as one added from the session, the partner parameter will prevail.

It is possible to remove a specific session partner parameter by passing the desired key to the `RemoveSessionPartnerParameter` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveSessionPartnerParameter(const FString& Key);
```

If you wish to remove all keys and values from the session partner parameters, you can reset them with the `ResetSessionPartnerParameters` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void ResetSessionPartnerParameters();
```

### <a id="delay-start"></a>Delay start

Delaying the start of the Adjust SDK allows your app some time to obtain session parameters, such as unique identifiers, so they can be sent upon install.

Set the initial delay time, in seconds, with the `DelayStart` member of the `FAdjustConfig` structure:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString DelayStart;
```

After this time has elapsed, or if you call `SendFirstPackages` method of the `Adjust` class in the meantime, every session parameter will be added to the delayed install session and events, and the Adjust SDK will resume as usual.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SendFirstPackages();
```

**The maximum delay start time of the Adjust SDK is 10 seconds**.

### <a id="attribution-callback"></a>Attribution callback

Adjust can also send you a callback upon any change in attribution. Due to the different sources considered for attribution, this information cannot be provided synchronously.

Attribution callback exists in `AdjustDelegates` class and has following signature:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedDelegate, const FAdjustAttribution&, Attribution);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnAttributionChangedDelegate OnAttributionChangedDelegate;
```

Once implemented in your app and triggered, you can access following attribution information inside `FAdjustAttribution` struct instance:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString TrackerToken; // The tracker token of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString TrackerName;  // The tracker name of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Network;      // The network grouping level of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Campaign;     // The campaign grouping level of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adgroup;      // The ad group grouping level of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Creative;     // The creative grouping level of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString ClickLabel;   // The click label of the current attribution.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adid;         // The Adjust device identifier.
```

Please make sure to consider the [applicable attribution data policies][attribution-data].

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedNonDynamicDelegate, const FAdjustAttribution&);
```

### <a id="session-event-callbacks"></a>Session and event callbacks

You can register a callback to be notified of successfully tracked, as well as failed, events and/or sessions.

Follow the same steps as in the [attribution callback section above](#attribution-callback) if you want to implement the callback function for successfully tracked events:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSuccessDelegate, const FAdjustEventSuccess&, EventSuccess);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnEventSuccessDelegate OnEventSuccessDelegate;
```

Once implemented in your app and triggered, you can access following information inside `FAdjustEventSuccess` struct instance:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString EventToken;   // The event token.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString CallbackId;   // The callback ID of the event.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Message;      // The message from the server or the error logged by the SDK.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Timestamp;    // The timestamp from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adid;         // A unique device identifier provided by Adjust.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString JsonResponse; // The JSON object with the response from the server.
```

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEventSuccessNonDynamicDelegate, const FAdjustEventSuccess&);
```

The following callback function is used for failed events:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventFailureDelegate, const FAdjustEventFailure&, EventFailure);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnEventFailureDelegate OnEventFailureDelegate;
```

Once implemented in your app and triggered, you can access following information inside `FAdjustEventFailure` struct instance:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString EventToken;   // The event token.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString CallbackId;   // The callback ID of the event.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Message;      // The message from the server or the error logged by the SDK.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Timestamp;    // The timestamp from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adid;         // A unique device identifier provided by Adjust.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString JsonResponse; // The JSON object with the response from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool WillRetry;       // Indicates there will be an attempt to resend the package at a later time.
```

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEventFailureNonDynamicDelegate, const FAdjustEventFailure&);
```

For successfully tracked sessions:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionSuccessDelegate, const FAdjustSessionSuccess&, SessionSuccess);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnSessionSuccessDelegate OnSessionSuccessDelegate;
```

Once implemented in your app and triggered, you can access following information inside `FAdjustSessionSuccess` struct instance:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Message;      // The message from the server or the error logged by the SDK.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Timestamp;    // The timestamp from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adid;         // A unique device identifier provided by Adjust.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString JsonResponse; // The JSON object with the response from the server.
```

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSessionSuccessNonDynamicDelegate, const FAdjustSessionSuccess&);
```

And for session failures:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionFailureDelegate, const FAdjustSessionFailure&, SessionFailure);

//...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnSessionFailureDelegate OnSessionFailureDelegate;
```

Once implemented in your app and triggered, you can access following information inside `FAdjustSessionFailure` struct instance:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Message;      // The message from the server or the error logged by the SDK.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Timestamp;    // The timestamp from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Adid;         // A unique device identifier provided by Adjust.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString JsonResponse; // The JSON object with the response from the server.

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool WillRetry;       // Indicates there will be an attempt to resend the package at a later time.
```

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSessionFailureNonDynamicDelegate, const FAdjustSessionFailure&);
```

### <a id="att-framework"></a>AppTrackingTransparency framework

**Note**: This feature exists only in iOS platform.

For each package sent, the Adjust backend receives one of the following four (4) states of consent for access to app-related data that can be used for tracking the user or the device:

- Authorized
- Denied
- Not Determined
- Restricted

After a device receives an authorization request to approve access to app-related data, which is used for user device tracking, the returned status will either be Authorized or Denied.

Before a device receives an authorization request for access to app-related data, which is used for tracking the user or device, the returned status will be Not Determined.

If authorization to use app tracking data is restricted, the returned status will be Restricted.

The SDK has a built-in mechanism to receive an updated status after a user responds to the pop-up dialog, in case you don't want to customize your displayed dialog pop-up. To conveniently and efficiently communicate the new state of consent to the backend, Adjust SDK offers a wrapper around the app tracking authorization method described in the following chapter, App-tracking authorization wrapper.

### <a id="ata-wrapper"></a>App-tracking authorisation wrapper

**Note**: This feature exists only in iOS platform.

Adjust SDK offers the possibility to use it for requesting user authorization in accessing their app-related data. Adjust SDK has a wrapper built on top of the [requestTrackingAuthorizationWithCompletionHandler:](https://developer.apple.com/documentation/apptrackingtransparency/attrackingmanager/3547037-requesttrackingauthorizationwith?language=objc) method, where you can as well define the callback method to get information about a user's choice. Also, with the use of this wrapper, as soon as a user responds to the pop-up dialog, it's then communicated back using your callback method. The SDK will also inform the backend of the user's choice. The `NSUInteger` value will be delivered via your callback method with the following meaning:

- 0: `ATTrackingManagerAuthorizationStatusNotDetermined`
- 1: `ATTrackingManagerAuthorizationStatusRestricted`
- 2: `ATTrackingManagerAuthorizationStatusDenied`
- 3: `ATTrackingManagerAuthorizationStatusAuthorized`

To use this wrapper, you need to register your callback method where authorisation status value will be delivered and call make a call to `requestTrackingAuthorizationWithCompletionHandler` method of `Adjust` class.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusDelegate, const int, AuthorizationStatus);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnAuthorizationStatusDelegate OnAuthorizationStatusDelegate;
```

If you are building your app with C++ and would like to avoid usage of dynamic delegates, you can also take advantage of non dynamic delegate:

```cpp
DECLARE_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusNonDynamicDelegate, const int);
```

In order to show the authorization dialog, you need to make sure to add text you want to be displayed in the dialog in your iOS app's `Info.plist` file. You can do that by going to `Project Settings -> Platforms -> iOS -> Extra PList Data` and adding key-value pair for this purpose:

```xml
<key>NSUserTrackingUsageDescription</key><string>Describe your reason to access IDFA in here.</string>

```

### <a id="ata-getter"></a>Get current authorisation status

**Note**: This feature exists only in iOS platform.

To get the current app tracking authorization status you can call `GetAppTrackingAuthorizationStatus` method of `Adjust` class that will return one of the following possibilities:

* `0`: The user hasn't been asked yet
* `1`: The user device is restricted
* `2`: The user denied access to IDFA
* `3`: The user authorized access to IDFA
* `-1`: The status is not available

### <a id="skadn-framework"></a>SKAdNetwork framework

**Note**: This feature exists only in iOS platform.

If you have implemented the Adjust SDK v4.26.0 or above and your app is running on iOS 14, the communication with SKAdNetwork will be set on by default, although you can choose to turn it off. When set on, Adjust automatically registers for SKAdNetwork attribution when the SDK is initialized. If events are set up in the Adjust dashboard to receive conversion values, the Adjust backend sends the conversion value data to the SDK. The SDK then sets the conversion value. After Adjust receives the SKAdNetwork callback data, it is then displayed in the dashboard.

In case you don't want the Adjust SDK to automatically communicate with SKAdNetwork, you can disable that in your `FAdjustConfig` structure instance by setting the `HandleSkAdNetwork` member to `false` (is set to `true` by default):

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool HandleSkAdNetwork = true;
```

### <a id="skadn-update-conversion-value"></a>Update SKAdNetwork conversion value

As of Adjust SDK v4.26.0 you can use Adjust SDK wrapper method `UpdateConversionValue` to update SKAdNetwork conversion value for your user:

```cpp
UAdjust::UpdateConversionValue(6);
```

### <a id="disable-tracking"></a>Disable tracking

You can disable the Adjust SDK from tracking by invoking the `SetEnabled` method of the `Adjust` class with the enabled parameter set to `false`. This setting is **remembered between sessions**, but it can only be activated after the first session.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SetEnabled(bool Enable);
```

You can verify if the Adjust SDK is currently active by using the `IsEnabled()` method of the `Adjust` class. 

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static bool IsEnabled();
```

It is always possible to activate the Adjust SDK by invoking `SetEnabled` method of the `Adjust` class with the parameter set to `true`.

### <a id="offline-mode"></a>Offline mode

You can put the Adjust SDK into offline mode, suspending transmissions to our servers while retaining tracked data to be sent later. When in offline mode, all information is saved in a file, so it is best not to trigger too many events while in offline mode.

You can activate offline mode by calling `SetOfflineMode` method of the `Adjust` class with the parameter set to `true`.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SetOfflineMode(bool Offline);
```

Conversely, you can deactivate offline mode by calling `SetOfflineMode` method of the `Adjust` class with the parameter set to `false`. When the Adjust SDK is put back in online mode, all saved information is sent to our servers with the correct time information.

Unlike when disabling tracking, **this setting is not remembered** between sessions. This means that the Adjust SDK always starts in online mode, even if the app was terminated in offline mode.

### <a id="event-buffering"></a>Event buffering

If your app makes heavy use of event tracking, you might want to delay some HTTP requests in order to send them in one batch every minute. You can enable event buffering through your `FAdjustConfig` structure instance by setting the `EventBuffering` member to `true`:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool EventBuffering;
```

If nothing is set here, event buffering is **disabled by default**.

### <a id="gdpr-forget-me"></a>GDPR right to be forgotten

In accordance with article 17 of the EU's General Data Protection Regulation (GDPR), you can notify Adjust when a user has exercised their right to be forgotten. Calling the following method will instruct the Adjust SDK to communicate the user's choice to be forgotten to the Adjust backend:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GdprForgetMe();
```

Upon receiving this information, Adjust will erase the user's data and the Adjust SDK will stop tracking the user. No requests from this device will be sent to Adjust in the future.

### <a id="sdk-signature"></a>SDK signature

An account manager must activate the Adjust SDK signature. Contact Adjust support (support@adjust.com) if you are interested in using this feature.

If the SDK signature has already been enabled on your account and you have access to App Secrets in your Adjust Dashboard, please use the method below to integrate the SDK signature into your app.

An App Secret is set by passing all secret parameters (`SecretId`, `Info1`, `Info2`, `Info3`, `Info4`) to `FAdjustConfig` structure instance before initialising the SDK:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString SecretId;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Info1;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Info2;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Info3;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Info4;
```

### <a id="background-tracking"></a>Background tracking

The default behavior of the Adjust SDK is to **pause sending HTTP requests while the app is in the background**. You can change this in your `FAdjustConfig` structure instance by setting the `SendInBackground` member to `true`:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool SendInBackground;
```

If nothing is set here, sending in the background is **disabled by default**.

### <a id="device-ids"></a>Device IDs

Certain services (such as Google Analytics) require you to coordinate device and client IDs in order to prevent duplicate reporting.

### <a id="di-idfa"></a>iOS Advertising Identifier

You can access the IDFA value on an iOS device by invoking the `GetIdfa()` method of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static FString GetIdfa();
```

### <a id="di-gps-adid"></a>Google Play Services advertising identifier

The Adjust SDK allows you to read the Google Advertising Identifier of the Android device on which your app is running. To do this, set the callback method which receives the `FString` parameter. This callback is, like all previous callbacks, part of the `AdjustDelegates` class. 

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoogleAdvertisingIdDelegate, const FString&, GoogleAdId);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnGoogleAdvertisingIdDelegate OnGoogleAdvertisingIdDelegate;
```

Next, invoke the `GetGoogleAdId()` method of the `Adjust` class. You will then get the Google Advertising Identifier value in your previously set callback:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetGoogleAdId();
```

### <a id="di-fire-adid"></a>Amazon advertising identifier

If you need to obtain the Amazon advertising ID, you can call the `GetAmazonAdId()` method of the `Adjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static FString GetAmazonAdId();
```

### <a id="di-adid"></a>Adjust device identifier

For each device with your app installed, the Adjust backend generates a unique **Adjust device identifier** (**adid**). In order to obtain this identifier, you can call the following method on the `Adjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static FString GetAdid();
```

**Note**: Information about the **adid** is only available after the Adjust backed has tracked your app's installation. From that moment on, the Adjust SDK has information about the device **adid** and you can access it with this method. So, **it is not possible** to access the **adid** before the SDK has been initialized and the installation of your app has been tracked successfully.

### <a id="user-attribution"></a>User attribution

Attribution callbacks are triggered via the method described in the [attribution callback section](#attribution-callback). They provide you with information about any changes to your users’ attribution values. If you wish to access information about a user's current attribution value at any other time, you can make a call to the following method of the `Adjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static FAdjustAttribution GetAttribution();
```

**Note**: Information about a user’s current attribution value is only available after the Adjust backed has tracked your app's installation and an initial attribution callback has been triggered. From that moment on, the Adjust SDK has information about the user's attribution value and you can access it with this method. So, **it is not possible** to access a user's attribution value before the SDK has been initialized and an initial attribution callback has been triggered.

### <a id="push-token"></a>Push token

To send us a push notification token, add the following call to Adjust **whenever your app receives the token or it is updated**:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SetPushToken(const FString& PushToken);
```

Push tokens are used for the Adjust Audience Builder and client callbacks, and are required for the uninstall tracking feature.

### <a id="pre-installed-trackers"></a>Pre-installed trackers

If you want to use the Adjust SDK to recognize users whose devices came with your app pre-installed, follow these steps.

- Create a new tracker in your [dashboard].
- Set the default tracker member of your `FAdjustConfig` structure instance:

    ```cpp
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DefaultTracker;
    ```

  Replace `{TrackerToken}` with the tracker token you created in step one. Please note that the dashboard displays a tracker URL (including `http://app.adjust.com/`). In your source code, you should specify only the six-character token and not the entire URL.

- Build and run your app. You should see a line like the following in the app's log output:

    ```
    Default tracker: 'abc123'
    ```
    

[adjust]:       http://adjust.com
[dashboard]:    http://adjust.com
[adjust.com]:   http://adjust.com

[releases]:             https://github.com/adjust/unreal_sdk/releases
[event-tracking]:       https://docs.adjust.com/en/event-tracking
[callbacks-guide]:      https://docs.adjust.com/en/callbacks
[special-partners]:     https://docs.adjust.com/en/special-partners
[attribution-data]:     https://github.com/adjust/sdks/blob/master/doc/attribution-data.md
[currency-conversion]:  https://docs.adjust.com/en/event-tracking/#tracking-purchases-in-different-currencies

    
## <a id="license"></a>License

The Adjust SDK is licensed under the MIT License.

Copyright (c) 2018-2021 Adjust GmbH, http://www.adjust.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
