# {{cookiecutter.client_name}} — per-client shell stamp

Apply this overlay onto a fork of the shared KMP shell (the foundation that all client
apps derive from). These are the only per-client changes; the shell, doorways, generated
API client, and entitlement plumbing are inherited unchanged from the fork.

| Aspect | Value |
|---|---|
| `rootProject.name` | `{{cookiecutter.app_slug}}` |
| `applicationId` | `{{cookiecutter.app_id}}` |
| `namespace` | `{{cookiecutter.namespace}}` |
| App label | {{cookiecutter.client_name}} |
| Theme primary | `{{cookiecutter.primary_color}}` |
| Vertical | {{cookiecutter.vertical}} |
| Features | `{{cookiecutter.features}}` |
| Default tier | {{cookiecutter.default_tier}} |
| Web surface base | {{cookiecutter.web_surface_base}} |

## Where each value lands in the shared KMP shell tree

The shared shell uses the layout `androidApp/ api/ billing/ engine/ generated/ gradle/ shared/ iosApp/`
(identical across every derived app). The stamp only touches:

- `settings.gradle.kts` → `rootProject.name` (this overlay ships it).
- `androidApp/src/main/res/values/strings.xml` → `app_name` (this overlay ships it).
- `androidApp/build.gradle.kts` → `android.defaultConfig` (apply the snippet below).

## androidApp/build.gradle.kts → android.defaultConfig

```kotlin
applicationId = "{{cookiecutter.app_id}}"
buildConfigField("String", "CLIENT_NAME", "\"{{cookiecutter.client_name}}\"")
buildConfigField("String", "WEB_SURFACE_BASE", "\"{{cookiecutter.web_surface_base}}\"")
buildConfigField("String", "FEATURES", "\"{{cookiecutter.features}}\"")
```

The home screen reads `BuildConfig.CLIENT_NAME`, `BuildConfig.WEB_SURFACE_BASE`, and
`BuildConfig.FEATURES.split(",")` — nothing else needs editing. The `default_tier`
({{cookiecutter.default_tier}}) gates which of the enabled `features` actually unlock at runtime
via the entitlement broker; the vertical matrix enables them, the tier gates them.
