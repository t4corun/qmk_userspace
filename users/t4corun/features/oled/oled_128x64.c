#include "oled_128x64.h"
#include "oled_common.c"

/* render horizonal OLED (Work in progress)
 * 21 cols x 8 rows
 *
 * left side (split)
 *
 * 00  base lyr: current lyr
 * 01  ---------------------
 * 02
 * 03   mod  mod  mod  mod
 * 04   mod  mod  mod  mod
 * 05
 * 06  -------------- xxxxx
 * 07   NCS           xxxxx
 *
 *
 * 00  base lyr: current lyr
 * 01  ---------------------
 * 02  ssssscccccaaaaaggggg
 * 03  ssssscccccaaaaaggggg
 * 04  ssssscccccaaaaaggggg
 * 05
 * 06  -------------- xxxxx
 * 07   NCS           xxxxx
 *
 * right side (main)
 *
 * 00  KLOR Saegewerk
 * 01  ---------------------
 * 02  RGB matrix mode: xxx
 * 03  hue: xxx    sat: xxx
 * 04  val: xxx    spd: xxx
 * 05
 * 06  -------------- xxxxx
 * 07   xx xx xx xx   xxxxx
 *
 */

void render_feature_status (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_is_enabled() ? oled_write_P(rgb_matrix_on, false) : oled_write_P(rgb_matrix_off, false);
#else
    oled_write_P(rgb_matrix_off, false);
#endif //RGB_MATRIX_ENABLED
    oled_set_cursor(col + 3, row);
#if defined(AUDIO_ENABLE)
    is_audio_on() ? oled_write_P(sound_on, false) : oled_write_P(sound_off, false);
#else
    oled_write_P(sound_off, false);
#endif //AUDIO_ENABLE
    oled_set_cursor(col + 6, row);
#if defined(HAPTIC_ENABLE)
    haptic_get_enable() ? oled_write_P(haptic_on, false) : oled_write_P(haptic_off, false);
#else
    oled_write_P(haptic_off, false);
#endif //HAPTIC_ENABLE
    oled_set_cursor(col + 9, row);
#if defined(COMBO_ENABLE)
    is_combo_enabled() ? oled_write_P(combo_on, false) : oled_write_P(combo_off, false);
#else
    oled_write_P(combo_off, false);
#endif //HAPTIC_ENABLE
}

#if defined(RGB_MATRIX_ENABLE)
void render_rgb_status (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    for ( int i = 0; i < 4; i++ ) {
        oled_write_P(line_off, false);
    }
    oled_set_cursor(col, row);

    if (rgb_matrix_is_enabled()) {
        uint8_t current_mods = get_mods() | get_oneshot_mods();

        current_mods == ( MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) ) ? oled_write_P(PSTR("rgb matrix mode: "), true)            : oled_write_P(PSTR("rgb matrix mode: "), false);
        current_mods == ( MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) ) ? oled_write(get_u8_str(rgb_matrix_get_mode(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_mode(), ' '), false);
        oled_set_cursor(col, row + 1);
        current_mods == MOD_BIT(KC_LSFT) ? oled_write_P(PSTR("hue: "), true)                       : oled_write_P(PSTR("hue: "), false);
        current_mods == MOD_BIT(KC_LSFT) ? oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
        oled_set_cursor(col + 12, row + 1);
        current_mods == MOD_BIT(KC_LCTL) ? oled_write_P(PSTR("sat: "), true)                       : oled_write_P(PSTR("sat: "), false);
        current_mods == MOD_BIT(KC_LCTL) ? oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
        oled_set_cursor(col, row + 2);
        current_mods == MOD_BIT(KC_LALT) ? oled_write_P(PSTR("val: "), true)                       : oled_write_P(PSTR("val: "), false);
        current_mods == MOD_BIT(KC_LALT) ? oled_write(get_u8_str(rgb_matrix_get_val(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_val(), ' '), false);
        oled_set_cursor(col + 12, row + 2);
        current_mods == MOD_BIT(KC_LGUI) ? oled_write_P(PSTR("spd: "), true)                         : oled_write_P(PSTR("spd: "), false);
        current_mods == MOD_BIT(KC_LGUI) ? oled_write(get_u8_str(rgb_matrix_get_speed(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_speed(), ' '), false);
    } else {
        oled_write_P(PSTR("rgb mammtrix:      off"), false);
    }
}
#endif // RGB_MATRIX_ENABLE

void render_kb_logo (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    oled_write_P(kb_logo_L1, false);
    oled_set_cursor(col, row + 1);
    oled_write_P(kb_logo_L2, false);
}

// Coordinate the OLED rendering
bool oled_task_user (void) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();
    if (is_keyboard_master()) {
        oled_write_P(PSTR(OLED_KEYBOARD_NAME), false);
        oled_set_cursor(0,1);
        oled_write_P(line_sep, false);
        render_rgb_status(2,0);
        oled_set_cursor(0,6);
        oled_write_P(line_sep_short, false);
        render_feature_status(7,1);
        render_kb_logo(6,15);
    } else {
        render_default_layer_state(0,0);
        render_layer_state(0,11);
        render_mod_shift(2,0, current_mods);
        render_mod_ctrl(2,5, current_mods);
        render_mod_alt(2,10, current_mods);
        render_mod_gui(2,15, current_mods);
        oled_set_cursor(0,1);
        oled_write_P(line_sep, false);
        oled_set_cursor(0,6);
        oled_write_P(line_sep_short, false);
        render_led_status(7,1);
        render_kb_logo(6,15);
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_180 for KLOR
    return OLED_ROTATION_180;
}
