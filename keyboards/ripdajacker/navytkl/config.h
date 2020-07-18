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
#define SHR_LATCH B3
#define SHR_CLOCK B2    
#define SHR_DATA B1

#define SHR_COLS {  0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080 }
#define COL_SEVENTEEN B6

#define PIN_CAPS_LOCK B4
#define PIN_NUM_LOCK  B5


#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#    define BACKLIGHT_LEVELS 0
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 4

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
