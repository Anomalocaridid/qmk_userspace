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
// userspace code
#include "anomalocaridid.h"

#include "keycodes.h"

enum layers {
    BASE, // default layer
    SCRL, // scroll modifier layer
    XTRA, // extra mouse buttons
    HORI  // horizontal scrolling overlay
};

// enum custom_keycodes_keymap {
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT( /* Base */
        MS_BTN1, MS_BTN3, LT(XTRA, MS_BTN4), // Primary Buttons
        MS_BTN2, LT(SCRL, MS_BTN5)           // Secondary Buttons
    ),

    [SCRL] = LAYOUT(
        DRAG_SCROLL, TG(HORI), QK_MAKE,
        DPI_CONFIG,  _______
    ),

    [XTRA] = LAYOUT(
        MS_BTN6, MS_BTN8, _______,
        MS_BTN7, VRSN
    ),

    // This layer should not alter any of the mouse buttons
    [HORI] = LAYOUT(
        _______, _______, _______,
        _______, _______
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [SCRL] = { ENCODER_CCW_CW(_______, _______) },
    [XTRA] = { ENCODER_CCW_CW(_______, _______) },
    [HORI] = { ENCODER_CCW_CW(MS_WHLR, MS_WHLL) }
};
// clang-format on
