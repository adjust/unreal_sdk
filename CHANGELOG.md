### Version 5.4.0 (6th November 2025)
#### Added
- Added `JsonResponse` field (`FString`) to `FAdjustAttribution` where every key-value pair sent by the backend as part of the attribution response can be found.
- Added ability to disable SDK's interaction with `AppTrackingTransparency.framework` API. You can disable it by setting the `IsAppTrackingTransparencyUsageEnabled` property to `false` on your `FAdjustConfig` instance.
- Added ability to send organic search referrer together with deep link. You can pass it by setting the `Referrer` property of your `FAdjustDeeplink` instance.
- Added ability to initialize the SDK for the first session in delayed mode. You can start the SDK in the delayed mode by setting the `IsFirstSessionDelayEnabled` property to `true` on your `FAdjustConfig` instance. To end the delay, make sure to call `EndFirstSessionDelay` method of `UAdjust` instance. Additionally, you can use `EnableCoppaComplianceInDelay`, `DisableCoppaComplianceInDelay`, `SetExternalDeviceIdInDelay` methods, and on Android `EnablePlayStoreKidsComplianceInDelay`, `DisablePlayStoreKidsComplianceInDelay` methods.
- Added support for configuring store information via the `FAdjustStoreInfo` object. You can now specify the store name and store app ID using `StoreInfo` property on your `FAdjustConfig` instance. This enables the SDK to record the intended app store source during initialization.
- Added ability to set the maximum number of event deduplication IDs the SDK remembers. You can set this by setting the `EventDeduplicationIdsMaxSize` property on your `FAdjustConfig` instance.
- Added support for URL strategy and data residency. You can configure this by setting the `UrlStrategyDomains`, `ShouldUseSubdomains`, and `IsDataResidency` properties on your `FAdjustConfig` instance. This allows you to set either the country in which Adjust stores your data (data residency) or the endpoint to which the Adjust SDK sends traffic (URL strategy).
- Added support for preinstall tracking on Android. You can enable this by setting the `IsPreinstallTrackingEnabled` property to `true` and optionally setting the `PreinstallFilePath` property on your `FAdjustConfig` instance.
- Added support for subscription tracking. You can track App Store subscriptions on iOS using `TrackAppStoreSubscription` method and Play Store subscriptions on Android using `TrackPlayStoreSubscription` method of `UAdjust` instance.
- Added support for purchase verification. You can verify App Store purchases on iOS using `VerifyAppStorePurchase` method and Play Store purchases on Android using `VerifyPlayStorePurchase` method of `UAdjust` instance. Additionally, you can verify and track purchases in a single call using `VerifyAndTrackAppStorePurchase` and `VerifyAndTrackPlayStorePurchase` methods.
- Added ability to resolve adjust links behind other links. You can use the `ResolveLink` method of `UAdjust` instance to resolve shortened links and get the final destination URL.
- Added `GetLastDeeplink` method to `UAdjust` instance to retrieve the last processed deeplink.
- Added `TransactionId` and `ProductId` fields to `FAdjustEvent` for iOS, and `ProductId` and `PurchaseToken` fields for Android to support in-app purchase event tracking.
- Added `FbAppId` property to `FAdjustConfig` for Android to set Facebook App ID.

#### Fixed
- Fixed iOS getter callbacks not running on Unreal game thread, which caused ensure failures when using `TObjectIterator` in callbacks. All iOS completion handlers now properly marshal execution to the Unreal game thread using `AsyncTask`.
- Fixed `CostAmount` field in `FAdjustAttribution` not being initialized properly by adding default value.

#### Changed
- Updated logic to validate empty string parameters before passing them to native SDKs to prevent unnecessary native calls.
- Updated revenue and currency handling in `TrackEvent` method to properly handle cases where revenue is set but currency is empty, or both are empty.

#### Native SDKs
- [Android@v5.4.5][android_sdk_v5.4.5]
- [iOS@v5.4.6][ios_sdk_v5.4.6]

---

### Version 5.0.1 (17th February 2025)
#### Added
- Added sending of the additional parameter to improve troubleshooting of `SKAdNetwork` related issues.

#### Fixed
- Fixed occasional occurrences in which ATT waiting interval timer was not being started.
- Fixed occasional NPE occurrences when app was entering background (https://github.com/adjust/android_sdk/issues/630).

#### Changed
- Updated logic so that Unreal C++ callbacks are getting triggered inside of the `ENamedThreads::GameThread` (as they are on the Android platform).

#### Native SDKs
- [Android@v5.1.0][android_sdk_v5.1.0]
- [iOS@v5.1.0][ios_sdk_v5.1.0]

---

### Version 5.0.0 (30th January 2025)

We're excited to release our major new SDK version (v5). Among many internal improvements, our spoofing protection solution is now included out of the box, reinforcing our commitment to accurate, actionable, and fraud-free data.

To try out SDK v5 in your app, you can follow our new v4 to v5 [migration guide](./MIGRATION.md).

If you are a current Adjust client and have questions about SDK v5, please email [sdk-v5@adjust.com](mailto:sdk-v5@adjust.com).

---

### Version 4.28.0 (3rd April 2021)
#### Changed
- Removed native iOS legacy code.

#### Native SDKs
- [Android@v4.26.2][android_sdk_v4.26.2]
- [iOS@v4.28.0][ios_sdk_v4.28.0]

---

### Version 4.26.0 (6th February 2021)
#### Added
- Added `DisableThirdPartySharing` method to `Adjust` interface to allow disabling of data sharing with third parties outside of Adjust ecosystem.
- Added communication with `SKAdNetwork` framework by default on iOS 14.
- Added `HandleSkAdNetowrk` field to `AdjustConfig` to be able to switch off default communication with `SKAdNetwork` framework in iOS 14.
- Added wrapper method `RequestTrackingAuthorizationWithCompletionHandler` to `Adjust` to allow asking for user's consent to be tracked in iOS 14 and immediate propagation of user's choice to backend.
- Added wrapper method `UpdateConversionValue:` method to `Adjust` to allow updating SKAdNetwork conversion value via SDK API.
- Added handling of new `iAd.framework` error codes introduced in iOS 14.
- Added support for Apple Search Ads attribution with usage of `AdServices.framework`.
- Added `GetAppTrackingAuthorizationStatus` getter to `Adjust` instance to be able to get current app tracking status.
- Added `UrlStrategy` field to `AdjustConfig` class to allow selection of URL strategy for specific market.
- Added `PreinstallTracking` field to `AdjustConfig` to allow enabling of preinstall tracking (this feature is OFF by default).

#### Fixed
- Fixed compile errors due to having `EAdjustEnvironment` and `EAdjustLogLevel` enumerations not starting with 0.

#### Native SDKs
- [Android@v4.26.2][android_sdk_v4.26.2]
- [iOS@v4.26.1][ios_sdk_v4.26.1]

---

### Version 4.18.0 (2nd October 2019)
#### Added
- Added `TrackAdRevenue` method to `Adjust` interface to allow tracking of ad revenue. With this release added support for `MoPub` ad revenue tracking.

#### Fixed
- Fixed crashes when trying to convert not initialised `bool` values to `jboolean`.
- Fixed crashes when trying to initialise custom Adjust Java classes from `Adjust_UPL_Android.xml` if distribution build is using ProGuard.

#### Native SDKs
- [Android@v4.18.1][android_sdk_v4.18.1]
- [iOS@v4.18.3][ios_sdk_v4.18.3]

---

### Version 4.17.0 (24th January 2019)
#### Added
- Initial release of the Adjust SDK for Unreal Engine. Supported platforms: `Android` and `iOS`.

#### Native SDKs
- [Android@v4.17.0][android_sdk_v4.17.0]
- [iOS@v4.17.1][ios_sdk_v4.17.1]

[android_sdk_v4.17.0]: https://github.com/adjust/android_sdk/tree/v4.17.0
[android_sdk_v4.18.1]: https://github.com/adjust/android_sdk/tree/v4.18.1
[android_sdk_v4.26.2]: https://github.com/adjust/android_sdk/tree/v4.26.2
[android_sdk_v5.1.0]: https://github.com/adjust/android_sdk/tree/v5.1.0
[android_sdk_v5.4.5]: https://github.com/adjust/android_sdk/tree/v5.4.5

[ios_sdk_v4.17.1]: https://github.com/adjust/ios_sdk/tree/v4.17.1
[ios_sdk_v4.18.3]: https://github.com/adjust/ios_sdk/tree/v4.18.3
[ios_sdk_v4.26.1]: https://github.com/adjust/ios_sdk/tree/v4.26.1
[ios_sdk_v4.28.0]: https://github.com/adjust/ios_sdk/tree/v4.28.0
[ios_sdk_v5.0.1]: https://github.com/adjust/ios_sdk/tree/v5.0.1
[ios_sdk_v5.1.0]: https://github.com/adjust/ios_sdk/tree/v5.1.0
[ios_sdk_v5.4.6]: https://github.com/adjust/ios_sdk/tree/v5.4.6
