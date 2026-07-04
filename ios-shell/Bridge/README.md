# ios-shell/Bridge

This directory will hold the C-to-Swift bridge.

Expected files:

- `ShellEngineBridge.swift`
- `shell_engine.modulemap`

Primary responsibilities:

- import the C ABI from [`../../engine/include/shell_engine.h`](../../engine/include/shell_engine.h)
- convert Swift values into `shell_engine_config` and `shell_subscription_state`
- expose small Swift-friendly wrappers to the rest of the iOS app
