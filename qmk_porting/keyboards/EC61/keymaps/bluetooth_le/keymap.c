/*
Copyright 2022 OctopusZ <https://github.com/OctopusZ>

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
#include "battery_measure.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(/* 0: qwerty */
                     QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
                     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                     KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_RSFT,
                     KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),
    [1] = LAYOUT_all(/* 1: fn */
                     KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE,
                     KC_PSCR, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CALC, KC_MYCM,
                     MO(9), KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_INSERT, KC_HOME, RGB_TOG,
                     _______, _______, _______, _______, _______, _______, _______, _______, KC_PAGE_UP, KC_PAGE_DOWN, KC_END, KC_VOLU, _______,
                     MO(3), _______, MO(2), _______, MO(1), KC_MUTE, KC_VOLD, KC_MPLY),
    [2] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______,
                     _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_M_R, _______,
                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,
                     _______, _______, KC_MS_D, _______, _______, _______, _______, RGB_MOD, RGB_RMOD, RGB_M_B, RGB_M_P, RGB_VAI, _______,
                     MO(3), _______, MO(2), _______, MO(1), RGB_HUD, RGB_VAD, RGB_HUI),
    [3] = LAYOUT_all(/* 3: fn */
                     KC_WSCH, _______, KC_BRID, KC_BRIU, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     MO(3), _______, MO(2), _______, MO(1), _______, _______, _______),
    [4] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
    [5] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
    [6] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
    [7] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
    [8] = LAYOUT_all(/* 2: fn */
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
    [9] = LAYOUT_all(/* 2: fn */
                     _______, BLE_SLOT0, BLE_SLOT1, BLE_SLOT2, BLE_SLOT3, _______, _______, _______, _______, _______, _______, _______, _______, BLE_ALL_CLEAR,
                     _______, BATTERY_INDICATOR, USB_MODE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______, _______, _______),
};

static uint8_t lowpower_state = 0;
static uint16_t lowpower_tick;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    if (lowpower_state == 1) { // low power indicator breathing
        for (uint8_t i = led_min; i < led_max; i++) {
            if (i != 0) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
            }
        }
    }

    return true;
}

void housekeeping_task_user()
{
    if (battery_get_last_percentage() < 5) {
        switch (lowpower_state) {
            case 0:
                lowpower_state = 1;
                lowpower_tick = timer_read();
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
                rgb_matrix_set_speed_noeeprom(255);
                rgb_matrix_sethsv_noeeprom(0, 255, 255);
                break;
            case 1:
                if (timer_elapsed(lowpower_tick) > 8000) {
                    lowpower_state = 2;
                    rgb_matrix_disable_noeeprom();
                }
                break;
            case 2:
                if (rgb_matrix_is_enabled()) {
                    rgb_matrix_disable_noeeprom();
                }
                break;
            default:
                break;
        }
    } else {
        if (lowpower_state == 2) {
            rgb_matrix_reload_from_eeprom();
        }
        lowpower_state = 0;
    }
}
