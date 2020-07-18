#pragma once

#include "quantum.h"

#define LAYOUT( \
   KA0,  KA1,  KA2,  KA3,  KA4,  KA5,  KA6,  KA7,  KA8,  KA9, KA10, KA11, KA12, KA13, KA14, KA15, KA16, \
   KB0,  KB1,  KB2,  KB3,  KB4,  KB5,  KB6,  KB7,  KB8,  KB9, KB10, KB11, KB12, KB13, KB14, KB15, KB16, \
   KC0,  KC1,  KC2,  KC3,  KC4,  KC5,  KC6,  KC7,  KC8,  KC9, KC10, KC11, KC12, KC13, KC14, KC15, KC16, \
   KD0,  KD1,  KD2,  KD3,  KD4,  KD5,  KD6,  KD7,  KD8,  KD9, KD10, KD11, KD12, KD13, KD14, KD15, KD16, \
   KE0,  KE1,  KE2,  KE3,  KE4,  KE5,  KE6,  KE7,  KE8,  KE9, KE10, KE11, KE12, KE13, KE14, KE15, KE16, \
   KF0,  KF1,  KF2,  KF3,  KF4,  KF5,  KF6,  KF7,  KF8,  KF9, KF10, KF11, KF12, KF13, KF14, KF15, KF16 \
) { \
   {KA0,  KA1,    KA2,  KA3,    KA4,   KA5,   KA6,  KA7,   KA8,   KA9,   KA10,  KA11, KA12, KA13,   KA14,  KA15, KA16},\
   {KB0,  KB1,    KB2,  KB3,    KB4,   KB5,   KB6,  KB7,   KB8,   KB9,   KB10,  KB11, KB12, KB13,   KB14,  KB15, KB16},\
   {KC0,  KC1,    KC2,  KC3,    KC4,   KC5,   KC6,  KC7,   KC8,   KC9,   KC10,  KC11, KC12, KC13,   KC14,  KC15, KC16},\
   {KD0,  KD1,    KD2,  KD3,    KD4,   KD5,   KD6,  KD7,   KD8,   KD9,   KD10,  KD11, KD12, KD13,  KC_NO, KC_NO, KC_NO},\
   {KE0,  KE1,    KE2,  KE3,    KE4,   KE5,   KE6,  KE7,   KE8,   KE9,   KE10,  KE11, KE12, KC_NO, KC_NO,  KE15,  KC_NO},\
   {KF0,  KF1,    KF2,  KC_NO,  KC_NO, KC_NO, KF6,  KC_NO, KC_NO, KC_NO, KF10,  KF11, KF12, KF13,   KF14,  KF15, KF16} \
}

