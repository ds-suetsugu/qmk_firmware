#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY 0
#define LOWER 1
#define RAISE 2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,--------------------------------------------------------------------------------------.
   * | Tab   |   Q  |   W  |   E  |   R   |   T  |   Y   |   U  |   I  |   O  |   P  | Bksp |
   * |-------+------+------+------+-------+------+-------+------+------+------+------+------|
   * |Esc/Ctl|   A  |   S  |   D  |   F   |   G  |   H   |   J  |   K  |   L  |  ;:  |  '"  |
   * |-------+------+------+------+-------+------|-------+------+------+------+------+------|
   * | Eisu  |   Z  |   X  |   C  |   V   |   B  |   N   |   M  |  ,<  |  .>  |  /?  | Kana |
   * |-------+------+------+------+-------+------+-------+------+------+------+------+------|
   * |       |      | Alt  | GUI  | Lower |Sp/Sft|Ent/Sft| Raise| GUI  | ALT  |      |      |
   * `--------------------------------------------------------------------------------------'
   */
  [QWERTY] = KEYMAP( \
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,           KC_Y,           KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,  \
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,      KC_G,           KC_H,           KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  \
    KC_LANG2,      KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,           KC_N,           KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  KC_LANG1, \
    _______,       _______, KC_LALT, KC_LGUI, MO(LOWER), SFT_T(KC_SPC),  SFT_T(KC_ENT),  MO(RAISE), KC_RGUI, KC_RALT, _______,  _______   \
  ),

  /* Lower 
   * ,-----------------------------------------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   `  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   \  |   |  |   -  |   _  |   =  |   +  |   [  |   ]  |   {  |   }  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [LOWER] = KEYMAP( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,  \
    _______, KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Raise 
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |MsWhUp| MsLf | MsUp | MsDn | MsRg |MsWhDn|PageDn|CrsrLf|CrsrDn|CrsrUp|CrsrRg|PageUp|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      | Prev |StpPly| Next |Mute  |VolDn |VolUp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Reset |      |      |      |ClickL|ClickR|      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [RAISE] = KEYMAP( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  \
    KC_WH_U, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGUP, \
    _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, \
    RESET,   _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______,  _______  \
  ),
};
