# android-shell

This shell is intended to start from `android/architecture-templates` by default, with `MobileUpLLC/MobileUp-Android-Template` as an optional richer alternative.

## Ownership

- Jetpack Compose layout and navigation
- Android lifecycle integration
- Play Billing product, purchase, and acknowledgement flows
- JNI and NDK bridge code that calls the C engine

## Planned Files

- `app/src/main/java/com/ludoplex/shell/ShellEngine.kt`
- `app/src/main/java/com/ludoplex/shell/billing/BillingRepository.kt`
- `app/src/main/java/com/ludoplex/shell/ui/HomeScreen.kt`
- `native/src/main/cpp/shell_jni.cpp`
- `native/src/main/cpp/CMakeLists.txt`

## Upstream Bootstrap

The conservative upstream bootstrap is documented in `android/architecture-templates/README.md#L48-L59`:

`bash customizer.sh your.package.name DataItemType [YourAppName]`
