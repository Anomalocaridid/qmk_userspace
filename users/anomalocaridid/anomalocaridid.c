#include "anomalocaridid.h"

#include "action_util.h"
#include "version.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Output flash command by default
        case QK_MAKE:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT_LSHIFT);
            }
            return true;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
    }

    return process_record_keymap(keycode, record);
}

// If magic keycodes are disabled, override placeholder functions to take up less space
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif

// If rgb matrix is enabled, set default state
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
}
#endif
