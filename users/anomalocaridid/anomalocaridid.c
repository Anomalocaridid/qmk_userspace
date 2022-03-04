#include "anomalocaridid.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                send_version();
            }
            return false;
        case FLASH:
            if (record->event.pressed) {
                send_flash_command();
            }
            return false;
    }

    return process_record_keymap(keycode, record);
}

void send_version(void) {
    SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
}

void send_flash_command(void) {
    SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
}