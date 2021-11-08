#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_GRV,  KC_MUTE,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G, KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, KC_LGUI, KC_LALT, MO(1),   KC_BSPC,      KC_SPC,       MO(1),   KC_RALT, KC_RGUI, XXXXXXX
    ),
    [1] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,  KC_9,    KC_0,    _______, _______,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_F11,  KC_F12,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,  _______,
        XXXXXXX, _______, _______, MO(2),   KC_ESC,           KC_ENT,           MO(2), _______, _______, XXXXXXX
    ),
    [2] = LAYOUT(
        _______, LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),     LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, _______,
        _______, LSFT(KC_MINS), LSFT(KC_EQL), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS), KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    _______,
        _______, _______,      _______,      _______,        _______,       _______,       _______,    _______,    _______,    _______,    _______ ,   _______,
        XXXXXXX, _______,      _______,      XXXXXXX,        _______,                      _______,                XXXXXXX,    _______,    _______,    XXXXXXX
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 2) {
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
        if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}
