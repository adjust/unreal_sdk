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

[ios_sdk_v4.17.1]: https://github.com/adjust/ios_sdk/tree/v4.17.1
[ios_sdk_v4.18.3]: https://github.com/adjust/ios_sdk/tree/v4.18.3
[ios_sdk_v4.26.1]: https://github.com/adjust/ios_sdk/tree/v4.26.1
[ios_sdk_v4.28.0]: https://github.com/adjust/ios_sdk/tree/v4.28.0
