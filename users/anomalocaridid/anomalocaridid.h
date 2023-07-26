#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

#include QMK_KEYBOARD_H

enum custom_keycodes_user {
    VRSN = SAFE_RANGE,
    FLASH, // Type qmk command for flashing firmware
    USER_SAFE_RANGE,
};
