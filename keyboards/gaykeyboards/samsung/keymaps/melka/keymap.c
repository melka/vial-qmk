#include QMK_KEYBOARD_H
#include "keymap_french_osx.h"
#include "sendstring_french_osx.h"

/*
Security Note: While it is possible to use macros to send passwords, credit card numbers,
and other sensitive information it is a supremely bad idea to do so. Anyone who gets a hold
of your keyboard will be able to access that information by opening a text editor.
*/
enum custom_keycodes
{
  PASS_A = SAFE_RANGE,
  PASS_B
};

#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	LAYOUT(
	    FR_LABK, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, FR_RPRN, FR_MINS, KC_BSPC,           KC_INS, KC_HOME, MO(1),
        KC_TAB, FR_A, FR_Z, FR_E, FR_R, FR_T, FR_Y, FR_U, FR_I, FR_O, FR_P, FR_CIRC, FR_DLR, FR_GRV,            KC_DEL, KC_END,  KC_PGDN,
        KC_LCAP, FR_Q, FR_S, FR_D, FR_F, FR_G, FR_H, FR_J, FR_K, FR_L, FR_M, FR_LUGR, KC_ENT,
        KC_LSFT, FR_AT, FR_W, FR_X, FR_C, FR_V, FR_B, FR_N, FR_COMM, FR_SCLN, FR_COLN, FR_EQL, KC_RSFT,                KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,              KC_SPC,             KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    LAYOUT(
	    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___,     PASS_A, PASS_B, ___,
        ___, KC_WH_U, KC_UP, KC_WH_D, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                         ___, ___, ___,
        ___, KC_LEFT, KC_DOWN, KC_RIGHT, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        TO(2), ___, KC_APP, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                                         KC_VOLU,
        ___, ___, ___,              ___,             ___, ___, ___, ___,                                         ___, KC_VOLD, KC_MUTE
    ),
    LAYOUT(
	    RESET, ___, ___, ___, ___, ___, ___, ___, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, ___, ___,                    ___, ___, ___,
        ___, ___, ___, ___, ___, ___, ___, ___, KC_P7, KC_P8, KC_P9, KC_PMNS, ___, ___,                          ___, ___, ___,
        ___, ___, ___, ___, ___, ___, ___, ___, KC_P4, KC_P5, KC_P6, KC_PPLS, ___,
        TO(0), ___, ___, ___, ___, ___, ___, ___, ___, KC_P1, KC_P2, KC_P3, KC_PENT,                                    ___,
        ___, ___, ___,              ___,             ___, KC_P0, KC_PDOT, KC_PENT,                                 ___, ___, ___
    )
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

        case KC_BSPC:
            {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_CTRL) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }

        case FR_AT:
            {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_CTRL) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_ESC);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_ESC);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }

        case PASS_A:
            {
            if (record->event.pressed) {
                SEND_STRING(PASSWORD_A);
            }
            break;
        }

        case PASS_B:
            {
            if (record->event.pressed) {
                SEND_STRING(PASSWORD_B);
            }
            break;
        }
    }
    return true;
}
