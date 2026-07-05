# cookiecutter — stamp a per-client mobile shell

`cookiecutter .` → answer the prompts → it generates `<app_slug>/` containing the
**per-client branding overlay**. Apply that overlay onto a fork of the shared KMP shell
foundation to get a buildable, client-branded app.

This is the "one backend, M branded forks" model: a single shared shell (the KMP layout
`androidApp/ api/ billing/ engine/ generated/ gradle/ shared/ iosApp/`), and one thin
per-client overlay stamped from the variables below.

> **Two shell tracks in this repo.** The top-level `android-shell/` + `ios-shell/` +
> `engine/` + `billing/` tree documents the *native-first* starter track (Swift/StoreKit +
> JNI/NDK binding the C ABI in `engine/include/shell_engine.h`). This `cookiecutter/`
> directory stamps the *KMP* per-client overlay track that the shipping client apps use
> today. They share the same C-engine philosophy but are distinct layouts; pick the track
> that matches your foundation fork.

## Invoke

```bash
# from this cookiecutter/ directory, non-interactive:
cookiecutter --no-input . client_name="The Commodore" app_slug="the-commodore" \
  vertical="fnb" features="book,order,pay,loyalty,info,wifi" default_tier="TIER_2" \
  -o /path/to/output

# or interactive (prompts for each variable):
cookiecutter .
```

Output: `<app_slug>/` with `settings.gradle.kts`, `androidApp/src/main/res/values/strings.xml`,
and `STAMP.md` (which carries the `androidApp/build.gradle.kts` snippet to apply).

## Variables

| Var | Meaning |
|---|---|
| `client_name` | shown in-app (app label, top bar) |
| `app_slug` | repo/dir + `rootProject.name` |
| `app_id` | Android applicationId (derived from slug) |
| `namespace` | kept `com.jetbrains.kmpapp` (matches foundation sources) |
| `primary_color` | theme primary |
| `vertical` | choice; sets default features + `resourceType` per `vertical-matrix.csv` |
| `features` | CSV of enabled doorways (book,order,pay,loyalty,info,wifi) |
| `web_surface_base` | derived; the WebView doorways open this |
| `default_tier` | the tier that gates the features at runtime (TIER_1/2/3) |

## Vertical matrix

`vertical-matrix.csv` is the machine-readable lookup: per vertical it sets `resourceType`
(room/teeTime/table/serviceSlot/none), the default doorway toggles, the default tier, and
the web-surface-base pattern. The vertical you pick seeds the `features` default.

## Example

`cookiecutter --no-input . client_name="The Commodore" app_slug="the-commodore" vertical="fnb" features="book,order,pay,loyalty,info,wifi"`
→ a Commodore-branded F&B front door (tables + order-ahead + loyalty), gated by the
client's tier.
