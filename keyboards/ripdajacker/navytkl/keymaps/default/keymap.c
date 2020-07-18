#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    /*        0        1        2       3         4       5        6        7        8        9        10        11                12               13       14        15       16      */
    /* A */ KC_ESC,  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_F11,          KC_F12,  KC_PSCR,  KC_SLCK,  KC_PAUS,
    /* B */ KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,         KC_BSPC,   KC_INS,  KC_HOME,  KC_PGUP,
    /* C */ KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_RBRC,           KC_NO,   KC_DEL,   KC_END,  KC_PGDN,
    /* D */ KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,         KC_NUHS,          KC_ENT,    KC_NO,    KC_NO,    KC_NO,
    /* E */ KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,         KC_RSFT,           KC_NO,    KC_NO,    KC_UP,    KC_NO,
    /* F */ KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_RALT, MO(1),      KC_APPLICATION,        KC_RCTRL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [1] = LAYOUT(
    /*         0         1         2         3          4        5         6         7         8          9        10        11        12       13       14        15          16   */
    /* A */ _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    /* B */ _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MEDIA_NEXT_TRACK,  KC__VOLUP,
    /* C */ _______,  _______,  _______,  _______,    RESET,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MEDIA_PREV_TRACK,  KC__VOLDOWN,
    /* D */ _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    /* E */ _______,  _______,  _______,  _______,  KC_CALCULATOR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    /* F */ _______,  _______,  _______,  _______,  _______,  _______,  KC_MEDIA_PLAY_PAUSE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};
