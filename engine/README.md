# engine

This directory holds the shared C engine contract that both mobile shells call into.

## Current Files

- [`include/shell_engine.h`](include/shell_engine.h): public C ABI for shell to engine communication
- [`src/README.md`](src/README.md): implementation placeholder
- [`tests/README.md`](tests/README.md): test placeholder

## Design Rules

- Keep the public boundary narrow and stable.
- Do not import store SDKs or UI frameworks here.
- Accept normalized shell config, user actions, and entitlement state.
- Return engine snapshots or routing hints in a shell-neutral format.

## Portability

The core here should stay compatible with `jart/cosmopolitan` and `ludoplex/cosmo-bde` where practical, but mobile shells still wrap it as native app targets.
