# Architecture

## Objective

This repo is the starter-shell layer around a shared C engine. The first implementation target is native iOS plus native Android, not KMP-first.

## Component Boundaries

### `engine/`

- Owns the shared C ABI.
- Must not depend on StoreKit, Google Play Billing, UIKit, SwiftUI, Android UI, or Jetpack Compose.
- Receives normalized configuration, actions, and entitlement state from the shells.

### `ios-shell/`

- Starts from `nimblehq/ios-templates`.
- Owns SwiftUI layout, navigation, StoreKit 2 integration, and App Store compliance UX.
- Calls the C engine through the future bridge files `ios-shell/Bridge/ShellEngineBridge.swift` and `ios-shell/Bridge/shell_engine.modulemap`.

### `android-shell/`

- Starts from `android/architecture-templates` by default.
- Owns Compose layout, navigation, Play Billing integration, and Play policy UX.
- Calls the C engine through the future bridge files `android-shell/native/src/main/cpp/shell_jni.cpp` and `android-shell/app/src/main/java/com/ludoplex/shell/ShellEngine.kt`.

### `billing/`

- Defines the normalized entitlement vocabulary that both shells feed into the engine.
- Does not purchase anything directly.
- Exists so the engine can react to subscription state without embedding store SDK logic.

## Concrete Runtime Flow

1. The shell boots with platform configuration and initializes the engine through `shell_engine_initialize`.
2. The shell renders native UI and converts user actions into JSON or typed calls for `shell_engine_dispatch_action_json`.
3. The shell obtains current store entitlements and maps them into `shell_subscription_state`.
4. The shell pushes those entitlements into `shell_engine_set_subscription_state`.
5. The engine returns state snapshots or route hints that the shell uses to update native UI.

## Why KMP Is Not The Default

The relevant upstream files are:

- `Kotlin/KMP-App-Template-Native/README.md#L6`
- `Kotlin/KMP-App-Template-Native/shared/build.gradle.kts#L13-L49`
- `Kotlin/KMP-App-Template-Native/iosApp/iosApp/iOSApp.swift#L1-L14`
- `Kotlin/KMP-App-Template-Native/iosApp/iosApp/ListView.swift#L1-L75`

Those files show:

- shared business logic in `shared/`
- iOS targets in `iosX64`, `iosArm64`, and `iosSimulatorArm64`
- Android as its own `androidTarget`
- native SwiftUI UI on iOS

That is a valid architecture, but it does not remove the Android JNI/NDK bridge or the platform-specific store work. It adds another layer to integrate and debug.

## Initial File Ownership

- [`engine/include/shell_engine.h`](../engine/include/shell_engine.h): cross-platform C ABI
- `ios-shell/Bridge/ShellEngineBridge.swift`: Swift wrapper around the C ABI
- `ios-shell/Bridge/shell_engine.modulemap`: C module exposure for Swift import
- `android-shell/native/src/main/cpp/shell_jni.cpp`: JNI wrapper over the C ABI
- `android-shell/app/src/main/java/com/ludoplex/shell/ShellEngine.kt`: Kotlin bridge for JNI calls
- `billing/README.md`: normalized entitlement mapping contract

## Template Sources

- `nimblehq/ios-templates`: `README.md#L31-L37` documents `swift run --package-path Scripts/Swift/iOSTemplateMaker iOSTemplateMaker make`
- `android/architecture-templates`: `README.md#L48-L59` documents branch bootstrap plus `bash customizer.sh`
- `MobileUpLLC/MobileUp-Android-Template`: `README.md#L23-L47` documents module layout and dependencies

## Deferred Option

If shared Kotlin becomes necessary later, add a separate adapter layer rather than replacing the native shells:

- `kmp-adapters/shared/`
- `kmp-adapters/ios/`
- `kmp-adapters/android/`

That keeps the engine ABI stable while letting Kotlin own only the parts that actually benefit from sharing.
