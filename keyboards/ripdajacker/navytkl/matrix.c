/*
  Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "navytkl.h"

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "led.h"
#include "config.h"
#include "matrix.h"
#include "navytkl.h"
#include "quantum.h"

#ifndef DEBOUNCE
#    define DEBOUNCE 5
#endif

static uint8_t debouncing = DEBOUNCE;

static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static uint8_t read_rows(void);
static void    select_col(uint8_t col);

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }

inline uint8_t matrix_cols(void) { return MATRIX_COLS; }

/**
 * Row pins PD2, PD3... PD7 are input for rows A-F.
 * The rows are pulled low with a pull-down resistor.
 *
 * The columns are scanned using two 74hc595 in series on pins defined in config.h.
 */
void matrix_init(void) {
    setPinInputHigh(ROW_A);
    setPinInputHigh(ROW_B);
    setPinInputHigh(ROW_C);
    setPinInputHigh(ROW_D);
    setPinInputHigh(ROW_E);
    setPinInputHigh(ROW_F);

    setPinOutput(DEMUX_ENABLE);

    setPinOutput(DEMUX_A0);
    setPinOutput(DEMUX_A1);
    setPinOutput(DEMUX_A2);
    setPinOutput(DEMUX_A3);
    setPinOutput(COL_SEVENTEEN);

    writePin(COL_SEVENTEEN, 1);

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i]            = 0;
        matrix_debouncing[i] = 0;
    }
    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);
        _delay_us(3);
        uint8_t rows = read_rows();
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t)1 << col);
            bool curr_bit = rows & (1 << row);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t)1 << col);
                debouncing = DEBOUNCE;
            }
        }
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
    matrix_scan_quantum();
    return 1;
}

bool matrix_is_modified(void) {
    if (debouncing)
        return false;
    else
        return true;
}

inline bool matrix_is_on(uint8_t row, uint8_t col) { return (matrix[row] & ((matrix_row_t)1 << col)); }

inline matrix_row_t matrix_get_row(uint8_t row) { return matrix[row]; }

void matrix_print(void) {
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        xprintf("%02X: %032lb\n", row, bitrev32(matrix_get_row(row)));
    }
}

uint8_t matrix_key_count(void) {
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop32(matrix[i]);
    }
    return count;
}

static uint8_t read_rows(void) {
    return (readPin(ROW_F) ? 0: (1<< 5))
    | (readPin(ROW_E) ? 0 : (1<< 4))
    | (readPin(ROW_D) ? 0 : (1 << 3))
    | (readPin(ROW_C) ? 0 : (1 << 2))
    | (readPin(ROW_B) ? 0 : (1 << 1))
    | (readPin(ROW_A) ? 0 : 1);
}

static void select_col(uint8_t col) {
    if (col == 17) {
        writePinHigh(DEMUX_ENABLE);
        writePinLow(COL_SEVENTEEN);
    } else {
        uint8_t bit0 = col & 0b0001;
        uint8_t bit1 = col & 0b0010;
        uint8_t bit2 = col & 0b0100;
        uint8_t bit3 = col & 0b1000;

        writePinLow(DEMUX_ENABLE);
        writePinHigh(COL_SEVENTEEN);

        writePin(DEMUX_A0, bit0);
        writePin(DEMUX_A1, bit1);
        writePin(DEMUX_A2, bit2);
        writePin(DEMUX_A3, bit3);
        _delay_us(1);
    }
}

void led_set_kb(uint8_t usb_led) {
    led_t leds = (led_t)usb_led;

    writePin(PIN_CAPS_LOCK, leds.caps_lock);
    writePin(PIN_NUM_LOCK, leds.num_lock);

    led_set_user(usb_led);
}

void led_init_ports(void) {
    setPinOutput(PIN_CAPS_LOCK);
    setPinOutput(PIN_NUM_LOCK);
}
