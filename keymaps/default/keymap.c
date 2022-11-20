#include QMK_KEYBOARD_H

#define _BASE 0
#define _SWITCH 1
#define _SCROLL 2
#define _SHORTCUTS 3
#define _TEAMS 4
#define _META 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │   │ En│
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_2x3(
        MO(_SWITCH), KC_NO, KC_MUTE,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),

    [_SWITCH] = LAYOUT_ortho_2x3(
        KC_TRNS, KC_NO, TG(_META),
        TG(_SCROLL), TG(_SHORTCUTS), TG(_TEAMS)
    ),

    [_SCROLL] = LAYOUT_ortho_2x3(
        TO(_BASE), KC_NO, KC_HOME,
        KC_PGUP, KC_PGDN, KC_END
    ),

    [_SHORTCUTS] = LAYOUT_ortho_2x3(
        TO(_BASE), KC_NO, KC_WHOM,
        KC_CALC, KC_MYCM, KC_MAIL
    ),

    [_TEAMS] = LAYOUT_ortho_2x3(
        TO(_BASE), KC_NO, C(S(KC_E)),
        C(S(KC_M)), C(S(KC_O)), C(S(KC_K))
    ),

    [_META] = LAYOUT_ortho_2x3(
        TO(_BASE), KC_NO, KC_TRNS,
        RGB_TOG, RGB_MOD, QK_BOOT
    )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SWITCH] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SCROLL] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_SHORTCUTS] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_TEAMS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_META] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
    case _SWITCH:
        rgblight_setrgb(0xFF,  0xFF, 0xFF);
        break;
    case _SCROLL:
        rgblight_setrgb(0xFF,  0xFF, 0x00);
        break;
    case _SHORTCUTS:
        rgblight_setrgb(0x00,  0xFF, 0x00);
        break;
    case _TEAMS:
        rgblight_setrgb(0xFF,  0x00, 0xFF);
        break;
    case _META:
        rgblight_setrgb(0x00,  0x00, 0xFF);
        break;
    default:
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
    }
  return state;
}

void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_setrgb(0x00, 0x00, 0x00);
}