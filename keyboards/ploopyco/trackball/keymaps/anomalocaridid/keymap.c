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
    HORI_SCROLL = USER_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, LT(XTRA, KC_BTN4), // Primary Buttons
        KC_BTN2, LT(SCRL, KC_BTN5)           // Secondary Buttons
    ),

    [SCRL] = LAYOUT(
        DRAG_SCROLL, HORI_SCROLL, FLASH,
        DPI_CONFIG, _______
    ),

    [XTRA] = LAYOUT(
        KC_BTN6, KC_BTN8, _______,
        KC_BTN7, VRSN
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
        int8_t h       = mouse_report.h;
        mouse_report.h = -mouse_report.v;
        mouse_report.v = h;
    }

    return mouse_report;
}
