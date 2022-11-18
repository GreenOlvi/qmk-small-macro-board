#include QMK_KEYBOARD_H

#define _BASE 0
#define _SPECIAL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │   │ En│
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_2x3(
        MO(_SPECIAL), KC_NO, KC_MUTE,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),

    [_SPECIAL] = LAYOUT_ortho_2x3(
        KC_TRANSPARENT, KC_NO, KC_END,
        KC_CALC, KC_MYCM, QK_BOOT
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SPECIAL] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
    case 1:
        rgblight_setrgb(0xFF,  0x00, 0xFF);
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