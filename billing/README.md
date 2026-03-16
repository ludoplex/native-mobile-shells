# billing

This directory defines the store-neutral entitlement model that the mobile shells map into before they call the engine.

## Rules

- Keep store SDK types out of the C engine.
- Normalize iOS and Android purchase state into `shell_subscription_state`.
- Treat billing as a shell concern and entitlement as an engine input.

## Platform Mapping

### iOS

Map StoreKit 2 values such as `Product`, `Product.SubscriptionInfo.Status`, and `Transaction` into the fields in [`../engine/include/shell_engine.h`](../engine/include/shell_engine.h).

### Android

Map `ProductDetails` and `Purchase` values obtained through `BillingClient.launchBillingFlow()`, `BillingClient.queryPurchasesAsync()`, and `BillingClient.acknowledgePurchase()` into the same fields.

## Current Documentation

- [`../docs/SUBSCRIPTIONS.md`](../docs/SUBSCRIPTIONS.md)
- [`../engine/include/shell_engine.h`](../engine/include/shell_engine.h)
