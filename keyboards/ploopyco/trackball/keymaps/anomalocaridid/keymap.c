/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keycode.h"
#include "pointing_device.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "version.h"
// userspace code
#include "anomalocaridid.h"

enum layers {
    BASE, // default layer
    SCRL, // scroll modifier layer
    XTRA, // extra mouse buttons
};

enum custom_keycodes_keymap {
    HORI_SCROLL = KEYMAP_SAFE_RANGE,
};

enum td_keycodes { BTN4_XTRA, BTN5_SCRL, VRSN_FLASH };

typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

// determine tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

#define TD_LT_ARGS qk_tap_dance_state_t *state, void *user_data
void lt_finished(TD_LT_ARGS, uint16_t keycode, int layer);
void lt_reset(TD_LT_ARGS, uint16_t keycode, int layer);

void vrsn_flash_res(TD_LT_ARGS);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, TD(BTN4_XTRA), // Primary Buttons
        KC_BTN2, TD(BTN5_SCRL)           // Secondary Buttons
    ),

    [SCRL] = LAYOUT(
        DRAG_SCROLL, HORI_SCROLL, QK_BOOT,
        DPI_CONFIG, _______
    ),

    [XTRA] = LAYOUT(
        KC_BTN6, KC_BTN8, _______,
        KC_BTN7, TD(VRSN_FLASH)
    ),
};

// clang-format on
extern uint16_t dpi_array[];

static bool horizontal_scroll = false;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HORI_SCROLL:
            if (record->event.pressed) {
                horizontal_scroll ^= 1;
            }
            return false;
    }
    return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (horizontal_scroll) {
        int8_t h = mouse_report.h;
        mouse_report.h = -mouse_report.v;
        mouse_report.v = h;
    }

    return mouse_report;
}

// tap dance functions
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (state->interrupted || !state->pressed) {
                return TD_SINGLE_TAP;
            } else {
                return TD_SINGLE_HOLD;
            }
        case 2:
            return TD_DOUBLE_TAP;
        default:
            return TD_UNKNOWN;
    }
}

static td_state_t td_state;

void lt_finished(TD_LT_ARGS, uint16_t keycode, int layer) {
    td_state = cur_dance(state);

    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(keycode);
            break;
        case TD_SINGLE_HOLD:
            layer_on(layer);
            break;
        default:
            break;
    }
}

void lt_reset(TD_LT_ARGS, uint16_t keycode, int layer) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(keycode);
            break;
        case TD_SINGLE_HOLD:
            layer_off(layer);
            break;
        default:
            break;
    }
}

#define TD_PROTO(name, func) void name##_##func(TD_LT_ARGS)
#define TD_LT_FUNC(name, keycode, layer, func)       \
    TD_PROTO(name, func);                            \
    TD_PROTO(name, func) {                           \
        lt_##func(state, user_data, keycode, layer); \
    }
#define TD_LT(name, keycode, layer) TD_LT_FUNC(name, keycode, layer, finished) TD_LT_FUNC(name, keycode, layer, reset)

TD_LT(btn4_xtra, KC_BTN4, XTRA)
TD_LT(btn5_scrl, KC_BTN5, SCRL)

void vrsn_flsh(TD_LT_ARGS) {
    switch (cur_dance(state)) {
        case TD_SINGLE_TAP:
            send_version();
            break;
        case TD_DOUBLE_TAP:
            send_flash_command();
            break;
        default:
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [BTN4_XTRA]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, btn4_xtra_finished, btn4_xtra_reset), // KC_BTN4/XTRA layer
    [BTN5_SCRL]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, btn5_scrl_finished, btn5_scrl_reset), // KC_BTN4/SCRL layer
    [VRSN_FLASH] = ACTION_TAP_DANCE_FN(vrsn_flsh)                                           // VRSN/FLSH
};
