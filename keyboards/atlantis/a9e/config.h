#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414B // 9e
#define PRODUCT_ID      0x0015 // 
#define DEVICE_VER      0x0001
#define MANUFACTURER    Atlantis
#define PRODUCT         A9e
// #define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, F2, F3 }
#define MATRIX_COL_PINS { F5, F6, F7, A0, A1, A2, A3, A4, A5, B7, B6, B5 }
#define UNUSED_PINS

/* encoder pins */
#define ENCODERS_PAD_A { C1, C3, C5, C7, D1, D3, D5, D7, A6}
#define ENCODERS_PAD_B { C0, C2, C4, C6, D0, D2, D4, D6, A7 }
#define ENCODER_RESOLUTIONS { 4, 4, 4, 4, 4, 4, 4, 2, 2 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_HUE_STEP 8 //NEW
#define RGBLIGHT_SAT_STEP 8 //NEW
#define RGBLIGHT_VAL_STEP 8 //NEW
#define RGBLIGHT_LAYERS //NEW
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF //NEW

#define RGBLED_NUM 60
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 180
#endif

#endif