### Version 4.18.0 (xxth October 2019)
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

[ios_sdk_v4.17.1]: https://github.com/adjust/ios_sdk/tree/v4.17.1
[ios_sdk_v4.18.3]: https://github.com/adjust/ios_sdk/tree/v4.18.3
