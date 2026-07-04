# ios-shell

This shell is intended to start from `nimblehq/ios-templates`.

## Ownership

- SwiftUI layout and navigation
- app lifecycle and scene setup
- StoreKit 2 purchase and entitlement refresh
- bridge code that imports [`engine/include/shell_engine.h`](../engine/include/shell_engine.h)

## Planned Files

- `AppShell/AppShellApp.swift`
- `AppShell/Features/Home/HomeView.swift`
- `AppShell/Billing/SubscriptionStore.swift`
- `Bridge/ShellEngineBridge.swift`
- `Bridge/shell_engine.modulemap`

## Upstream Bootstrap

The current upstream bootstrap command is documented in `nimblehq/ios-templates/README.md#L31-L37`:

`swift run --package-path Scripts/Swift/iOSTemplateMaker iOSTemplateMaker make`
