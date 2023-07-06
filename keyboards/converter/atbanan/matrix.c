/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#include QMK_KEYBOARD_H
#include "libs/SingleWireSerial.h"
#include "print.h"

/*
 * Matrix Array usage:
 *
 * ROW: 16(4bits)
 * COL:  8(3bits)
 *
 *    8bit wide
 *   +---------+
 *  0|00 ... 07|
 *  1|08 ... 0F|
 *  :|   ...   |
 *  :|   ...   |
 *  E|70 ... 77|
 *  F|78 ... 7F|
 *   +---------+
 */
static uint8_t matrix[MATRIX_ROWS];
uint8_t sun_led = 0x0E;

#define ROW(code)      ((code>>3)&0xF)
#define COL(code)      (code&0x07)

static bool is_modified = false;

void ss_handle_interrupt(void) {
    // donothing
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        sun_led = sun_led & ~(1 << 1);
    } else {
        sun_led = sun_led | (1 << 1);
    }
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        sun_led = sun_led & ~(1 << 2);
    } else {
        sun_led = sun_led | (1 << 2);
    }
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        sun_led = sun_led & ~(1 << 3);
    } else {
        sun_led = sun_led | (1 << 3);
    }
    uprintf("USB: 0x%02X\n", usb_led);
    uprintf("SUN: 0x%02X\n", sun_led);
    ss_write(sun_led);
}

void matrix_init(void)
{
    debug_enable = false;
    debug_matrix = false;

    _delay_ms(200);

    dprint("Starting\n");

    ss_init(false);
    ss_begin(4800);

    dprint("UART started\n");

    ss_write(sun_led);

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) matrix[i] = 0x00;

    matrix_init_quantum();
    return;
}

uint8_t matrix_scan(void)
{
    uint8_t code;
    code = 0;

    if (ss_available()) {
        code = ss_read();
        uprintf("received 0x%02X\n", code);
        uprintf("sending  0x%02X\n", sun_led);
        ss_write(sun_led);
    } else {
        code = 0;
    }

    if (code&0x80) {
        // break code
        if (matrix_is_on(ROW(code), COL(code))) {
            matrix[ROW(code)] &= ~(1<<COL(code));
        }
    } else {
        // make code
        if (!matrix_is_on(ROW(code), COL(code))) {
            matrix[ROW(code)] |=  (1<<COL(code));
        }
    }

    matrix_scan_quantum();
    return code;
}

bool matrix_is_modified(void)
{
    return is_modified;
}

inline
bool matrix_has_ghost(void)
{
    return false;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & (1<<col));
}

inline
uint8_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 01234567\n");
    for (uint8_t row = 0; row < matrix_rows(); row++) {
        print_hex8(row); print(": ");
        print_bin_reverse8(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop(matrix[i]);
    }
    return count;
}
