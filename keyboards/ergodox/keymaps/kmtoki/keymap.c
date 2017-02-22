#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer: TODO
 *
 * .-------------------------------------------------.           .--------------------------------------------------.
 * |        |  1! |   2@ |   3# |   4$ |   5% |      |           |      |   6^ |   7& |   8* |  9(  |  0)  |        |
 * |--------+-----+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |  Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |  P   |   -_   |
 * |--------+-----+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/ESC|A/L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;:/L2 |   '"   |
 * |--------+-----+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |  Z  |   X  |   C  |   V  |   B  |  L1  |           |  L1  |   N  |   M  |  ,<  |  .>  |  /?  |   =+   |
 * `--------+-----+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EISU | Alt |  Cmd |  \|  |  `~  |                                       |   [{ |  }]  |  Cmd |  Alt | KANA |
 *                                     ,----------------,       ,---------------,
 *                                     | Esc/Ctrl| TG_L1|       | TG_L2|Esc/Ctrl|
 *                              ,------|---------|------|       |------+--------+------.
 *                              |Space |         | Home |       | PgUp |        |Space |
 *                              |/Shift| BSpace  |------|       |------| Tab    |/Enter|
 *                              |      |         | End  |       | PgDn |        |      |
 *                              `-----------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,        KC_1,           KC_2,    KC_3,    KC_4,     KC_5,   KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,    KC_E,    KC_R,     KC_T,   KC_TRNS,
        CTL_T(KC_ESC),  LT(MDIA,KC_A),  KC_S,    KC_D,    KC_F,     KC_G,
        KC_LSFT,        KC_Z,           KC_X,    KC_C,    KC_V,     KC_B,   MO(SYMB),
        KC_LANG2,       KC_LALT,        KC_LGUI, KC_BSLS, KC_GRV,
                                                           CTL_T(KC_ESC),  TG(SYMB),
                                                                           KC_HOME,
                                                   SFT_T(KC_SPC), KC_BSPC, KC_END,
        // right hand
             KC_TRNS,     KC_6,   KC_7,     KC_8,    KC_9,    KC_0,             KC_TRNS,
             KC_TRNS,     KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,             KC_MINS,
                          KC_H,   KC_J,     KC_K,    KC_L,    LT(MDIA,KC_SCLN), KC_QUOT,
             MO(SYMB),    KC_N,   KC_M,     KC_COMM, KC_DOT,  CTL_T(KC_SLSH),   KC_EQL,
                                  KC_LBRC,  KC_RBRC, KC_LGUI, KC_RALT,          KC_LANG1,
             TG(MDIA), CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,  KC_TAB, SFT_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,    KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F11,
       KC_TRNS,     KC_1,     KC_2,    KC_3,     KC_4,     KC_5,  KC_TRNS,
       KC_TRNS,  KC_EXLM,    KC_AT, KC_HASH,   KC_DLR,  KC_PERC,
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                                    RGB_MOD,   KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_F12,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
       KC_TRNS,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_F12,
                KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RSET   |      |      |      |      |      |      |           |      |      |      |      |      |      |PWR/SLEP|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MPRV | MsUp | MNXT | WH_U |      |           |      | Home | PgUp | Up   | PgDn |      |  WAKE  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght| WH_D |------|           |------| End  | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Mute |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BTN3 |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BTN1 | BTN2 |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MPRV, KC_MS_U, KC_MNXT, KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_BTN3, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MT(KC_PWR,KC_SLEP),
       KC_TRNS,  KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_WAKE,
                 KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

}
