/*
Copyright 2021 Jay Greco

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

int LAYER_LEVEL = 0;

enum custom_keycodes {
	POINT = SAFE_RANGE,
	MEASURE,
	STICK,
	DELETE,
	RECALL,
	DRAW,
	SHAPE,
	POLYGON
};

void layer_changer(void) {
	++LAYER_LEVEL;
	if (LAYER_LEVEL > 2) {
		LAYER_LEVEL = 0;
	}
	layer_move(LAYER_LEVEL);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
	case POINT:
		if (record->event.pressed) {
			SEND_STRING("s");
		} else {
			// do nothing
		}
		break;
	case MEASURE:
		if (record->event.pressed) {
			SEND_STRING("q");
		} else {
			// do nothing
		}
		break;
	case STICK:
		if (record->event.pressed) {
			SEND_STRING(SS_LSFT());
		} else {
			// do nothing
		}
		break;
	case DELETE:
		if (record->event.pressed) {
			SEND_STRING(SS_TAP(X_DELETE));
		} else {
			// do nothing
		}
		break;
	case RECALL:
		if (record->event.pressed) {
			SEND_STRING("x");
		} else {
			// do nothing
		}
		break;
	case DRAW:
		if (record->event.pressed) {
			SEND_STRING("ff");
		} else {
			layer_changer();
		}
		break;
	case SHAPE:
		if (record->event.pressed) {
			SEND_STRING("fr");
		} else {
			layer_changer();
		}
		break;
	case POLYGON:
		if (record->event.pressed) {
			SEND_STRING("fg");
		} else {
			layer_changer();
		}
		break;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
	DRAW, STICK, RECALL,
    POINT, MEASURE, DELETE
),

[1] = LAYOUT(
	SHAPE, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

[2] = LAYOUT(
	POLYGON, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
)

};

void matrix_init_user(void) {
  set_scramble_LED(LED_OFF);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}