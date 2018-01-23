#include "minidox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define QWERTY 0
#define DVORAK 1
#define COLMAK 2
#define LOWER 3
#define RAISE 4
#define MISC 5

enum custom_keycodes {
  KC_IME = SAFE_RANGE,
};

// Fillers to make layering more clear
#define ____ KC_TRNS
#define XXXX KC_NO

#define KC_NTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define KC_PTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define KC_NAPP ACTION_MODS_KEY(MOD_LGUI, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI  | Lower|      |    |Back  | Raise| Alt  |
 *                  `-------------| Space|    | Space|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[QWERTY] = KEYMAP( \
  KC_Q,        KC_W,  KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
  LT(MISC,     KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,    KC_K,   KC_L,    LT(MISC, KC_SCLN), \
  CTL_T(KC_Z), KC_X,  KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
  KC_LGUI, MO(LOWER), SFT_T(KC_SPC), SFT_T(KC_BSPC), MO(RAISE), KC_LALT \
),

/* Dvorak 
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   '  |   ,  |   .  |   P  |   Y  |           |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |           |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  |           |   B  |   M  |   W  |   V  |   Z  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[DVORAK] = KEYMAP( \
  KC_QUOT,           KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
  LT(MISC, KC_A),   KC_O,    KC_E,   KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, LT(MISC, KC_S), \
  KC_SCLN,          KC_Q,    KC_J,   KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
  ____, ____, ____, ____, ____, ____ \
),


/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |           |  F12 |   ~  |   \  |   '  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | IME  |      |    |      |      |      |
 *                  `-------------|Enter |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = KEYMAP( \
  KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,          KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,         KC_TILD, KC_BSLS, KC_QUOT, KC_SLSH,    \
  ____,  KC_IME, KC_ENT, ____, ____, ____ \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Tab  |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
   | Esc  |      |      |      |      |           |      |   `  |   |  |   "  |   ?  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      | IME |       |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = KEYMAP( \
  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_TAB,  ____,  ____,    ____,   ____,    ____,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_ESC,  ____,  ____,    ____,   ____,    ____,    KC_TILD, KC_PIPE, KC_DQT,  KC_QUES, \
  ____,    ____,  ____,    ____,   KC_IME,  ____ \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * | Reset|M_W_U | M_U  |M_W_D | PTAB |           | NTAB | PG_D | Up   | PG_U |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | M_L  | M_D  | M_R  |      |           | NAPP | Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |Dvorak|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | BTM3 | BTM2 |      |    |      |      |      |
 *                  `-------------| BTM1 |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISC] =  KEYMAP( \
  RESET,   KC_MS_WH_UP, KC_MS_U, KC_MS_WH_DOWN, KC_PTAB, KC_NTAB, KC_PGDOWN, KC_UP,   KC_PGUP,  ____,       \
  ____,    KC_MS_L,     KC_MS_D, KC_MS_R,       ____,    KC_NAPP, KC_LEFT,   KC_DOWN, KC_RIGHT, ____,       \
  ____,    ____,        ____,    ____,          ____,    ____,    ____,      ____,    ____,     TG(DVORAK), \
  KC_BTN3, KC_BTN2,     KC_BTN1, ____,          ____,    ____ \
)
};


static bool ime_state = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_IME:
      if (record->event.pressed) {
        if (ime_state) {
         register_code(KC_LANG2);
         unregister_code(KC_LANG2);
        }
        else {
         register_code(KC_LANG1);
         unregister_code(KC_LANG1);
        }
        ime_state = !ime_state;
      }
      break;
  }
  return true;
}

