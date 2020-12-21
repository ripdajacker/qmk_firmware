#include QMK_KEYBOARD_H
#include "joystick.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    JS_BUTTON0,
    JS_BUTTON1,
    JS_BUTTON2,
    JS_BUTTON3,
    JS_BUTTON4,
    JS_BUTTON5,
    JS_BUTTON6,
    JS_BUTTON7,
    JS_BUTTON8,
    JS_BUTTON9
  )
};

void matrix_scan_user(void){}

// initialize matrix
void matrix_init_user(void) {
}

// joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {[0] = JOYSTICK_AXIS_IN(F5, 480, 480, 1023)};
