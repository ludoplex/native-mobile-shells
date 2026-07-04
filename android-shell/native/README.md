# android-shell/native

This directory will hold the JNI and NDK bridge.

Expected files:

- `src/main/cpp/shell_jni.cpp`
- `src/main/cpp/CMakeLists.txt`

Primary responsibilities:

- marshal Kotlin and Java values into C structs
- call functions from [`../../engine/include/shell_engine.h`](../../engine/include/shell_engine.h)
- map engine snapshots back into Kotlin-facing data
