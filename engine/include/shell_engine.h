#ifndef SHELL_ENGINE_H_
#define SHELL_ENGINE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum shell_platform {
  SHELL_PLATFORM_UNKNOWN = 0,
  SHELL_PLATFORM_IOS = 1,
  SHELL_PLATFORM_ANDROID = 2
} shell_platform;

typedef enum shell_subscription_tier {
  SHELL_SUBSCRIPTION_TIER_NONE = 0,
  SHELL_SUBSCRIPTION_TIER_FREE = 1,
  SHELL_SUBSCRIPTION_TIER_PRO = 2
} shell_subscription_tier;

typedef struct shell_engine_config {
  const char *app_id;
  const char *app_version;
  const char *storage_dir;
  const char *cache_dir;
  const char *locale;
  const char *device_model;
  const char *system_version;
  shell_platform platform;
} shell_engine_config;

typedef struct shell_subscription_state {
  shell_subscription_tier tier;
  const char *product_id;
  const char *offer_id;
  const char *storefront;
  const char *original_transaction_id;
  const char *purchase_token;
  int64_t purchase_time_unix_ms;
  int64_t expires_time_unix_ms;
  bool is_active;
  bool will_auto_renew;
} shell_subscription_state;

typedef struct shell_host_callbacks {
  void (*log_message)(int32_t level, const char *message, void *user_data);
  void (*request_ui_refresh)(void *user_data);
} shell_host_callbacks;

bool shell_engine_initialize(
    const shell_engine_config *config,
    const shell_host_callbacks *callbacks,
    void *user_data);

bool shell_engine_set_subscription_state(
    const shell_subscription_state *state);

const char *shell_engine_get_initial_route(void);

bool shell_engine_dispatch_action_json(const char *action_json_utf8);

const char *shell_engine_snapshot_json(void);

void shell_engine_shutdown(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif  /* SHELL_ENGINE_H_ */
