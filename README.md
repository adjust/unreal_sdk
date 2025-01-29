## Summary

This is the Unreal Engine SDK of Adjust™. You can read more about Adjust™ at [Adjust.com].

## Table of contents

* [Basic integration](#basic-integration)
   * [Get the SDK](#sdk-get)
   * [Add the SDK to your project](#sdk-add)
   * [Integrate the SDK into your app](#sdk-integrate)
   * [Adjust logging](#sdk-logging)
* [Additional features](#additional-features)
   * [Send event information](#event-sending)
      * [Event revenue](#event-revenue)
      * [Event deduplication](#event-deduplication)
      * [Event callback identifier](#event-callback-id)
      * [Event callback parameters](#event-callback-params)
      * [Event partner parameters](#event-partner-params)
   * [User attribution](#user-attribution)
      * [Attribution callback](#attribution-callback)
      * [Get user attribution](#attribution-getter)
   * [Preinstalled apps](#preinstalled-apps)
      * [Default link token](#preinstall-default-link)
   * [Global parameters](#global-params)
      * [Global callback parameters](#global-callback-params)
      * [Global partner parameters](#global-partner-params)
   * [Privacy features](#privacy-features)
      * [GDPR right to be forgotten](#gdpr-forget-me)
      * [Third party sharing](#third-party-sharing)
      * [Disable third-party sharing for specific users](#disable-third-party-sharing)
      * [Enable or re-enable third-party sharing for specific users](#enable-third-party-sharing)
      * [Send granular options](#send-granular-options)
      * [Manage Facebook Limited Data Use](#facebook-limited-data-use)
      * [Provide consent data to Google (Digital Markets Act compliance)](#digital-markets-act)
      * [Update partner sharing settings](#partner-sharing-settings)
      * [Consent measurement for specific users](#measurement-consent)
      * [COPPA compliance](#coppa-compliance)
      * [Play Store kids apps](#play-store-kids-apps)
   * [Deep linking](#deeplinking)
      * [Standard deep linking scenario](#deeplinking-standard)
      * [Deferred deep linking scenario](#deeplinking-deferred)
      * [Reattribution via deep links](#deeplinking-reattribution)
      * [Resolve Adjust short links](#short-links-resolution)
   * [App Tracking Transparency](#app-tracking-transparency)
      * [ATT authorization wrapper](#att-wrapper)
      * [Get current authorization status](#att-status-getter)
      * [ATT prompt waiting interval](#att-waiting-interval)
   * [SKAdNetwork and conversion values](#skan-framework)
      * [Disable SKAdNetwork communication](#skan-disable)
      * [Set up direct install postbacks](#skan-postbacks)
   * [Record ad revenue information](#adrevenue-recording)
      * [Ad revenue amount](#adrevenue-amount)
      * [Ad revenue network](#adrevenue-network)
      * [Ad revenue unit](#adrevenue-unit)
      * [Ad revenue placement](#adrevenue-placement)
      * [Ad impressions count](#adrevenue-impressions)
      * [Ad revenue callback parameters](#adrevenue-callback-params)
      * [Ad revenue partner parameters](#adrevenue-partner-params)
   * [Device IDs](#device-ids)
      * [iOS advertising identifier](#idfa)
      * [iOS identifier for vendors](#idfv)
      * [Google Play Services advertising identifier](#gps-adid)
      * [Amazon advertising identifier](#fire-adid)
      * [Adjust device identifier](#adid)
   * [Session and event callbacks](#session-event-callbacks)
   * [Disable the SDK](#disable-sdk)
   * [Offline mode](#offline-mode)
   * [Sending from background](#background-sending)
   * [External device ID](#external-device-id)
   * [Push token](#push-token)
   * [Disable AdServices information reading](#disable-ad-services)
* [License](#license)

## <a id="basic-integration"></a>Basic integration

These are the minimal steps required to integrate the Adjust SDK into your Unreal Engine project.

### <a id="sdk-get"></a>Get the SDK

Download the latest version from our [releases page][releases].

### <a id="sdk-add"></a>Add the SDK to your project

Adjust SDK plugin is located inside of the `Adjust` folder inside the archive you just downloaded. Copy `Adjust` folder inside of your app `Plugins` folder.

Add `Adjust` as a dependency to `PublicDependencyModuleNames` array inside of your app's `APPNAME.Build.cs` file:

```cs
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Adjust" });
```

### <a id="sdk-integrate"></a>Integrate the SDK into your app

It is recommended that you initialise Adjust SDK as soon as possible inside of your app. You can do this by invoking `InitSdk` method of the `Adjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void InitSdk(const FAdjustConfig& Config);
```

In order to successfully initialise SDK, it is mandatory that you set at least following properties of `FAdjustConfig` structure:
- `AppToken` - Your app token which you can obtain from Adjust dashboard.
- `Environment` - Environment in which you want to start Adjust SDK (either `EAdjustEnvironment::Sandbox` or `EAdjustEnvironment::Production`).

**Important:** Environment value should only ever be set to `EAdjustEnvironment::Sandbox` if you or someone else is testing your app. Make sure to set the environment to `EAdjustEnvironment::Production` before you publish your app. Set it back to `EAdjustEnvironment::Sandbox` again when you start developing and testing your app. We use this environment to distinguish between real traffic and test traffic from test devices. It is imperative that you keep this value meaningful at all times.

### <a id="sdk-logging"></a>Adjust logging

You can increase or decrease the amount of logs you see in tests by setting `LogLevel` field on your `FAdjustConfig` structure instance with one of the following values:

```
EAdjustLogLevel::Verbose   // enable all logging
EAdjustLogLevel::Debug     // enable more logging
EAdjustLogLevel::Info      // default
EAdjustLogLevel::Warn      // disable info logging and below
EAdjustLogLevel::Error     // disable warnings as well
EAdjustLogLevel::Assert    // disable errors as well
EAdjustLogLevel::Suppress  // disable all log output
```

In Android, you can check for log output from Adjust SDK by seaching for lines with tag `Adjust`. In iOS, you can find Adjust SDK log lines by looking the ones that start with `[Adjust]` string.

## <a id="additional-features"></a>Additional features

You can take advantage of the following features once the Adjust SDK is integrated into your project.

### <a id="event-sending"></a>Send event information

You can tell Adjust about every event you want to record.

If you create a new event in your dashboard - let's say that event token is `abc123` - you can assign that token to `EventToken` field of the `FAdjustEvent` structure and invoke `TrackEvent` method of the `UAdjust` class:

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

### <a id="event-revenue"></a>Event revenue

If your users can generate revenue by tapping on advertisements or making in-app purchases, then you can record those revenues with events. You could track the revenue by setting this info on `Revenue` and `Currency` fields on the `FAdjustEvent` structure:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
float Revenue;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Currency;
```

### <a id="event-deduplication"></a>Event deduplication

You can also add an optional deduplication ID to avoid recording duplicate events. The last ten transaction IDs are remembered by default, and events with duplicate deduplication IDs are skipped. This is especially useful for in-app purchase tracking. Deduplication ID can be assigned to `DeduplicationId` member of the `FAdjustEvent` structure.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString DeduplicationId;
```

### <a id="event-callback-id"></a>Event callback identifier

You can also add custom string identifier to each event you want to record. This identifier will later be reported in event success and/or event failure callbacks to enable you to keep track on which event was successfully recorded or not.  You can set this identifier by assigning the value to `CallbackId` member of `FAdjustEvent` structure:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString CallbackId;
```

### <a id="event-callback-params"></a>Event callback parameters

You can also register a callback URL for that event in your [dashboard](https://dash.adjust.com), and we will send a GET request to that URL whenever the event gets recorded. In that case, you can also put some key-value pairs to `CallbackParameters` map member of the `FAdjustEvent` structure before tracking the event. We will then append these parameters to your callback URL.

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

### <a id="event-partner-params"></a>Event partner parameters

You can also add parameters for integrations that have been activated in your Adjust dashboard that can be transmitted to network partners.

This works similarly to the callback parameters mentioned above, by adding key-value pairs to `PartnerParameters` map member of the `FAdjustEvent` structure.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
TMap<FString, FString> PartnerParameters;
```

### <a id="user-attribution"></a>User attribution

Each recorded install is getting certain attribution assigned and also, during the app lifetime, the attribution can change.

### <a id="attribution-callback"></a>Attribution callback

You can register a callback to be notified of attribution changes. Due to the different sources considered for attribution, this information can not be provided synchronously.

Attribution callback exists in `UAdjustDelegates` class and has following signature:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedDelegate, const FAdjustAttribution&, Attribution);

// ...

UPROPERTY(BlueprintAssignable, Category = Adjust)
FOnAttributionChangedDelegate OnAttributionChangedDelegate;
```

Once implemented in your app and triggered, you can access following attribution information inside `FAdjustAttribution` struct instance:

```cpp
// the campaign link token of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString TrackerToken;

// the campaign link name of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString TrackerName;

// the network grouping level of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString Network;

// the campaign grouping level of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString Campaign;

// the ad group grouping level of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString Adgroup;

// the creative grouping level of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString Creative;

// the click label of the current attribution
UPROPERTY(BlueprintReadWrite, Category = "Adjust")
FString ClickLabel;

// the cost type in case cost data is part of the attribution
UPROPERTY(BlueprintReadOnly, Category = "Adjust")
FString CostType;

// the cost amount in case cost data is part of the attribution
UPROPERTY(BlueprintReadOnly, Category = "Adjust")
double CostAmount;   

// the cost currency in case cost data is part of the attribution
UPROPERTY(BlueprintReadOnly, Category = "Adjust")
FString CostCurrency;

// the FB install referrer value in case install is attributed to it (Android only)
UPROPERTY(BlueprintReadOnly, Category = "Adjust")
FString FbInstallReferrer;
```

### <a id="attribution-getter"></a>Get user attribution

If you want to access information about a user's current attribution whenever you need it, you can make a call to the `GetAttribution` method of the `UAdjust` class.

Before making this call, you need to assign a callback method to the isntance of `UAdjustDelegates` class:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionGetterDelegate, const FAdjustAttribution&, Attribution);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAttributionGetterDelegate OnAttributionGetterDelegate;
```

**Note**: Information about current attribution is available after app installation has been recorded by the Adjust backend and the attribution callback has been initially triggered. From that moment on, the Adjust SDK has information about a user's attribution and you can access it with this method. So, **it is not possible** to access a user's attribution value before the SDK has been initialised and an attribution callback has been triggered.

### <a id="preinstalled-apps"></a>Preinstalled apps

You can use the Adjust SDK to record activity from apps that came preinstalled on a user’s device. This enables you to attribute these users to a custom defined campaign link instead to an organic one.

### <a id="preinstall-default-link"></a>Default link token

Configuring a default link token enables you to attribute all preinstalls to a predefined Adjust link. Adjust records all information against this token until the attribution source changes. To set this up, first you need to [create a new campaign link in Campaign Lab](https://help.adjust.com/en/article/links). After doing this set the default tracker member of your `FAdjustConfig` structure instance:

 ```cpp
 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
 FString DefaultTracker;
 ```

In case this approach is not applicable to your preinstall use case, please reach out to support@adjust.com to explore other ways of how the attribution for preinstalled apps can be handled.

### <a id="global-params"></a>Global parameters

Some parameters are saved to be sent in every session, event, ad revenue and subscription request of the Adjust SDK. Once you have added any of these parameters, you don't need to add them every time, since they will be saved locally. If you add the same parameter twice, there will be no effect. These global parameters can be set before the Adjust SDK is launched to make sure they are sent even on install.

### <a id="global-callback-params"></a>Global callback parameters

### <a id="session-callback-parameters"></a>Session callback parameters

You can save the same callback parameters that are registered for [events](#callback-parameters) to be sent in every event or session of the Adjust SDK.

The global callback parameters have a similar interface to the event callback parameters. Instead of adding the key and its value to an event, it's added through a call to the `AddGlobalCallbackParameter` method of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void AddGlobalCallbackParameter(const FString& Key, const FString& Value);
```

The global callback parameters will be merged with the callback parameters added to an event / ad revenue / subscription. The callback parameters added to any of these packages take precedence over the global callback parameters. Meaning that, when adding a callback parameter to any of these packages with the same key to one added globaly, the value that prevails is the callback parameter added any of these particular packages.

It's possible to remove a specific global callback parameter by passing the desired key to the method `RemoveGlobalCallbackParameter` of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveGlobalCallbackParameter(const FString& Key);
```

If you wish to remove all keys and values from the global callback parameters, you can reset it with the method `RemoveGlobalCallbackParameters` of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveGlobalCallbackParameters();
```

### <a id="global-partner-params"></a>Global partner parameters

In the same way that there are [global callback parameters](#session-callback-params) that are sent for every event or session of the Adjust SDK, there are also global partner parameters.

These will be transmitted to network partners, for the integrations that have been activated in your Adjust [dashboard](https://dash.adjust.com).

The global partner parameters have a similar interface to the event / ad revenue / subscription partner parameters. Instead of adding the key and its value to an event, it's added through a call to the `AddGlobalPartnerParameter` method of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void AddGlobalPartnerParameter(const FString& Key, const FString& Value);
```

The global partner parameters will be merged with the partner parameters added to an event / ad revenue / subscription. The partner parameters added to any of thes packages take precedence over the global partner parameters. Meaning that, when adding a partner parameter to any of these packages with the same key to one added globally, the value that prevails is the partner parameter added to any of these particular packages.

It's possible to remove a specific global partner parameter by passing the desired key to the method `RemoveGlobalPartnerParameter` of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveGlobalPartnerParameter(const FString& Key);
```

If you wish to remove all keys and values from the global partner parameters, you can reset them with the method `RemoveGlobalPartnerParameters` of the `Adjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RemoveGlobalPartnerParameters();
```

### <a id="privacy-features"></a>Privacy features

The Adjust SDK contains features that you can use to handle user privacy in your app.

### <a id="gdpr-forget-me"></a>GDPR right to be forgotten

In accordance with article 17 of the EU's General Data Protection Regulation (GDPR), you can notify Adjust when a user has exercised their right to be forgotten. Calling the following method will instruct the Adjust SDK to communicate the user's choice to be forgotten to the Adjust backend:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GdprForgetMe();
```

Upon receiving this information, Adjust will erase the user's data and no requests from this device will be sent to Adjust in the future.

### <a id="third-party-sharing"></a>Third-party sharing for specific users

You can notify Adjust when a user disables, enables, and re-enables data sharing with third-party partners.

### <a id="disable-third-party-sharing"></a>Disable third-party sharing for specific users

In order to change third party sharing settings for your users, you need to invoke `TrackThirdPartySharing` method of the `UAdjust` class:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void TrackThirdPartySharing(const FAdjustThirdPartySharing& ThirdPartySharing);
```

Call the following method to instruct the Adjust SDK to communicate the user's choice to disable data sharing to the Adjust backend:

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Disable;

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

Upon receiving this information, Adjust will block the sharing of that specific user's data to partners and the Adjust SDK will continue to work as usual.

### <a id="enable-third-party-sharing">Enable or re-enable third-party sharing for specific users</a>

Call the following method to instruct the Adjust SDK to communicate the user's choice to share data or change data sharing, to the Adjust backend:

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Enable;

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

Upon receiving this information, Adjust changes sharing the specific user's data to partners. The Adjust SDK will continue to work as expected.

### <a id="send-granular-options">Send granular options</a>

You can attach granular information when a user updates their third-party sharing preferences. Use this information to communicate more detail about a user’s decision. To do this, call the `GranularOption.Add` method like this:

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustGranularOption GranularOptions;
GranularOptions.GranularOption.Add("key", "value");
adjustThirdPartySharing.GranularOptions.Add("partnerName", GranularOptions);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

The following partners are available:

| Partner name              | String value                  |
|---------------------------|-------------------------------|
| AppleAds                  | apple_ads                     |
| Facebook                  | facebook                      |
| GoogleAds                 | adwords                       |
| GoogleMarketingPlatform   | google_marketing_platform     |
| Snapchat                  | snapchat                      |
| Tencent                   | tencent                       |
| TikTokSan                 | tiktok_san                    |
| X (formerly Twitter)      | twitter                       |
| YahooGemini               | yahoo_gemini                  |
| YahooJapanSearch          | yahoo_japan_search            |

### <a id="facebook-limited-data-use">Manage Facebook Limited Data Use</a>

Facebook provides a feature called Limited Data Use (LDU) to comply with the California Consumer Privacy Act (CCPA). This feature enables you to notify Facebook when a California-based user is opted out of the sale of data. You can also use it if you want to opt all users out by default.

You can update the Facebook LDU status by passing arguments following arguments:

| Parameter                        | Description                                                                 |
|----------------------------------|-----------------------------------------------------------------------------|
| `partner_name`                   | Use `facebook` to toggle LDU.                                              |
| `data_processing_options_country`| The country in which the user is located.                                  |
|                                  | - `0`: Request that Facebook use geolocation.                              |
|                                  | - `1`: United States of America.                                           |
| `data_processing_options_state`  | Notifies Facebook in which state the user is located.                      |
|                                  | - `0`: Request that Facebook use geolocation.                              |
|                                  | - `1000`: California.                                                      |
|                                  | - `1001`: Colorado.                                                        |
|                                  | - `1002`: Connecticut.                                                     |

> Note: If you call this method with a 0 value for **either** `data_processing_options_country` or `data_processing_options_state`, the Adjust SDK passes **both** fields back as 0.

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustGranularOption GranularOptions;
GranularOptions.GranularOption.Add("data_processing_options_country", "1");
GranularOptions.GranularOption.Add("data_processing_options_state", "1000");
adjustThirdPartySharing.GranularOptions.Add("facebook", GranularOptions);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

### <a id="digital-markets-act">Provide consent data to Google (Digital Markets Act compliance)</a>

> Important: Passing these options is required if you use Google Ads or Google Marketing Platform and have users located in the European Economic Area (EEA).

To comply with the EU’s Digital Markets Act (DMA), Google Ads and the Google Marketing Platform require explicit consent to receive Adjust’s attribution requests to their APIs. To communicate this consent, you need to add the following granular options to your third party sharing instance for the partner `google_dma`.

| Key                 | Value               | Description                                                                                                      |
|---------------------|---------------------|------------------------------------------------------------------------------------------------------------------|
| `eea`               | `1` (positive) \| `0` (negative) | Informs Adjust whether users installing the app are within the European Economic Area. Includes EU member states, Switzerland, Norway, Iceland, and Slovenia. |
| `ad_personalization`| `1` (positive) \| `0` (negative) | Informs Adjust whether users consented with being served personalized ads via Google Ads and/or Google Marketing Platform. This parameter also informs the `npa` parameter reserved for Google Marketing Platform. |
| `ad_user_data`      | `1` (positive) \| `0` (negative) | Informs Adjust whether users consented with their advertiser ID being leveraged for attribution purposes.         |

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustGranularOption GranularOptions;
GranularOptions.GranularOption.Add("eea", "1");
GranularOptions.GranularOption.Add("ad_personalization", "1");
GranularOptions.GranularOption.Add("ad_user_data", "1");
adjustThirdPartySharing.GranularOptions.Add("google_dma", GranularOptions);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

### <a id="partner-sharing-settings">Update partner sharing settings</a>

By default, Adjust shares all metrics with any partners you’ve configured in your app settings. You can use the Adjust SDK to update your third party sharing settings on a per-partner basis. To do this, call the `PartnerSharingSetting.Add` method by passing the partner sharing structure where you will need to set following parameters:

| Argument     | Data type | Description                                                |
|--------------|-----------|------------------------------------------------------------|
| `partnerName`| String    | The name of the partner. [Download the full list of available partners](https://assets.ctfassets.net/5s247im0esyq/5WvsJ7J7fGFUlfsFeGdalj/643651619adc3256acac7885ec60624d/modules.csv). |
| `key`        | String    | The metric to share with the partner.                      |
| `value`      | Boolean   | The user’s decision.                                       |

You can use the `key` to specify which metrics you want to disable or re-enable. If you want to enable/disable sharing all metrics, you can use the `all` key. The full list of available metrics is available below:

- `ad_revenue`
- `all`
- `attribution`
- `update`
- `att_update`
- `cost_update`
- `event`
- `install`
- `reattribution`
- `reattribution_reinstall`
- `reinstall`
- `rejected_install`
- `rejected_reattribution`
- `sdk_click`
- `sdk_info`
- `session`
- `subscription`
- `uninstall`

When you set a `false` value against a metric for a partner, Adjust stops sharing the metric with the partner.

> Tip: If you only want to share a few metrics with a partner, you can pass the `all` key with a `false` value to disable all sharing and then pass individual metrics with a `true` value to limit what you share.

Examples:

If you want to stop sharing all metrics with a specific partner, pass the `all` key with a `false` value.

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustPartnerSharingSetting PartnerSettings;
PartnerSettings.PartnerSharingSetting.Add("all", false);
adjustThirdPartySharing.PartnerSharingSettings.Add("PartnerA", PartnerSettings);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

To re-enable sharing, pass the `all` key with a `true` value.

```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustPartnerSharingSetting PartnerSettings;
PartnerSettings.PartnerSharingSetting.Add("all", true);
adjustThirdPartySharing.PartnerSharingSettings.Add("PartnerA", PartnerSettings);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

You can stop or start sharing specific metrics by calling the `PartnerSharingSetting.Add` method multiple times with different keys. For example, if you only want to share event information with a partner, you can pass:

- `all` with a `false` value to disable sharing all information
- `event` with a `true` value to enable event sharing

> Note: Specific keys always take priority over `all`. If you pass `all` with other keys, the individual key values override the `all` setting.


```cpp
FAdjustThirdPartySharing adjustThirdPartySharing;
adjustThirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;

FAdjustPartnerSharingSetting PartnerSettings;
PartnerSettings.PartnerSharingSetting.Add("all", false);
PartnerSettings.PartnerSharingSetting.Add("event", true);
adjustThirdPartySharing.PartnerSharingSettings.Add("PartnerA", PartnerSettings);

UAdjust::TrackThirdPartySharing(adjustThirdPartySharing);
```

### <a id="measurement-consent"></a>Consent measurement for specific users

If you’re using [Data Privacy settings](https://help.adjust.com/en/article/manage-data-collection-and-retention) in your Adjust dashboard, you need to set up the Adjust SDK to work with them. This includes settings such as consent expiry period and user data retention period.

To toggle this feature, call the `TrackMeasurementConsent` method of `UAdjust` class with the boolean argument which indicates whether consent measurement is enabled (`true`) or not (`false`).

When enabled, the SDK communicates the data privacy settings to Adjust’s servers. Adjust’s servers then applies your data privacy rules to the user. The Adjust SDK continues to work as expected.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void TrackMeasurementConsent(bool MeasurementConsent);
```

### <a id="coppa-compliance"></a>COPPA compliance

f you need your app to be compliant with the Children’s Online Privacy Protection Act (COPPA), set the `IsCoppaComplianceEnabled` field on your `FAdjustConfig` structure to `true` before initializing the SDK. This performs the following actions:

1. Disables third-party sharing **before** the user launches their first `session`.
2. Prevents the SDK from reading device and advertising IDs (for example: `gps_adid`, `idfa`, and `android_id`).

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsCoppaComplianceEnabled = false;
```

By default, the SDK is not being launched in COPPA compliance mode.

### <a id="play-store-kids-apps"></a>Play Store kids apps

If your app targets users under the age of 13, and the install region **isn’t** the USA, you need to mark it as a Kids App. This prevents the SDK from reading device and advertising IDs (for example: `idfa`, `gps_adid` and `android_id`).

To mark your app as a Play Store Kids App, set the `IsPlayStoreKidsComplianceEnabled` field on your `FAdjustConfig` structure to `true` before initializing the SDK.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsPlayStoreKidsComplianceEnabled = false;
```

By deafult, the SDK is not being launched in Play Store Kids compliance mode.

### <a id="deeplinking"></a>Deep linking

If you are using the Adjust campaign link URL with an option to deep link into your app from the URL, there is the possibility to get information about the deep link URL and its content. Hitting the URL can happen when the user has your app already installed (standard deep linking scenario) or if they don't have the app on their device (deferred deep linking scenario).

### <a id="deeplinking-standard"></a>Standard deep linking scenario

The standard deep linking scenario is a platform specific feature in which an app gets opened when user clicks on the deep link. This guide is going to assume that you are aware how deep linking should be set up in your app for both, iOS and Android platforms.

### <a id="deeplinking-deferred"></a>Deferred deep linking scenario

While deferred deep linking is not supported out of the box on Android and iOS, our Adjust SDK makes it possible.

In order to get information about the URL content in a deferred deep linking scenario, you should set a callback method on the `UAdjustDelegates` object to be able to 

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeferredDeeplinkDelegate, const FString&, Deeplink);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnDeferredDeeplinkDelegate OnDeferredDeeplinkDelegate;
```

In a deferred deep linking scenario, there is one additional setting which can be set on the `FAdjustConfig` structure. Once the Adjust SDK gets the deferred deep link information, you have the possibility to choose whether our SDK should open this URL or not. You can influence default SDK behavior by setting the `IsDeferredDeeplinkOpeningEnabled` field on the `FAdjustConfig` instance to `false`

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsDeferredDeeplinkOpeningEnabled = true;
```

If nothing is set, **the Adjust SDK will always try to launch the URL by default**.

### <a id="deeplinking-reattribution"></a>Reattribution via deep links

Adjust enables you to run re-engagement campaigns through deep links.

If you are using this feature, in order for your user to be properly reattributed, you need to make one additional call to the Adjust SDK in your app.

Once you have received deep link content information in your app, add a call to the `ProcessDeeplink` method of `UAdjust` class. By making this call, the Adjust SDK will try to find if there is any new attribution information inside of the deep link. If there is any, it will be sent to the Adjust backend. If your user should be reattributed due to a click on the Adjust campaign link URL with deep link content, you will see the [attribution callback](#attribution-callback) in your app being triggered with new attribution info for this user.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void ProcessDeeplink(const FAdjustDeeplink& Deeplink);
```

```cpp
FAdjustDeeplink adjustDeeplink;
adjustDeeplink.Deeplink = "your-app-scheme://deep-link-content";
UAdjust::ProcessDeeplink(adjustDeeplink);
```

### <a id="short-links-resolution"></a>Resolve Adjust short links

To resolve an Adjust shortened deep link, instantiate an `FAdjustDeeplink` structure with your shortened deep link and pass it to the `ProcessAndResolveDeeplink` method of the `UAdjust` class. In addition to this, you need to declare a callback method on the `UAdjustDelegates` object that will get triggered once the link gets resolved.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void ProcessAndResolveDeeplink(const FAdjustDeeplink& Deeplink);
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeeplinkResolutionDelegate, const FString&, ResolvedLink);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnDeeplinkResolutionDelegate OnDeeplinkResolutionDelegate;
```

> Note: If the link passed to the `ProcessAndResolveDeeplink` method was shortened, the callback function receives the extended original link. Otherwise, the callback function receives the link you passed.

### <a id="app-tracking-transparency"></a>App Tracking Transparency

> Note: This feature exists only in iOS platform.

If you want to record the device’s ID for Advertisers (IDFA), you must display a prompt to get your user’s authorization. To do this, you need to include Apple’s App Tracking Transparency (ATT) framework in your app. The Adjust SDK stores the user’s authorization status and sends it to Adjust’s servers with each request.

Below, you can find the list of possible ATT status values:

| Status                                    | Code | Description                                                          |
|-------------------------------------------|------|----------------------------------------------------------------------|
| `ATTrackingManagerAuthorizationStatusNotDetermined` | `0`  | The user hasn’t responded to the access prompt yet                   |
| `ATTrackingManagerAuthorizationStatusRestricted`   | `1`  | Access to app-related data is blocked at the device level            |
| `ATTrackingManagerAuthorizationStatusDenied`       | `2`  | The user has denied access to app-related data for device measurement |
| `ATTrackingManagerAuthorizationStatusAuthorized`   | `3`  | The user has approved access to app-related data for device measurement |

> Note: You might receive a status code of -1 if the SDK is unable to retrieve the ATT (App Tracking Transparency) status.

### <a id="att-wrapper"></a>ATT authorization wrapper

**Note**: This feature exists only in iOS platform.

The Adjust SDK contains a wrapper around [Apple’s requestTrackingAuthorizationWithCompletionHandler: method](https://developer.apple.com/documentation/apptrackingtransparency/attrackingmanager/3547037-requesttrackingauthorizationwith). You can use this wrapper if you don’t want to use the ATT prompt.

The callback method triggers when your user responds to the consent dialog. This method sends the user’s consent status code to Adjust’s servers. You can define responses to each status code within the callback function.

You must specify text content for the ATT. To do this, add your text to the `NSUserTrackingUsageDescription` key in your `Info.plist` file.

```xml
 <key>NSUserTrackingUsageDescription</key>
 <string>Your custom message explaining why is access to IDFA necessary.</string>
```

You can trigger ATT prompt via Adjust SDK wrapper method like described below.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void RequestAppTrackingAuthorization();
```

```cpp
UAdjust::RequestAppTrackingAuthorization();
```

In order to obtain the ATT prompt response, you need to define a callback method and set it on `UAdjustDelegates` object before invoking the `RequestAppTrackingAuthorization` method.

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestTrackingAuthorizationDelegate, const int, AuthorizationStatus);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnRequestTrackingAuthorizationDelegate OnRequestTrackingAuthorizationDelegate;
```

### <a id="att-status-getter"></a>Get current authorization status

You can retrieve a user’s current authorization status at any time. Call the `GetAppTrackingAuthorizationStatus` method to return the authorization status and make sure to set the callback method on `UAdjustDelegates` object before you make this call.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetAppTrackingAuthorizationStatus();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusGetterDelegate, const int, AuthorizationStatus);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAuthorizationStatusGetterDelegate OnAuthorizationStatusGetterDelegate;
```

### <a id="att-waiting-interval"></a>ATT prompt waiting interval

If your app includes an onboarding process or a tutorial, you may want to delay sending your user’s ATT consent status until after the user has completed this process. To do this, you can set the `AttConsentWaitingInterval` method of your `FAdjustConfig` structure to delay the sending of data for up to **360 seconds** to give the user time to complete the initial onboarding. After the timeout ends or the user sets their consent status, the SDK sends all information it has recorded during the delay to Adjust’s servers along with the user’s consent status.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
int AttConsentWaitingInterval = 0;
```

### <a id="skan-framework"></a>SKAdNetwork and conversion values

> Important: This feature is only available on devices running iOS 14 and above.

SKAdNetwork is Apple’s attribution framework for app install and reinstall attribution. The SKAdNetwork workflow goes like this:

1. Apple gathers attribution information and notifies the relevant ad network.
2. The network sends a postback with this information to Adjust.
3. Adjust displays SKAdNetwork data in [Datascape](https://help.adjust.com/en/suite/article/datascape).

### <a id="skan-disable"></a>Disable SKAdNetwork communication

The Adjust SDK communicates with SKAdNetwork by default. The SDK registers for SKAdNetwork attribution upon initialization.

You can change this behavior by setting the `IsSkanAttributionEnabled` field of your `FAdjustConfig` structure to `false`.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsSkanAttributionEnabled = true;
```

### <a id="skan-postbacks"></a>Set up direct install postbacks

> Note: Direct install postbacks contain only SKAdNetwork information. Information such as campaign data isn’t included in these postbacks.

You can configure your app to send a copy of winning SKAdNetwork callbacks to Adjust. This enables you to use SKAdNetwork information in your analytics.

To set up direct install postbacks, you need to add the Adjust callback URL to your `Info.plist` file:

```xml
<key>NSAdvertisingAttributionReportEndpoint</key>
<string>https://adjust-skadnetwork.com</string>
```

> See also: See Apple’s guide on [Configuring an Advertised App](https://developer.apple.com/documentation/storekit/skadnetwork/configuring_an_advertised_app) for more information.

### <a id="adrevenue-recording"></a>Record ad revenue information

You can record ad revenue for [supported network partners](https://help.adjust.com/en/article/ad-revenue) using the Adjust SDK.

> Important: You need to perform some extra setup steps in your Adjust dashboard to measure ad revenue. Contact your Technical Account Manager or support@adjust.com to get started.

To send ad revenue information with the Adjust SDK, you need to instantiate an `FAdjustAdRevenue` structure. This structure contains variables that are sent to Adjust when ad revenue is recorded in your app.

You can set the following parameters:

- `Source`: The source of the ad revenue. This parameter is mandatory. See the table below for available sources.

| Argument                     | Ad revenue Source        |
|------------------------------|--------------------------|
| `"applovin_max_sdk"`         | AppLovin MAX            |
| `"admob_sdk"`                | AdMob                   |
| `"ironsource_sdk"`           | ironSource              |
| `"admost_sdk"`               | AdMost                  |
| `"unity_sdk"`                | Unity                   |
| `"helium_chartboost_sdk"`    | Helium Chartboost       |
| `"adx_sdk"`                  | Ad(X)                   |
| `"tradplus_sdk"`             | TradPlus                |
| `"topon_sdk"`                | TopOn                   |
| `"publisher_sdk"`            | Generic source          |

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Source;
```

### <a id="adrevenue-amount"></a>Ad revenue amount

To send the ad revenue amount, set the `Revenue` and `Currency` fields of your `FAdjustAdRevenue` structure:

- `Revenue`: The amount of revenue
- `Currency`: The 3 character [ISO 4217 code](https://www.iban.com/currency-codes) of your reporting currency

> See also: Check the [guide to recording purchases in different currencies](https://help.adjust.com/en/article/currency-conversion) for more information.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
double Revenue = 0.0;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString Currency;
```

### <a id="adrevenue-network"></a>Ad revenue network

To record the network associated with the ad revenue, set `AdRevenueNetwork` field of your `FAdjustAdRevenue` structure with the network name.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString AdRevenueNetwork;
```

### <a id="adrevenue-unit"></a>Ad revenue unit

To send the ad revenue unit, set `AdRevenueUnit` field of your `FAdjustAdRevenue` structure with the unit value.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString AdRevenueUnit;
```

### <a id="adrevenue-placement"></a>Ad revenue placement

To send the ad revenue placement, set `AdRevenuePlacement` field of your `FAdjustAdRevenue` structure with the placement value.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString AdRevenuePlacement;
```

### <a id="adrevenue-impressions"></a>Ad impressions count

To send the number of recorded ad impressions, set `AdImpressionsCount` field of your `FAdjustAdRevenue` structure with the number of ad impressions.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
int AdImpressionsCount = 0;
```

### <a id="adrevenue-callback-params"></a>Ad revenue callback parameters

Similar to how one can set [event callback parameters](#event-callback-params), the same can be done for ad revenue:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
TMap<FString, FString> CallbackParameters;
```

### <a id="adrevenue-partner-params"></a>Ad revenue partner parameters

Similar to how one can set [event partner parameters](#event-partner-params), the same can be done for ad revenue:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
TMap<FString, FString> PartnerParameters;
```

### <a id="device-ids"></a>Device IDs

The Adjust SDK contains helper methods that return device information. Use these methods to add details to your callbacks and improve your reporting.

### <a id="idfa"></a>IDFA

To obtain the IDFA, call the function `GetIdfa` of the `UAdjust` class. You need to set callback method on the `UAdjustDelegates` object where the IDFA value will be delivered to.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetIdfa();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIdfaGetterDelegate, const FString&, Idfa);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnIdfaGetterDelegate OnIdfaGetterDelegate;
```

### <a id="idfv"></a>IDFV

To obtain the IDFV, call the function `GetIdfv` of the `UAdjust` class. You need to set callback method on the `UAdjustDelegates` object where the IDFV value will be delivered to.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetIdfv();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIdfvGetterDelegate, const FString&, Idfv);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnIdfvGetterDelegate OnIdfvGetterDelegate;
```

### <a id="gps-adid"></a>Google advertising identifier

To obtain Google advertising ID, call the function `GetGoogleAdId` of the `UAdjust` class. You need to set callback method on the `UAdjustDelegates` object where the Google advertising ID value will be delivered to.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetGoogleAdId();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoogleAdIdGetterDelegate, const FString&, GoogleAdId);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnGoogleAdIdGetterDelegate OnGoogleAdIdGetterDelegate;
```

### <a id="fire-adid"></a>Amazon advertising identifier

If you need to obtain the Amazon advertising ID, you can call the `GetAmazonAdId` method of the `UAdjust` class. You need to set callback method on the `UAdjustDelegates` object where the Amazon advertising ID value will be delivered to.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetAmazonAdId();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmazonAdIdGetterDelegate, const FString&, AmazonAdId);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAmazonAdIdGetterDelegate OnAmazonAdIdGetterDelegate;
```

### <a id="adid"></a>Adjust device identifier

For every device with your app installed on it, the Adjust backend generates a unique **Adjust device identifier** (**adid**). In order to obtain this identifier, you can make a call to `GetAdid` method of the `UAdjust` class. You need to set callback method on the `UAdjustDelegates` object where the Adjust device ID value will be delivered to.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void GetAdid();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAdidGetterDelegate, const FString&, Adid);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnAdidGetterDelegate OnAdidGetterDelegate;
```

**Note**: Information about the **adid** is available after app installation has been recorded by the Adjust backend. From that moment on, the Adjust SDK has information about the device **adid** and you can access it with this method. So, **it is not possible** to access the **adid** value before the SDK has been initialised and installation of your app has been successfully recorded.

### <a id="session-event-callbacks"></a>Session and event callbacks

You can register a callback to be notified of successful and failed recorded events and/or sessions.

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

### <a id="disable-sdk"></a>Disable the SDK

You can disable the Adjust SDK from recording any activity by invoking the method `Disable` of the `UAdjust` class. This setting is **remembered between sessions**.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void Disable();
```

You can verify if the Adjust SDK is currently active with the method `IsEnabled` of the `UAdjust` class. To obtain this value, you need to define callback on the `UAdjustDelegates` object to obtain it.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void IsEnabled();
```

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsEnabledGetterDelegate, bool, IsEnabled);

// ...

UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
FOnIsEnabledGetterDelegate OnIsEnabledGetterDelegate;
```

It is always possible to activate the Adjust SDK by invoking `Enable` method of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void Enable();
```

### <a id="offline-mode"></a>Offline mode

You can put the Adjust SDK in offline mode to suspend transmission to our servers, while still retaining recorded data to be sent later. While in offline mode, all information is saved in a file, so be careful not to trigger too many events while in offline mode.

You can activate offline mode by calling the method `WwitchToOfflineMode` of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SwitchToOfflineMode();
```

Conversely, you can deactivate the offline mode by calling `SwitchBackToOnlineMode` method of the `UAdjust` class.

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SwitchBackToOnlineMode();
```

When the Adjust SDK is put back in online mode, all saved information is sent to our servers with the correct timestamps.

Unlike disabling the SDK, this setting is **not remembered between sessions**. This means that the SDK is in online mode whenever it is started, even if the app was terminated in offline mode.

### <a id="background-sending"></a>Sending from background 

The default behaviour of the Adjust SDK is to **pause sending HTTP requests while the app is in the background**. You can change this in your `FAdjustConfig` structure by setting the `IsSendingInBackgroundEnabled` field to `true`.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsSendingInBackgroundEnabled = false;
```

If nothing is set, sending in background is **disabled by default**.

### <a id="external-device-id"></a>Set external device ID

> **Note** If you want to use external device IDs, please contact your Adjust representative. They will talk you through the best approach for your use case.

An external device identifier is a custom value that you can assign to a device or user. They can help you to recognize users across sessions and platforms. They can also help you to deduplicate installs by user so that a user isn't counted as multiple new installs.

You can also use an external device ID as a custom identifier for a device. This can be useful if you use these identifiers elsewhere and want to keep continuity.

Check out our [external device identifiers article](https://help.adjust.com/en/article/external-device-identifiers) for more information.

To set an external device ID, assign the identifier to the `ExternalDeviceId` field of your `FAdjustConfig` structure. Do this before you initialize the Adjust SDK.

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
FString ExternalDeviceId;
```

> **Important**: You need to make sure this ID is **unique to the user or device** depending on your use-case. Using the same ID across different users or devices could lead to duplicated data. Talk to your Adjust representative for more information.

If you want to use the external device ID in your business analytics, you can pass it as a session callback parameter. See the section on [session callback parameters](#session-callback-params) for more information.

You can import existing external device IDs into Adjust. This ensures that the backend matches future data to your existing device records. If you want to do this, please contact your Adjust representative.

### <a id="push-token"></a>Push token

To send us the push notification token, add the following call to Adjust **whenever you get your token in the app or when it gets updated**:

```cpp
UFUNCTION(BlueprintCallable, Category = "Adjust")
static void SetPushToken(const FString& PushToken);
```

Push tokens are used for Audience Builder and client callbacks, and they are required for the uninstall detection feature.

### <a id="disable-ad-services"></a>Disable AdServices information reading

> Note: This is iOS only feature.

The SDK is enabled by default to try to communicate with `AdServices.framework` on iOS in order to try to obtain attribution token which is later being used for handling Apple Search Ads attribution. In case you would not like Adjust to show information from Apple Search Ads campaigns, you can disable this in the SDK by setting `IsAdServicesEnabled` field of your `FAdjustConfig` structure to `false`:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
bool IsAdServicesEnabled = true;
```

## <a id="license"></a>License

The Adjust SDK is licensed under the MIT License.

Copyright (c) 2018-Present Adjust GmbH, http://www.adjust.com

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
