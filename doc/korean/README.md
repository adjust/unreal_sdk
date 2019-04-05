요약
---

Adjust™의 Unreal Engine SDK에 관한 문서입니다. [Adjust.com](http://adjust.com)에서 Adjust™에 대한 정보를 더 자세히 알아보세요.

목차
---

* [기본 연동](#basic-integration) 
  * [SDK 설치](#sdk-get)
  * [프로젝트에 SDK 추가](#sdk-add)
  * [앱에 SDK 연동](#sdk-integrate)
  * [Adjust 로깅](#sdk-logging)

* [부가 기능](#additional-features) 
  * [이벤트 추적](#event-tracking) 
    * [매출 추적](#revenue-tracking)
    * [매출 중복 제거](#revenue-deduplication)
    * [콜백 파라미터](#callback-parameters)
    * [파트너 파라미터](#partner-parameters)
    * [콜백 ID](#callback-id)

  * [세션 파라미터](#session-parameters) 
    * [세션 콜백 파라미터](#session-callback-parameters)
    * [세션 파트너 파라미터](#session-partner-parameters)
    * [시작 지연](#delay-start)

  * [어트리뷰션 콜백](#attribution-callback)
  * [세션 및 이벤트 콜백](#session-event-callbacks)
  * [트래킹 비활성화](#disable-tracking)
  * [오프라인 모드](#offline-mode)
  * [이벤트 버퍼링](#event-buffering)
  * [GDPR 잊혀질 권리](#gdpr-forget-me)
  * [SDK 서명](#sdk-signature)
  * [백그라운드 추적](#background-tracking)
  * [기기 ID](#device-ids) 
    * [iOS 광고 ID](#di-idfa)
    * [Google Play 서비스 광고 ID](#di-gps-adid)
    * [Amazon 광고 ID](#di-fire-adid)
    * [Adjust 기기 식별자](#di-adid)

  * [사용자 어트리뷰션](#user-attribution)
  * [푸시 토큰](#push-token)
  * [사전 설치 트래커](#pre-installed-trackers)

* [라이센스](#license)

<a id="user-content-basic-integration"></a>기본 연동
--------------------------------------

Adjust SDK를 Unreal Engine 프로젝트에 연동하는 데 필요한 최소한의 단계입니다.

### <a id="user-content-sdk-get"></a>SDK 설치

Adjust [릴리스 페이지](https://github.com/adjust/unreal_sdk/releases)에서 최신 버전을 다운로드합니다.

### <a id="user-content-sdk-add"></a>프로젝트에 SDK 추가

Adjust SDK 플러그인은 앞서 다운로드한 아카이브 내 `Adjust` 폴더에 있습니다. 앱 `Plugins` 폴더 안의 `Adjust` 폴더를 복사합니다.

앱의 `APPNAME.Build.cs` 내 `PublicDependencyModuleNames` 배열에 `Adjust`를 의존 요소로 추가합니다. 파일:

    PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Adjust" });

### <a id="user-content-sdk-integrate"></a>앱에 SDK 연동

앱 내부에서 가능한 한 빨리 Adjust SDK를 초기화하는 것이 좋습니다. `Adjust` 클래스의 `Initialize` 메서드를 호출하여 초기화할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void Initialize\(const FAdjustConfig& Config\);
```

SDK를 초기화하려면 최소한 `FAdjustConfig` 구조의 속성을 다음과 같이 설정해야 합니다.

* `AppToken` \- Adjust 대시보드에서 얻을 수 있는 앱 토큰입니다.
* `Environment` \- Adjust SDK를 시작할 환경입니다\(`Sandbox` 또는 `Production`\).

**중요:** 사용자 또는 다른 사람이 앱을 테스트하는 경우 환경 값은 `Sandbox`로만 설정할 수 있습니다. 앱을 퍼블리시할 준비가 완료되면 환경 설정을 `Production`으로 변경하고, 앱을 개발하고 테스트하기 시작할 때 다시 `Sandbox`로 설정하세요. 테스트 기기로 인해 발생하는 테스트 트래픽과 실제 트래픽을 구분하기 위해 환경모드를 사용하실 수 있으니, 상황에 알맞은 설정을 적용해야 합니다.

### <a id="user-content-sdk-logging"></a>Adjust 로깅\(logging\)

다음 값 중 하나를 사용하여 `FAdjustConfig` 구조 인스턴스에 `LogLevel` 필드를 설정함으로써 테스트에서 확인하는 로그 수를 늘리거나 줄일 수 있습니다.

    Verbose   // enable all logging
    Debug     // enable more logging
    Info      // default
    Warn      // disable info logging and below
    Error     // disable warnings as well
    Assert    // disable errors as well
    Suppress  // disable all log output

Android에서는 `Adjust` 태그가 있는 줄을 찾아 Adjust SDK로부터 발생하는 로그 출력을 확인할 수 있습니다. iOS에서는 `[Adjust]` 문자열로 시작하는 부분을 확인하여 Adjust SDK 로그 줄을 찾을 수 있습니다.

<a id="user-content-additional-features"></a>부가 기능
----------------------------------------

Adjust SDK를 프로젝트에 연동하면 다음 기능을 활용할 수 있습니다.

### <a id="user-content-event-tracking"></a>이벤트 추적

Adjust를 사용하여 원하는 모든 이벤트를 추적할 수 있습니다.

[대시보드](http://adjust.com)에 `abc123`이라는 새 이벤트 토큰을 생성하면 이 토큰을 `FAdjustEvent` 구조의 `EventToken` 필드에 배정하고 `Adjust` 클래스의 `TrackEvent` 메서드를 호출할 수 있습니다.

```
// Adjust method to invoke for event tracking.
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void Initialize\(const FAdjustConfig& Config\);
```

```
// FAdjustEvent structure EventToken member.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString EventToken;
```

### <a id="user-content-revenue-tracking"></a>매출 추적

사용자가 광고를 누르거나 인앱 결제를 진행하여 매출을 창출할 수 있다면 해당 매출을 추적할 수도 있습니다. 광고를 한 번 누르는 행위에 €0\.01의 가치가 있다고 가정해 보겠습니다. `FAdjustEvent` 구조에서 이 정보를 `Revenue` 및 `Currency` 필드에 설정하면 이러한 매출을 추적할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
float Revenue;
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Currency;
```

사용자가 통화 토큰을 설정하면 Adjust는 사용자의 선택에 따라 발생 매출을 보고 매출로 자동 전환합니다. [여기](https://docs.adjust.com/en/event-tracking/#tracking-purchases-in-different-currencies)에서 통화 전환에 대해 자세히 알아보세요.

[이벤트 추적 가이드](https://docs.adjust.com/en/event-tracking)에서 매출 및 이벤트 추적에 대해 자세히 알아볼 수 있습니다.

### <a id="user-content-revenue-deduplication"></a>매출 중복 제거

중복되는 매출을 추적하는 것을 방지하기 위해 트랜잭션 ID를 선택적으로 추가할 수도 있습니다. 마지막 열 개의 전환 ID가 보관되며, 중복되는 전환 ID가 있는 매출 이벤트는 건너뛰게 됩니다. 이러한 방식은 인앱 결제 트래킹에 활용하실 수 있습니다. 전환 ID는 `FAdjustEvent` 구조의 `TransactionId` 구성원에 배정될 수 있습니다.

인앱 결제를 추적하려는 경우, 전환이 완료되었을 때만 `TrackEvent`를 호출하십시오. 이렇게 하면 실제로 발생하지 않은 매출을 트래킹하는 것을 방지할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString TransactionId;
```

**참고** : 트랜잭션 ID는 iOS 용어입니다. 완료된 Android 인앱 결제를 위한 고유 ID는 **주문 ID** 라고 합니다.

### <a id="user-content-callback-parameters"></a>콜백 파라미터

[대시보드](http://adjust.com)에서 이벤트를 위한 콜백 URL을 등록할 수 있습니다. 그러면 Adjust는 이벤트가 추적될 때마다 해당 URL에 GET 요청을 보냅니다. 사용자는 이벤트를 추적하기 전에 `FAdjustEvent` 구조의 `CallbackParameters` 맵 구성원에 키\-값 쌍을 추가함으로써 콜백 파라미터를 이벤트에 추가할 수 있습니다. 그런 다음 Adjust는 이러한 파라미터를 사용자의 콜백 URL에 추가합니다.

예를 들어, 사용자가 이벤트를 위해 `http://www.adjust.com/callback` URL을 등록했으며 2개의 키\-값 쌍\(`("key", "value")` 및 `("foo", "bar")`\)을 `CallbackParameters` 구성원에 추가한다고 가정해 보겠습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
TMap<FString, FString> CallbackParameters;
```

이 경우, Adjust가 이벤트를 추적하여 다음으로 요청을 전송합니다.

    http://www.adjust.com/callback?key=value&foo=bar

Adjust는 iOS용 `{idfa}`나 Android용 `{gps_adid}` 등 파라미터 값으로 사용될 수 있는 다양한 placeholder를 지원합니다.  콜백 결과 에서 `{idfa}` 라는 placeholder는 현재 iOS 기기의 광고 ID로 대체되며 `{gps_adid}`는 현재 Android 기기의 Google 광고 ID로 대체됩니다. Adjust는 사용자의 커스텀 파라미터를 저장하지 않으며 콜백으로 전달 하기만 합니다. 또한 특정 이벤트에 대한 콜백 파라미터를 등록하지 않은 경우에는 이러한 파라미터를 읽지도 않습니다.

Adjust [콜백 가이드](https://docs.adjust.com/en/callbacks)에서 사용 가능한 값의 전체 목록을 비롯하여 URL 콜백을 사용하는 방법을 자세히 알아보실 수 있습니다.

### <a id="user-content-partner-parameters"></a>파트너 파라미터

Adjust 대시보드에서 활성화한 연동의 경우, 네트워크 파트너에게 전송할 파라미터를 추가할 수 있습니다.

파트너 파라미터는 위에서 언급한 콜백 파라미터와 유사하게 작동합니다. `FAdjustEvent` 구조의 `PartnerParameters` 맵 구성원에 키\-값 쌍을 추가하는 방식입니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
TMap<FString, FString> PartnerParameters;
```

Adjust의 [특별 파트너 가이드](https://docs.adjust.com/en/special-partners)에서 특별 파트너와 연동 방법에 대한 자세한 내용을 알아보실 수 있습니다.

### <a id="user-content-callback-id"></a>콜백 ID

추적할 각 이벤트에 커스텀 문자열 ID를 추가할 수도 있습니다. 이 ID는 이후에 이벤트 성공 및/또는 이벤트 실패 콜백에서 보고되며, 이를 통해 성공적으로 추적된 이벤트와 그렇지 않은 이벤트를 확인할 수 있습니다. `FAdjustEvent` 구조의 `CallbackId` 구성원에 값을 할당하여 이 ID를 설정할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString CallbackId;
```

### <a id="user-content-session-parameters"></a>세션 파라미터

일부 파라미터는 저장되어 Adjust SDK의 모든 이벤트 및 세션에 전송됩니다. 이러한 파라미터를 한 번 추가하면 로컬로 저장되기 때문에 다시 추가할 필요가 없습니다. 동일한 파라미터를 다시 추가해도 아무 일도 일어나지 않습니다.

이러한 세션 파라미터는 설치 중에도 전송될 수 있도록 Adjust SDK가 실행되기 전에 호출될 수 있습니다. 설치 시에 파라미터를 전송해야 하지만 필요한 값을 실행 이후에만 확보할 수 있는 경우, Adjust SDK의 첫 실행을 [연기](#delay-start)하면 됩니다.

### <a id="user-content-session-callback-parameters"></a>세션 콜백 파라미터

Adjust SDK의 모든 이벤트 또는 세션에서 전송될 [이벤트](#callback-parameters)를 위해 등록된 동일한 콜백 파라미터를 저장할 수 있습니다.

세션 콜백 파라미터는 이벤트 콜백 파라미터와 유사한 인터페이스를 가지지만, 키와 값을 이벤트에 추가하는 대신 호출을 통해 `Adjust` 클래스의 `AddSessionCallbackParameter` 메서드에 추가됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void AddSessionCallbackParameter\(const FString& Key, const FString& Value\);
```

세션 콜백 파라미터는 사용자가 이벤트에 추가한 콜백 파라미터와 병합됩니다. 이벤트에 추가된 콜백 파라미터는 세션 콜백 파라미터보다 높은 우선순위를 가집니다. 세션에서 추가된 것과 동일한 키로 콜백 파라미터를 이벤트에 추가하면 이벤트에 추가된 콜백 파라미터가 우선시됩니다.

원하는 키를 `Adjust` 클래스의 `RemoveSessionCallbackParameter` 메서드에 전달하여 특정 세션 콜백 파라미터를 삭제할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void RemoveSessionCallbackParameter\(const FString& Key\);
```

세션 콜백 파라미터에서 모든 키와 값을 삭제하려면 `Adjust` 클래스의 `ResetSessionCallbackParameters` 메서드로 재설정하면 됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void ResetSessionCallbackParameters\(\);
```

### <a id="user-content-session-partner-parameters"></a>세션 파트너 파라미터

Adjust SDK의 모든 이벤트 또는 세션마다 전송되는 [세션 콜백 파라미터](#session-callback-parameters)가 있는 것처럼, 세션 파트너 파라미터도 있습니다. 이러한 파라미터는 사용자의 Adjust [대시보드](http://adjust.com)에 연동되고 활성화된 모든 네트워크 파트너에 전송됩니다.

세션 파트너 파라미터는 이벤트 파트너 파라미터와 유사한 인터페이스를 가지지만, 키와 값을 이벤트에 추가하는 대신 호출을 통해 `Adjust` 클래스의 `AddSessionPartnerParameter` 메서드에 추가됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void AddSessionPartnerParameter\(const FString& Key, const FString& Value\);
```

세션 파트너 파라미터는 사용자가 이벤트에 추가한 파트너 파라미터와 병합됩니다. 이벤트에 추가된 파트너 파라미터는 세션 파트너 파라미터보다 높은 우선순위를 가집니다. 즉, 세션에서 추가된 것과 동일한 키로 파트너 파라미터를 이벤트에 추가하면 이벤트에 추가된 파트너 파라미터가 우선시됩니다.

원하는 키를 `Adjust` 클래스의 `RemoveSessionPartnerParameter` 메서드에 전달하여 특정 세션 파트너 파라미터를 삭제할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void RemoveSessionPartnerParameter\(const FString& Key\);
```

세션 파트너 파라미터에서 모든 키와 값을 삭제하려면 `Adjust` 클래스의 `ResetSessionPartnerParameters` 메서드로 재설정하면 됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void ResetSessionPartnerParameters\(\);
```

### <a id="user-content-delay-start"></a>시작 지연

Adjust SDK의 시작을 지연시키면 앱이 고유 ID와 같은 세션 파라미터를 획득할 시간이 확보되므로, 세션 파라미터를 설치 시에 전송할 수 있게 됩니다.

`FAdjustConfig` 구조의 `DelayStart` 구성원을 사용하여 초기 지연 시간을 초 단위로 설정하세요.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString DelayStart;
```

이 시간이 지나거나 그 동안 `Adjust` 클래스의 `SendFirstPackages` 메서드를 호출하면 모든 세션 파라미터가 지연된 설치 세션 및 이벤트에 추가되며 Adjust SDK가 평소대로 되돌아갑니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void SendFirstPackages\(\);
```

**Adjust SDK의 최대 시작 지연 시간은 10초입니다** .

### <a id="user-content-attribution-callback"></a>어트리뷰션 콜백

Adjust는 사용자에게 어트리뷰션의 변동 사항에 대한 콜백을 전송할 수 있습니다. 어트리뷰션에는 다양한 소스가 관련되어 있기 때문에 이 정보는 즉각적으로 제공될 수 없습니다.

어트리뷰션 콜백은 `AdjustDelegates` 클래스에 있으며 다음 서명을 갖습니다.

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnAttributionChangedDelegate, const FAdjustAttribution&, Attribution\);
// ...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnAttributionChangedDelegate OnAttributionChangedDelegate;
```

앱 내에 설치하여 실행하고 나면 `FAdjustAttribution` 구조 인스턴스 내 다음 어트리뷰션 정보에 액세스할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString TrackerToken; // The tracker token of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString TrackerName;  // The tracker name of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Network;      // The network grouping level of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Campaign;     // The campaign grouping level of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adgroup;      // The ad group grouping level of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Creative;     // The creative grouping level of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString ClickLabel;   // The click label of the current attribution.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adid;         // The Adjust device identifier.
```

[해당되는 어트리뷰션 데이터 정책](https://github.com/adjust/sdks/blob/master/doc/attribution-data.md)을 고려해야 합니다.

### <a id="user-content-session-event-callbacks"></a>세션 및 이벤트 콜백

콜백을 등록하여 성공적으로 추적되었거나 실패한 이벤트 및/또는 세션에 대한 알림을 받을 수 있습니다.

성공적으로 추적된 이벤트에 대한 콜백 기능을 구현하려면 [상기 어트리뷰션 콜벡 섹션](#attribution-callback)과 동일한 단계를 따르세요.

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnEventSuccessDelegate, const FAdjustEventSuccess&, EventSuccess\);
// ...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnEventSuccessDelegate OnEventSuccessDelegate;
```

앱 내에 설치하여 실행하고 나면 `FAdjustEventSuccess` 구조 인스턴스 내 다음 정보에 액세스할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString EventToken;   // The event token.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString CallbackId;   // The callback ID of the event.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Message;      // The message from the server or the error logged by the SDK.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Timestamp;    // The timestamp from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adid;         // A unique device identifier provided by Adjust.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString JsonResponse; // The JSON object with the response from the server.
```

다음 콜백 기능은 실패한 이벤트에 사용됩니다.

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnEventFailureDelegate, const FAdjustEventFailure&, EventFailure\);
// ...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnEventFailureDelegate OnEventFailureDelegate;
```

앱 내에 설치하여 실행하고 나면 `FAdjustEventFailure` 구조 인스턴스 내 다음 정보에 액세스할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString EventToken;   // The event token.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString CallbackId;   // The callback ID of the event.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Message;      // The message from the server or the error logged by the SDK.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Timestamp;    // The timestamp from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adid;         // A unique device identifier provided by Adjust.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString JsonResponse; // The JSON object with the response from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
bool WillRetry;       // Indicates there will be an attempt to resend the package at a later time.
```

성공적으로 트래킹 된 세션의 경우:

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnSessionSuccessDelegate, const FAdjustSessionSuccess&, SessionSuccess\);
// ...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnSessionSuccessDelegate OnSessionSuccessDelegate;
```

앱 내에 설치하여 실행하고 나면 `FAdjustSessionSuccess` 구조 인스턴스 내 다음 정보에 액세스할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Message;      // The message from the server or the error logged by the SDK.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Timestamp;    // The timestamp from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adid;         // A unique device identifier provided by Adjust.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString JsonResponse; // The JSON object with the response from the server.
```

세션 실패의 경우:

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnSessionFailureDelegate, const FAdjustSessionFailure&, SessionFailure\);
//...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnSessionFailureDelegate OnSessionFailureDelegate;
```

앱 내에 설치하여 실행하고 나면 `FAdjustSessionFailure` 구조 인스턴스 내 다음 정보에 액세스할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Message;      // The message from the server or the error logged by the SDK.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Timestamp;    // The timestamp from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Adid;         // A unique device identifier provided by Adjust.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString JsonResponse; // The JSON object with the response from the server.
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
bool WillRetry;       // Indicates there will be an attempt to resend the package at a later time.
```

### <a id="user-content-disable-tracking"></a>추적 비활성화

`Adjust` 클래스의 `SetEnabled` 메서드를 호출하고 활성화된 파라미터를 `false`로 설정하여 Adjust SDK의 추적을 비활성화할 수 있습니다. 이 설정은 **세션 간에 유지되지만** , 첫 세션 이후에만 활성화될 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void SetEnabled\(bool Enable\);
```

Adjust SDK가 `Adjust` 클래스의 `IsEnabled()` 메서드를 사용하여 현재 활성화된 경우 검증할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static bool IsEnabled\(\);
```

`Adjust` 클래스의 `SetEnabled` 메서드를 호출하고 파라미터를 `true`로 설정하여 Adjust SDK를 활성화할 수 있습니다.

### <a id="user-content-offline-mode"></a>오프라인 모드

Adjust 서버에 대한 전송을 연기하고 추적된 데이터가 이후에 전송되도록 유지함으로써 Adjust SDK를 오프라인 모드로 설정할 수 있습니다. 오프라인 모드에서는 모든 정보가 파일에 저장되기 때문에 너무 많은 이벤트를 발생시키지 않는 것이 가장 좋습니다.

`Adjust` 클래스의 `SetOfflineMode` 메서드를 호출하고 파라미터를 `true`로 설정하여 오프라인 모드를 활성화할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void SetOfflineMode\(bool Offline\);
```

반대로 `Adjust` 클래스의 `SetOfflineMode` 메서드를 호출하고 파라미터를 `false`로 설정하여 오프라인 모드를 비활성화할 수 있습니다. Adjust SDK가 다시 온라인 모드가 되면 저장된 모든 정보가 정확한 시간 정보와 함께 Adjust 서버로 전송됩니다.

트래킹을 비활성화했을 때와는 다르게 **이 설정은 세션 간에 유지되지 않습니다** . 즉, 앱이 오프라인 모드에서 종료되었더라도 Adjust SDK는 항상 온라인 모드로 시작됩니다.

### <a id="user-content-event-buffering"></a>이벤트 버퍼링

앱이 이벤트 트래킹을 많이 사용하는 경우, 일부 HTTP 요청을 연기하여 HTTP 요청을 1분에 한 번씩 일괄로 보내고자 할 수 있습니다. `EventBuffering` 구성원을 `true` 로 설정하여 `FAdjustConfig` 구조 인스턴스를 통해 이벤트 버퍼링을 활성화할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
bool EventBuffering;
```

여기에 아무 것도 설정되지 않으면 이벤트 버퍼링이 **기본적으로 비활성화됩니다** .

### <a id="user-content-gdpr-forget-me"></a>GDPR 잊혀질 권리

EU의 개인정보보호법\(GDPR\) 제17조에 따라, 사용자는 잊혀질 권리\(Right to be Forgotten\)를 행사했음을 Adjust에 알릴 수 있습니다. 다음 메서드를 호출하면 Adjust SDK가 잊혀질 권리에 대한 사용자의 선택과 관련된 정보를 Adjust 백엔드에 보냅니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void GdprForgetMe\(\);
```

이 정보를 수신하면 Adjust는 해당 사용자의 데이터를 삭제하며 Adjust SDK는 해당 사용자에 대한 추적을 중지합니다. 이후 이 기기로부터의 요청은 Adjust에 전송되지 않습니다.

### <a id="user-content-sdk-signature"></a>SDK 서명

계정 관리자는 Adjust SDK 서명을 활성화해야 합니다. 이 기능의 사용에 관심이 있는 경우 Adjust 고객 지원팀\([support@adjust.com](mailto:support@adjust.com)\)에 문의하시기 바랍니다.

SDK 서명이 이미 계정에서 활성화되어 있으며 Adjust 대시보드의 앱 비밀에 액세스할 수 있는 경우, 아래 방법을 사용하여 SDK 서명을 앱에 연동하세요.

앱 비밀은 SDK를 초기화하기 전에 모든 비공개 파라미터\(`SecretId`, `Info1`, `Info2`, `Info3`, `Info4`\)를 `FAdjustConfig`구조 인스턴스에 전달하도록 설정되어 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString SecretId;
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Info1;
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Info2;
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Info3;
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
FString Info4;
```

### <a id="user-content-background-tracking"></a>백그라운드 추적

Adjust SDK는 기본적으로 **앱이 백그라운드에서 작동하는 동안 HTTP 요청 전송을 일시 중지** 하도록 설정되어 있습니다. `FAdjustConfig` 구조 인스턴스에서 `SendInBackground` 구성원을 `true`로 설정하면 이러한 설정을 변경할 수 있습니다.

```
UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
bool SendInBackground;
```

여기에 아무 것도 설정되지 않으면 백그라운드 전송이 **기본적으로 비활성화됩니다** .

### <a id="user-content-device-ids"></a>기기 ID

특정 서비스\(예: Google Analytics\)는 중복 보고를 방지하기 위해 기기 및 클라이언트 ID 통합을 요청합니다.

### <a id="user-content-di-idfa"></a>iOS 광고 ID

`Adjust` 클래스의 `GetIdfa()` 메서드를 호출하여 iOS 기기의 IDFA 값에 액세스할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static FString GetIdfa\(\);
```

### <a id="user-content-di-gps-adid"></a>Google Play 서비스 광고 ID

Adjust SDK를 사용하면 사용자의 앱이 실행되고 있는 Android 기기의 Google 광고 ID를 읽을 수 있습니다. 이를 위해서는 `FString` 파라미터를 수신하는 콜백 메서드를 설정해야 합니다. 이 콜백은 앞서 언급된 모든 콜백과 마찬가지로 `AdjustDelegates` 클래스의 일부입니다.

```
DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam\(FOnGoogleAdvertisingIdDelegate, const FString&, GoogleAdId\);
// ...
UPROPERTY\(BlueprintAssignable, Category = Adjust\)
FOnGoogleAdvertisingIdDelegate OnGoogleAdvertisingIdDelegate;
```

다음으로 `Adjust` 클래스의 `GetGoogleAdId()` 메서드를 호출합니다. 그러면 이전에 설정한 콜백의 Google 광고 ID 값을 확보할 수 있습니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void GetGoogleAdId\(\);
```

### <a id="user-content-di-fire-adid"></a>Amazon 광고 ID

Amazon 광고 ID를 확보하려면 `Adjust` 클래스의 `GetAmazonAdId()` 메서드를 호출하면 됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static FString GetAmazonAdId\(\);
```

### <a id="user-content-di-adid"></a>Adjust 기기 식별자

사용자의 앱이 설치된 각 기기에 대해 Adjust 백엔드는 고유한 **Adjust 기기 식별자** \( **adid** \)를 생성합니다. 이 식별자를 확보하려면 `Adjust` 클래스에서 다음 메서드를 호출하면 됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static FString GetAdid\(\);
```

**참고** : **adid** 정보는 Adjust 백엔드가 앱의 설치를 추적한 다음에만 확보할 수 있습니다. 그 다음부터는 Adjust SDK가 기기 **adid** 정보를 보유하게 되며, 이 메서드를 사용하여 해당 정보에 액세스할 수 있습니다. 따라서 SDK가 초기화되고 앱 설치가 추적되기 전까지는 **adid** 에 액세스할 수 **없습니다** .

### <a id="user-content-user-attribution"></a>사용자 어트리뷰션

어트리뷰션 콜백은 [어트리뷰션 콜백 섹션](#attribution-callback)에서 설명한 메서드를 통해 실행되며, 사용자의 어트리뷰션 값 변동 사항에 관련된 정보를 제공합니다. 사용자의 현재 어트리뷰션 값에 대한 정보에 언제라도 액세스할 수 있도록 하려면 `Adjust` 클래스의 다음 메서드를 호출하면 됩니다.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static FAdjustAttribution GetAttribution\(\);
```

**참고** : 사용자의 현재 어트리뷰션 값에 대한 정보는 Adjust 백엔드가 앱의 설치를 추적하고 초기 어트리뷰션 콜백이 실행된 다음에만 확보할 수 있습니다. 그 다음부터는 Adjust SDK가 사용자의 어트리뷰션 값을 보유하게 되며, 이 메서드를 사용하여 해당 정보에 액세스할 수 있습니다. 따라서 SDK가 초기화되고 초기 어트리뷰션 콜백이 실행되기 전까지는 사용자의 어트리뷰션 값에 액세스할 수 **없습니다** .

### <a id="user-content-push-token"></a>푸시 토큰

Adjust에 푸시 알림 토큰을 전송하려면 **앱이 토큰을 수신하거나 업데이트될 때** 다음 호출을 Adjust에 추가하세요.

```
UFUNCTION\(BlueprintCallable, Category = "Adjust"\)
static void SetPushToken\(const FString& PushToken\);
```

푸시 토큰은 Adjust Audience Builder 및 고객에게 전달되는 콜백에 사용되며 앱삭제 트래킹 기능에도 필요합니다.

### <a id="user-content-pre-installed-trackers"></a>사전 설치 트래커

Adjust SDK를 사용하여 본인의 앱이 사전에 설치된 기기가 있는 사용자를 인식하려면 다음 단계를 따르세요.

* [대시보드](http://adjust.com)에서 새 트래커를 생성합니다.

* `FAdjustConfig` 구조 인스턴스의 기본 트래커 구성원을 설정합니다.

  ```
  UPROPERTY\(EditAnywhere, BlueprintReadWrite, Category = "Adjust"\)
  FString DefaultTracker;
  ```

  `{TrackerToken}`을 1단계에서 생성한 트래커 토큰으로 교체합니다. 대시보드에는 트래커 URL이 표시됩니다\(`http://app.adjust.com/` 포함\). 소스 코드에서 전체 URL이 아닌 6글자의 토큰만 지정해야 합니다.
* 앱을 빌드하고 실행합니다. 앱의 로그 출력에서 다음과 같은 라인이 표시됩니다.

      Default tracker: 'abc123'

[adjust]:       http://adjust.com
[dashboard]:    http://adjust.com
[adjust.com]:   http://adjust.com

[releases]:             https://github.com/adjust/unreal_sdk/releases
[event-tracking]:       https://docs.adjust.com/en/event-tracking
[callbacks-guide]:      https://docs.adjust.com/en/callbacks
[special-partners]:     https://docs.adjust.com/en/special-partners
[attribution-data]:     https://github.com/adjust/sdks/blob/master/doc/attribution-data.md
[currency-conversion]:  https://docs.adjust.com/en/event-tracking/#tracking-purchases-in-different-currencies

<a id="user-content-license"></a>라이센스
---------------------------

Adjust SDK는 MIT 라이센스하에 사용이 허가됩니다.

Copyright \(c\) 2019 Adjust GmbH, http://www.adjust.com

다음 조건하에 본 소프트웨어와 관련 문서 파일\(이하 "소프트웨어"\)의 사본을 보유한 제3자에게
소프트웨어의 사용, 복사, 수정, 병합, 게시, 배포, 재실시권 및/또는 사본의 판매 등을 포함하여
소프트웨어를 제한 없이 사용할 수 있는 권한을
무료로 부여하며,
해당 제3자는 소프트웨어를 보유한 이에게
이러한 이용을 허가할 수 있습니다.

본 소프트웨어의 모든 사본 또는 상당 부분에
위 저작권 공고와 본 권한 공고를 포함해야 합니다.

소프트웨어는 "있는 그대로" 제공되며,
소프트웨어의 상품성과 특정 목적에의 적합성 및 비 침해성에 대해 명시적이거나 묵시적인 일체의 보증을 하지 않습니다.
저자 또는 저작권자는 본 소프트웨어나 이의 사용 또는
기타 소프트웨어 관련 거래로 인해 발생하는
모든 클레임, 손해 또는 기타 법적 책임에 있어서
계약 또는 불법 행위와 관련된 소송에 대해
어떠한 책임도 부담하지 않습니다.
