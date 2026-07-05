# Folding the existing apps into this cookiecutter

The five apps below already ship the shared KMP shell (`androidApp/ api/ billing/ engine/
generated/ gradle/ shared/ iosApp/`). Each is reproducible as a cookiecutter context +
the shared foundation fork. Folding an app in later is mechanical: fork the foundation,
`cookiecutter --no-input . <vars>`, apply the resulting `<app_slug>/` overlay.

Values marked **(verified)** were read directly from each app's `settings.gradle.kts`,
`androidApp/build.gradle.kts`, and `strings.xml`. Values marked **(derived)** follow from
the app's documented purpose and the `vertical-matrix.csv` row.

| App (local dir) | client_name | app_slug | app_id | rootProject.name (verified) | namespace (verified) | vertical | features | default_tier |
|---|---|---|---|---|---|---|---|---|
| `mhi-frontdoor-mobile` (archetype) | Front Door | mhi-frontdoor | com.mhi.frontdoor.archetype **(verified)** | MhiFrontDoor | com.jetbrains.kmpapp | fnb *(derived, archetype default)* | book,order,pay,loyalty,info,wifi | TIER_2 *(derived)* |
| `computerstore-mobile` | Computer Store | computerstore | com.mhi.ludoplex.computerstore **(verified)** | ComputerStore | com.jetbrains.kmpapp | retail *(derived)* | order,pay,loyalty,info | TIER_1 *(derived)* |
| `computerstore-mobile-lite` | Computer Store | computerstore-lite | com.mhi.ludoplex.computerstore **(verified, same id)** | ComputerStore | com.jetbrains.kmpapp | retail *(derived)* | info *(web-first, no native pay)* | TIER_1 *(derived)* |
| `mhi-manage-mobile` | MHI Manage | mhi-manage | com.mhi.manage **(verified)** | MhiManage | com.jetbrains.kmpapp | *(admin/owner console — not a storefront vertical)* | info *(admin surface)* | TIER_3 *(derived, owner tier)* |
| `kmp-app-template-native-upstream` (foundation) | KMP App Template Native | kmp-app-template-native | com.mhi.ludoplex.shell **(verified)** | KMP-App-Template-Native | com.mhi.ludoplex.shell **(verified, differs)** | *(unbranded foundation)* | *(none — base shell)* | *(n/a)* |

## Notes per app

- **mhi-frontdoor-mobile** is the *archetype* (applicationId `...frontdoor.archetype`). It is
  the branded-per-client track this cookiecutter targets; its own values are the template
  defaults. Real clients get their own `app_slug`/`client_name`/`vertical` row.
- **computerstore-mobile** and **computerstore-mobile-lite** share the same `applicationId`
  (`com.mhi.ludoplex.computerstore`) and `rootProject.name` (`ComputerStore`) — the lite build
  is the same app with native payment SDKs removed (web-first billing). Distinguish them by
  `app_slug` and by the `features` set (lite = info-only doorway), not by app id.
- **mhi-manage-mobile** is the owner/admin console (App A), multi-tenant, MHI-branded. It is
  not a storefront "vertical"; treat `vertical`/`features` as an admin surface rather than a
  doorway matrix row. Its tier is the owner tier.
- **kmp-app-template-native-upstream** is the shared foundation (`mhi-native-mobile-shell-
  foundation`). Its namespace is `com.mhi.ludoplex.shell`, differing from the four derived
  apps' `com.jetbrains.kmpapp` — it is the base to fork, not a stamped client.

## Do NOT rewrite the apps

This file is a mapping for future mechanical reproduction only. The five app repos are owned
by other territories and must not be modified or deleted from here.
