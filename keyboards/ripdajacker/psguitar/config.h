#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xEEEE
#define PRODUCT_ID      0x2019
#define DEVICE_VER		0x0001
#define MANUFACTURER mehmedbasic
#define PRODUCT PlayStaion2 Guitar
#define DESCRIPTION An almost standard guitar controller

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 1

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5, D1, D0, D4, B6, F4 }
#define MATRIX_COL_PINS { F1 }
#define UNUSED_PINS

/* row pins */
#define BTN_GREEN      C6
#define BTN_RED        D7
#define BTN_YELLOW     E6
#define BTN_BLUE       B4
#define BTN_ORANGE     B5
#define BTN_START      D1
#define BTN_UP         D0
#define BTN_DOWN       D4
#define BTN_STAR_POWER B6
#define BTN_SELECT     F4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL
/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define JOYSTICK_BUTTON_COUNT 10
#define JOYSTICK_AXES_COUNT 1
