#include "A9e.h"

//added by xc 
bool is_alt_tab_active = false; // Super Alt Tab Code
uint16_t alt_tab_timer = 0;
#ifdef VIA_ENABLE
    enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
      ATABF = USER00, //Alt tab forwards
      ATABR //Alt tab reverse
    };
#else
    enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
      ATABF = SAFE_RANGE, //Alt tab forwards
      ATABR //Alt tab reverse
    };
#endif
//ended by xc

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_L, KC_1, KC_R, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_L, KC_4, KC_R, 
		KC_L, KC_2, KC_R, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_L, KC_5, KC_R, 
		KC_L, KC_3, KC_R, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_L, KC_6, KC_R, 
		KC_UP, KC_8, KC_DOWN, RGB_VAI, KC_9, RGB_VAD, KC_L, KC_7, KC_R),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

//void matrix_scan_user(void) {
//}


//below added by xc replace above part 2
void matrix_scan_user(void) { //run whenever user matrix is scanned
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
//above added by xc part 2


//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  return true;
//}

//below added by xc part 3
bool process_record_user(uint16_t keycode, keyrecord_t *record) { //Actions to override existing key behaviours
    switch (keycode) { //For super alt tab keycodes
    case ATABF: //Alt tab forwards
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ATABR: //Alt tab reverse
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_LSHIFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_TAB);
      }
      break;
    }
    return true;
};
//above by xc part 3

// void encoder_update_user(uint8_t index, bool clockwise) 
// {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 2));
//         }
//         } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 2));
//     	}} else if (index == 2) { /* 3 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 2));
//     	}} else if (index == 3) { /* 4 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 11));
//     	}} else if (index == 4) { /* 5 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 11));
//     	}} else if (index == 5) { /* 6 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 11));
//     	}} else if (index == 6) { /* 7 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 11));
//     	}} else if (index == 7) { /* 8 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 3));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 5));
//     	}} else if (index == 8) { /* 9 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 6));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 8));
//     	}
// 	}
// }

void encoder_update_user(uint8_t index, bool clockwise) 
{
    if (index == 0) { /* 1 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 1) { /* 2 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 0}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 0}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 2}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 2}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 2) { /* 3 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 0}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 0}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 2}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 2}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 3) { /* 4 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 9}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 9}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 11}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 11}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 4) { /* 5 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col =9}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col =9}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 11}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 11}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 5) { /* 6 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 9}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 9}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 11}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 2, .col = 11}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 6) { /* 7 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 9}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 9}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 11}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 11}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 7) { /* 8 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 3}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 3}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 5}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 5}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 8) { /* 9 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 8}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 8}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }


}


// 以下为RGB灯效分层设置：--------------------------------------------------------------------------------
// Light LEDs 0 to 6 in YELLOW when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_WHITE});
// Light LEDs 0 to 6 in RED when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_RED});
// Light LEDs 6 to 11 in GREEN when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_GREEN});
// Light LEDs 12 to 17 in BLUE when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_BLUE});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	my_capslock_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer       
    // Overrides other layers
);

void keyboard_post_init_user(void)
{    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state)
{    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}


bool led_update_user(led_t led_state)
{
   rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// 以上为RGB灯效分层设置：--------------------------------------------------------------------------------



void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}