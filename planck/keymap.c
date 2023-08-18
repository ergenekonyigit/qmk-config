/* Copyright 2021 Ergenekon Yigit
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
#include QMK_KEYBOARD_H


enum glosso_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _RGB,
  _SPACE,
  _EMOJI,
  _ADJUST,
  _EMPTY
};

// Screen Lock shortcut
#define LOCKOSX LCTL(LSFT(KC_PWR))
// Emoji popup
#define EMOJIPOPUP LGUI(LCTL(KC_SPC))
// Switch input source
#define SWITCHINPUT LCTL(LALT(KC_SPC))

// Macros
enum custom_keycodes {
    EMOJI
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EMOJI:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_SPC);
            layer_on(_EMOJI);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_SPC);
        } else {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_SPC);
            layer_off(_EMOJI);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_SPC);
        }
        break;

    }
    return true;
};

// Emojis
enum unicode_names {
    // Row 0
    JOY,   // 😂
    SMIL2, // 😅
    SMILE, // 😁
    GRIN,  // 😊
    KISS,  // 😘
    HALO,  // 😇
    PHEW,  // 😌
    CONFU, // 😕
    PENSV, // 😔
    UNAMU, // 😒
    DISAP, // 😞

    // Row 1
    CELE,  // 🙌
    OK,    // 👌
    PRAY,  // 🙏
    CLAP,  // 👏
    THMUP, // 👍

    // Row 2
    EYES,  // 👀
    HUNRD  // 💯
};

const uint32_t PROGMEM unicode_map[] = {
    // Row 0
    [JOY]   = 0X1F602,
    [SMIL2] = 0x1F605,
    [SMILE] = 0x1F601,
    [GRIN]  = 0x1F600,
    [KISS]  = 0x1F618,
    [HALO]  = 0x1F607,
    [PHEW]  = 0x1F60C,
    [CONFU] = 0x1F615,
    [PENSV] = 0x1F614,
    [UNAMU] = 0x1F612,
    [DISAP] = 0x1F61E,

    // Row 1
    [CELE]  = 0x1F64C,
    [OK]    = 0x1F44C,
    [PRAY]  = 0x1F64F,
    [CLAP]  = 0x1F44F,
    [THMUP] = 0x1F44D,

    // Row 2
    [EYES]  = 0x1F440,
    [HUNRD] = 0x1F4AF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |  tab  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   | bkspc |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  esc  |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | shift |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   | enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  rgb  | cntrl |  alt  |  cmd  | lower | space | space | raise |  cmd  |  alt  | cntrl | emoji |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,               KC_Y,               KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,       KC_G,               KC_H,               KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,               KC_N,               KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    MO(_RGB),        KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), LT(_SPACE, KC_SPC), LT(_SPACE, KC_SPC), MO(_RAISE), KC_RGUI, KC_RALT, KC_RCTL, EMOJI
),

/* lower
 * ,-----------------------------------------------------------------------------------------------.
 * |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   | bkspc |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  del  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   _   |   +   |   {   |   }   |   |   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  | iso ~ | iso | | home  |  end  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | next  | vol - | vol + | play  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* raise
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | bkspc |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  del  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   -   |   =   |   [   |   ]   |   \   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  | iso # | iso / | pg up | pg dn |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | next  | vol - | vol + | play  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* rgb
 * ,-----------------------------------------------------------------------------------------------.
 * |       |  rgb  |rgbmod |       |       |       |       |   7   |   8   |   9   |   -   | bkspc |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | hue + | hue - |       |       |       | enter |   4   |   5   |   6   |   +   |   *   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | sat + | sat + |       |       |       | enter |   1   |   2   |   3   |   +   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | val + | val - |       |       |       |       |   0   |   0   |   .   |   ,   |   =   |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RGB] = LAYOUT_ortho_4x12(
    _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9,   KC_PMNS, KC_BSPC,
    _______, RGB_HUI, RGB_HUD, _______, _______, _______, KC_PENT, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_PAST,
    _______, RGB_SAI, RGB_SAD, _______, _______, _______, KC_PENT, KC_P1, KC_P2, KC_P3,   KC_PPLS, KC_PSLS,
    _______, RGB_VAI, RGB_VAD, _______, _______, _______, _______, KC_P0, KC_P0, KC_PDOT, KC_PCMM, KC_PEQL
),

/* space
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |  up   |       |       |lockosx|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       | left  | down  | right |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_SPACE] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, LOCKOSX,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* emoji
 * ,-----------------------------------------------------------------------------------------------.
 * |  tab  |  😂   |  😅   |  😁   |  😊   |  😘   |  😇   |  😌   |  😕   |  😔   |  😒   |  😞   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | cntrl |  🙌   |  👌   |  🙏   |  👏   |  👍   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | shift |  👀   |  💯   |       |       |       |       |       |       |  up   |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | cntrl |  alt  |  cmd  |       |s-input| popup |       | left  | down  | right |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_EMOJI] = LAYOUT_ortho_4x12(
    KC_TAB,  X(JOY),  X(SMIL2), X(SMILE), X(GRIN), X(KISS),     X(HALO),    X(PHEW),  X(CONFU), X(PENSV), X(UNAMU), X(DISAP),
    KC_LCTL, X(CELE), X(OK),    X(PRAY),  X(CLAP), X(THMUP),    _______,    _______,  _______,  _______,  _______,  _______,
    KC_LSFT, X(EYES), X(HUNRD), _______,  _______, _______,     _______,    _______,  _______,  KC_UP,    _______,  _______,
    _______, KC_LCTL, KC_LALT,  KC_LGUI,  _______, SWITCHINPUT, EMOJIPOPUP, _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______
),

/* adjust (lower + raise)
 * ,-----------------------------------------------------------------------------------------------.
 * |       | reset |eep rst|       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |mus mod|aud on |aud off|       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |voice -|voice +|mus on |mus off|       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    _______, RESET,   EEP_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______,
    _______, _______, _______, _______, _______, _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* empty
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_EMPTY] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_MAC);
}

// Enable the adjust layer when both lower and raise
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
