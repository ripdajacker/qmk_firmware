#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MANUFACTURER mehmedbasic
#define PRODUCT Navy TKL
#define DESCRIPTION A almost standard TKL

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/* row pins */
#define ROW_A  E6
#define ROW_B  D0
#define ROW_C  C6
#define ROW_D  B4
#define ROW_E  D4
#define ROW_F  D7

/* columns 0 - 16 */
#define DEMUX_ENABLE B2
#define DEMUX_A0 B6
#define DEMUX_A1 B2
#define DEMUX_A2 B3
#define DEMUX_A3 B1

#define COL_SEVENTEEN F5

#define PIN_CAPS_LOCK F7
#define PIN_NUM_LOCK  F6


#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#    define BACKLIGHT_LEVELS 0
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef RGB_DI_PIN
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 0
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#endif
