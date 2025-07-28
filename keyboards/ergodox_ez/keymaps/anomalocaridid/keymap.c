#include "modifiers.h"
#include QMK_KEYBOARD_H
// userspace code
#include "anomalocaridid.h"

enum layers {
    BASE, // default layer
    FNCT, // function keys
    MOUS, // mouse keys
    ARRW, // arrow keys
};

enum custom_keycodes_keymap {
    ALTCASE = USER_SAFE_RANGE, // Alternate uppercase and lowercase automatically
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |NextFX|           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |FNCT/ |           |Delete|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|PrtScr|           |      |------+------+------+------+------+--------|
 * |L Shift(|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |R Shift)|
 * |--------+------+------+------+------+------| Left |           |Right |------+------+------+------+------+--------|
 * | L Ctrl |   Z  |   X  |   C  |   V  |   B  | GUI  |           |GUI   |   N  |   M  |   ,  |   .  |   /  | R Ctrl |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L Alt |ESC/~`|  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |R Alt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | MOUS | ARRW |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | HOME |       |PageUp|      |      |
 *                                 |Space | Tab  |------|       |------|Enter |BackSp|
 *                                 |      |      |Sw/End|       |PageDn|      |      |
 *                                 `--------------------'       `--------------------'
 */
    [BASE] = LAYOUT_ergodox_pretty(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, RM_NEXT,                         KC_EQL,  KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_MINUS,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, LT(FNCT, KC_PSCR),               KC_DEL,  KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        SC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, SC_RSPC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LGUI,                         KC_RGUI, KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
        KC_LALT, QK_GESC, KC_QUOT, KC_LEFT, KC_RGHT,                                                       KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_RALT,
                                                           XXXXXXX, XXXXXXX,      TG(MOUS), TG(ARRW),
                                                                    KC_HOME,      KC_PGUP,
                                                 KC_SPACE, KC_TAB,  SH_T(KC_END), KC_PGDN,  KC_ENTER, KC_BSPC
  ),

/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Mac1Rec |  F1  |  F2  |  F3  |  F4  |  F5  |NextFX|           |  =   |  F6  |  F7  |  F8  |  F9  |  F10 | Reboot |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Mac2Rec |  F11 |  F12 |  F13 |  F14 |  F15 | FNCT |           |Delete|  F16 |  F17 |  F18 |  F19 |  F20 | Flash  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mac1Play|  F21 |  F22 |  F23 |  F24 |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Left |           |Right |------+------+------+------+------+--------|
 * |Mac2Play|      |      |      |      |      | GUI  |           |GUI   |      |      |      |      |      |ALT CASE|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RecStp|      |      |      |      |                                       |      |      |      |      |Version|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |PageUp|      |      |
 *                                 |Space | Tab  |------|       |------|Enter |BackSp|
 *                                 |      |      |Sw/End|       |PageDn|      |      |
 *                                 `--------------------'       `--------------------'
 */
    [FNCT] = LAYOUT_ergodox_pretty(
        DM_REC1, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
        DM_REC2, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,                   _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  QK_MAKE,
        DM_PLY1, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ALTCASE,
        DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VRSN,
                                                              _______, _______, XXXXXXX, XXXXXXX,
                                                                       _______, _______,
                                                     _______, _______, _______, _______, _______, _______
  ),

/* Keymap 2: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |NextFX|           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |Delete| W Up |W Left| M Up |WRight|   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |L Shift(|   A  |   S  |   D  |   F  |   G  |------|           |------|W Down|M Down| M Up |MRight|   ;  |R Shift)|
 * |--------+------+------+------+------+------| Left |           |Right |------+------+------+------+------+--------|
 * | L Ctrl |   Z  |   X  |   C  |   V  |   B  | GUI  |           |GUI   |   N  |   M  |   ,  |   .  |   /  | R Ctrl |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L Alt |ESC/~`|  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |R Alt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | MOUS |Butt 5|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |Butt 4|      |      |
 *                                 |Space | Tab  |------|       |------|LClick|RClick|
 *                                 |      |      |Sw/End|       |MClick|      |      |
 *                                 `--------------------'       `--------------------'
 */
    [MOUS] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                   XXXXXXX, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   _______, MS_WHLU, MS_WHLL, MS_UP,   MS_WHLR, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, MS_BTN5,
                                                                       _______, MS_BTN4,
                                                     _______, _______, _______, MS_BTN3, MS_BTN1, MS_BTN2
  ),

/* Keymap 3: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |NextFX|           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |Delete|   Y  |   U  |  Up  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |L Shift(|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  | Left | Down |Right |   ;  |R Shift)|
 * |--------+------+------+------+------+------| Left |           |Right |------+------+------+------+------+--------|
 * | L Ctrl |   Z  |   X  |   C  |   V  |   B  | GUI  |           |GUI   |   N  |   M  |   ,  |   .  |   /  | R Ctrl |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L Alt |ESC/~`|  '"  | Left |Right |                                       |  Up  | Down |   [  |   ]  |R Alt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | ARRW |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |PageUp|      |      |
 *                                 |Space | Tab  |------|       |------|Enter |BackSp|
 *                                 |      |      |Sw/End|       |PageDn|      |      |
 *                                 `--------------------'       `--------------------'
 */
    [ARRW] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,                   _______, _______, _______, KC_UP,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                              _______, _______, XXXXXXX, _______,
                                                                       _______, _______,
                                                     _______, _______, _______, _______, _______, _______
  ),

};
// clang-format on

// Set rgb matrix defaults
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) {
        return false;
    }
    // Indicate the layer with the RGB colors, but only on keys with configured keycodes
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

                if (index >= led_min && index < led_max && index != NO_LED && keycode > KC_TRNS) {
                    // NOTE: make sure to distinguish mouse keys from each other
                    if (IS_MOUSEKEY_MOVE(keycode)) {
                        rgb_matrix_set_color(index, RGB_CYAN);
                    } else if (IS_MOUSEKEY_WHEEL(keycode)) {
                        rgb_matrix_set_color(index, RGB_MAGENTA);
                    } else {
                        rgb_matrix_set_color(index, RGB_PURPLE);
                    }
                }
            }
        }
    }
    return false;
}

static bool alt_case_toggle = false;
static bool alt_case_shift  = false;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
            if (alt_case_toggle && record->event.pressed) {
                if (alt_case_shift) {
                    add_oneshot_mods(MOD_BIT_LSHIFT);
                }
                alt_case_shift ^= 1;
            }
            return true;
        case ALTCASE:
            if (record->event.pressed) {
                alt_case_toggle ^= 1;
                alt_case_shift = false;
            }
            return false;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);

    ergodox_led_all_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};
