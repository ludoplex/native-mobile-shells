# Subscriptions

## Boundary Rule

Billing stays outside the C engine.

The engine should consume normalized entitlement state, not raw `Transaction`, `Purchase`, `Product`, `BillingClient`, or store SDK types.

## iOS

The iOS shell owns:

- product loading
- purchase UI
- restore and sync flows
- manage-subscription entry points
- App Store disclosure and review compliance

Relevant Apple documentation:

- Auto-renewable subscriptions: <https://developer.apple.com/app-store/subscriptions/>
- App Review Guidelines: <https://developer.apple.com/app-store/review/guidelines/>
- StoreKit: <https://developer.apple.com/storekit/>
- Imported C APIs in Swift: <https://developer.apple.com/documentation/swift/imported_c_and_objective-c_apis>

Important Apple-side types and functions to keep in the shell:

- `Product`
- `Product.SubscriptionInfo`
- `Transaction`
- `AppStore.sync()`

## Android

The Android shell owns:

- product detail queries
- purchase launch and acknowledgement
- restore and refresh flows
- subscription management entry points
- Play Billing and Play policy compliance

Relevant Google documentation:

- Play Billing integration: <https://developer.android.com/google/play/billing/integrate>
- Subscription policy and management: <https://support.google.com/googleplay/android-developer/answer/12154973?hl=en>
- Subscription cancellation policy: <https://support.google.com/googleplay/android-developer/answer/16810878?hl=en-IN&rd=1>
- Android NDK overview: <https://developer.android.com/ndk>

Important Android-side types and functions to keep in the shell:

- `BillingClient.launchBillingFlow()`
- `BillingClient.queryPurchasesAsync()`
- `BillingClient.acknowledgePurchase()`
- `Purchase`
- `ProductDetails`

## Normalized Entitlement Shape

Both shells should map store-specific data into the struct in [`engine/include/shell_engine.h`](../engine/include/shell_engine.h):

- `tier`
- `product_id`
- `offer_id`
- `storefront`
- `original_transaction_id`
- `purchase_token`
- `purchase_time_unix_ms`
- `expires_time_unix_ms`
- `is_active`
- `will_auto_renew`

## Review And Compliance Implication

KMP can share entitlement parsing rules, but it does not reduce the compliance surface that matters for a subscription app:

- iOS still needs StoreKit and App Review compliant subscription UX.
- Android still needs Play Billing and Play policy compliant subscription UX.

That is why this repo keeps billing native-first at the shell edge and only shares normalized state with the engine.
