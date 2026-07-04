# native-mobile-shells

Native-first mobile starter shells for a shared C engine, with Kotlin Multiplatform kept as an optional later step instead of the initial foundation.

## Default Recommendation

For the first usable version of this repo, the default pairing is:

- iOS shell: `nimblehq/ios-templates`
- Android shell: `android/architecture-templates`

Use `MobileUpLLC/MobileUp-Android-Template` only when a fuller Android shell is worth the extra opinionation. Use `Kotlin/KMP-App-Template-Native` only if shared Kotlin domain or data code is a hard requirement from day one.

## Why Native-First

An existing C engine crosses the fewest boundaries when:

- iOS binds the C API directly from Swift or SwiftUI.
- Android binds the same C API through JNI and the NDK.
- Billing stays store-native and is normalized before entitlement state reaches the engine.

KMP does not remove the store-specific billing surface or the Android native bridge. It adds a Kotlin shared layer that may be useful later, but it is not the shortest path to a shippable shell.

## Repository Layout

```text
.
|-- README.md
|-- .gitignore
|-- docs/
|   |-- ARCHITECTURE.md
|   `-- SUBSCRIPTIONS.md
|-- engine/
|   |-- README.md
|   |-- include/
|   |   `-- shell_engine.h
|   |-- src/
|   |   `-- README.md
|   `-- tests/
|       `-- README.md
|-- ios-shell/
|   |-- README.md
|   `-- Bridge/
|       `-- README.md
|-- android-shell/
|   |-- README.md
|   `-- native/
|       `-- README.md
`-- billing/
    `-- README.md
```

## Key Integration Boundaries

- [`engine/include/shell_engine.h`](engine/include/shell_engine.h): the C ABI that both mobile shells bind to
- [`ios-shell/Bridge/README.md`](ios-shell/Bridge/README.md): the planned Swift and module-map seam for the iOS shell
- [`android-shell/native/README.md`](android-shell/native/README.md): the planned JNI and NDK seam for the Android shell
- [`billing/README.md`](billing/README.md): the normalized entitlement model that the shells send into the engine

## External Sources

- `nimblehq/ios-templates` bootstrap: `README.md#L31-L37`
- `android/architecture-templates` bootstrap: `README.md#L48-L59`
- `MobileUpLLC/MobileUp-Android-Template` setup: `README.md#L11-L47`
- `Kotlin/KMP-App-Template-Native` structure: `README.md#L6`, `shared/build.gradle.kts#L13-L49`, `iosApp/iosApp/ListView.swift#L1-L75`

## Engine Portability Note

The shared C engine can still stay compatible with `jart/cosmopolitan` and `ludoplex/cosmo-bde` where that makes sense for non-mobile targets. The iOS and Android deliverables themselves still have to be native signed app bundles that satisfy platform SDK and store rules.
