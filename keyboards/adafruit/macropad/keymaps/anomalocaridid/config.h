/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// Settings
#define LED_NUM_LOCK_PIN RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED
#define MK_3_SPEED // Have mouse keys move at constant speed

// Disable unused features
#define NO_ACTION_TAPPING // Disable mod tap, layer tap, etc.
