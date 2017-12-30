/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "nisse_mini.h"

#define XXXX KC_NO
#define ____ KC_TRNS

// for MacOS
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define NEXTAPP ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define PREVAPP ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)

enum Layer {
  QWERTY,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  MISC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty 
   *
   * Q W E R T   Y U I O P 
   * A S D F G   H J K L ; '
   * Z X C V B   N M , . / -
   */

  [QWERTY] = {
    {KC_TAB,           KC_Q,    KC_W,    KC_E,     KC_R,      KC_T,    PREVTAB,  NEXTTAB,  KC_Y,  KC_U, KC_I,    KC_O,             KC_P,     KC_BSPC},
    {KC_LCTL, LT(MISC, KC_A),   KC_S,    KC_D,     KC_F,      KC_G,    KC_LANG2, KC_LANG1, KC_H,  KC_J, KC_K,    KC_L,   LT(MISC,  KC_SCLN), KC_QUOT},
    {KC_ESC,           KC_Z,    KC_X,    KC_C,     KC_V,      KC_B,    XXXX,     XXXX,     KC_N,  KC_M, KC_COMM, KC_DOT,           KC_SLSH,  KC_MINS},
    {XXXX,    XXXX,          KC_LGUI,    XXXX,     MO(LOWER), SFT_T(KC_SPC), KC_LALT,
     KC_RALT, SFT_T(KC_ENT), MO(RAISE),  XXXX,     KC_RGUI,  XXXX,           XXXX}
  },

  /* Colemak
   *
   * Q W F P G   J L U Y ;
   * A R S T D   H N E I O '
   * Z X C V B   K M , . / -
   */

  [COLEMAK] = {
    {KC_TAB,           KC_Q,    KC_W,     KC_F,    KC_P,      KC_G,          PREVTAB,  NEXTTAB,  KC_J,          KC_L,      KC_U,    KC_Y,     KC_SCLN, KC_BSPC},
    {KC_LCTL, LT(MISC, KC_A),   KC_R,     KC_S,    KC_T,      KC_D,          KC_LANG2, KC_LANG1, KC_H,          KC_N,      KC_E,    KC_I,     LT(MISC, KC_O),    KC_QUOT},
    {KC_ESC,           KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,          XXXX,     XXXX,     KC_K,          KC_M,      KC_COMM, KC_DOT,   KC_SLSH, KC_MINS},
    {XXXX,             XXXX,    KC_LGUI,  XXXX,    MO(LOWER), SFT_T(KC_SPC), KC_LALT,
      KC_RALT,  SFT_T(KC_ENT), MO(RAISE), XXXX,    KC_RGUI,   XXXX,          XXXX}
  },

  /* Dvorak
   *
   * ' , . P Y   F G C R L
   * A O E U I   D H T N S -
   * ; Q J K X   B M W V Z /
   */

  [DVORAK] = {
    {KC_TAB,           KC_QUOT, KC_COMM,  KC_DOT,  KC_P,      KC_Y,          PREVTAB,  NEXTTAB,  KC_F,          KC_G,      KC_C,    KC_R,          KC_L,  KC_BSPC},
    {KC_LCTL, LT(MISC, KC_A),   KC_O,     KC_E,    KC_U,      KC_I,          KC_LANG2, KC_LANG1, KC_D,          KC_H,      KC_T,    KC_N, LT(MISC, KC_S), KC_MINS},
    {KC_ESC,           KC_SCLN, KC_Q,     KC_J,    KC_K,      KC_X,          XXXX,     XXXX,     KC_B,          KC_M,      KC_W,    KC_V,          KC_Z,  KC_SLSH},
    {XXXX,     XXXX,          KC_LGUI,   XXXX, MO(LOWER),    SFT_T(KC_SPC), KC_LALT,
     KC_RALT,  SFT_T(KC_ENT), MO(RAISE), XXXX, KC_RGUI,      XXXX,          XXXX}
  },

  [LOWER] = {
    {KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, ____, ____, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, ____},
    {____,   ____,    ____,  ____,    ____,   ____,    ____, ____, ____,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
    {____,   ____,    ____,  ____,    ____,   ____,    XXXX, XXXX, ____,    ____,    ____,    ____,    ____,    ____},
    {XXXX,   XXXX,    ____,  ____,    ____,   ____,    ____, ____, ____,    ____,    ____,    ____,    XXXX,    XXXX},
  },

  [RAISE] = {
    {KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, ____, ____, KC_6, KC_7,    KC_8,   KC_9,    KC_0,    ____},
    {____,    ____, ____, ____, ____, ____, ____, ____, ____, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS},
    {____,    ____, ____, ____, ____, ____, XXXX, XXXX, ____, ____,    ____,   ____,    ____,    ____},
    {XXXX,    XXXX, ____, ____, ____, ____, ____, ____, ____, ____,    ____,   ____,    XXXX,    XXXX},
  },

  [MISC] = {
    {KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,   ____, ____, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12},
    {____,  ____,  KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, ____, ____, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, ____,    ____},
    {RESET, ____,  ____,    ____,    ____,    ____,    XXXX, XXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU},
    {XXXX,  XXXX,  ____,    ____,    ____,    KC_BTN1, KC_BTN2, ____, ____, TG(QWERTY),  TG(COLEMAK), TG(DVORAK),    XXXX,    XXXX}
  },
};

//const uint16_t PROGMEM fn_actions[] = {
//
//};
//
//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
//  // MACRODOWN only works in this function
//      switch(id) {
//        case 0:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//          } else {
//            unregister_code(KC_RSFT);
//          }
//        break;
//      }
//    return MACRO_NONE;
//};
//
//
//void matrix_init_user(void) {
//
//}
//
//void matrix_scan_user(void) {
//
//}
//
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  return true;
//}
//
//void led_set_user(uint8_t usb_led) {
//
//}
