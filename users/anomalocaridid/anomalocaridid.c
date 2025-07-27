#include "anomalocaridid.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
        case FLASH:
            if (record->event.pressed) {
                SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
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
