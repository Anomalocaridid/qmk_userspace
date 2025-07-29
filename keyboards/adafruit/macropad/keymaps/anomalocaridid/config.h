/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// Settings
#define ENABLE_COMPILE_KEYCODE // Add QK_MAKE key
#define LED_NUM_LOCK_PIN RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED

// Disable unused features
#define LAYER_STATE_8BIT // Limit layers to 8
