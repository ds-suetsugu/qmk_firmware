#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY 0
#define LOWER 1
#define RAISE 2
#define MISC 3

// Fillers to make layering more clear
#define ____ KC_TRNS
#define XXXX KC_NO

#define TPREV ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define TNEXT ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)

enum my_keycodes {
  IME_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ESC  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -_  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | IME  | Misc | Alt  | GUI  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = KEYMAP( \
  KC_TAB,            KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,          KC_Y,          KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, LT(MISC,  KC_A),    KC_S,    KC_D,      KC_F,          KC_G,          KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_ESC,            KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,          KC_N,          KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
  IME_TOG,           MO(MISC), KC_LALT, KC_LGUI, MO(LOWER), SFT_T(KC_SPC), SFT_T(KC_ENT), MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |    ~ |    | |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  ____,    ____,  ____,    ____,   ____,    ____,    KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  ____,    ____,    ____,  ____,    ____,   ____,    ____,    KC_TILD,    KC_PIPE, ____,    ____,    ____,    \
  ____,    ____,    ____,  ____,    ____,   ____,    ____,    ____,       ____,       ____,    ____,    ____ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   `  |   \  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = KEYMAP( \
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL, ____, ____, ____, ____, ____, ____, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  ____,   ____, ____, ____, ____, ____, ____, KC_GRV,  KC_BSLS, ____,    ____,    ____,    \
  ____,   ____, ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    ____ \
),

/* Misc 
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |TNEXT |TPREV |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |MPREV |MPLAY |MNEXT |Vol** |Vol-- |Vol++ |
 * `-----------------------------------------------------------------------------------'
 */

[MISC] =  KEYMAP( \
  KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  ____,  ____,  KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, ____,    TNEXT,   TPREV,   ____,    ____,    ____,   \
  ____,  ____,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,   \
  RESET, ____,  ____,    ____,    KC_BTN2, KC_BTN1, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU \
)

};

static bool ime_state = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case IME_TOG:
      if (record->event.pressed) {
        if (ime_state) {
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
          ime_state = !ime_state;
        }
        else {
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
          ime_state = !ime_state;
        }
      }
      return false;
      break;
  }
  return true;
}
