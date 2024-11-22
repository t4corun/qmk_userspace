#include "oled.h"
#include "oled_common.c"

/* render vertical OLED
 * 16 rows x 5 cols
 *
 * Left side (split)
 * - spacing is weird because of where the image is in the font
 * - this side won't show anything unless mods or host state are active
 *
 * 00  sssss
 * 01  shift
 * 02  sssss
 * 03
 * 04  ccccc
 * 05  *ctrl
 * 06  ccccc
 * 07  aaaaa
 * 08  *alt*
 * 09  aaaaa
 * 10
 * 11  ggggg
 * 12  *gui*
 * 13  ggggg
 * 14
 * 15   NCS
 *
 *
 * Right side (main)
 * - this will show data all the time
 *
 * 00  bslyr
 * 01   nav
 * 02   num
 * 03   sym
 * 04   mou
 * 05   fun
 * 06
 * 07  -cpi-
 * 08  xxxxx
 * 09
 * 10  -rgb-
 * 11  m 999
 * 12  h 999
 * 13  s 999
 * 14  v 999
 * 15  s 999
 *
 */

#if defined(RGB_MATRIX_ENABLE)
void render_rgb_status (uint8_t row, uint8_t col) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(col, row);
    oled_write_P(PSTR("-rgb-"), false);
    for ( int i = 0; i < 5; i++ ) {
        oled_write_P(line_off, false);
    }

    oled_set_cursor(col, row + 1);
    if (rgb_matrix_is_enabled()) {
        if (get_highest_layer(layer_state) == _FUNCTION) {
            current_mods == ( MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) ) ? oled_write_P(PSTR("m "), true)                           : oled_write_P(PSTR("m "), false);
            current_mods == ( MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) ) ? oled_write(get_u8_str(rgb_matrix_get_mode(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_mode(), ' '), false);
            oled_set_cursor(col, row + 2);
            current_mods == MOD_BIT(KC_LSFT) ? oled_write_P(PSTR("h "), true)                          : oled_write_P(PSTR("h "), false);
            current_mods == MOD_BIT(KC_LSFT) ? oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
            oled_set_cursor(col, row + 3);
            current_mods == MOD_BIT(KC_LCTL) ? oled_write_P(PSTR("s "), true)                          : oled_write_P(PSTR("s "), false);
            current_mods == MOD_BIT(KC_LCTL) ? oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
            oled_set_cursor(col, row + 4);
            current_mods == MOD_BIT(KC_LALT) ? oled_write_P(PSTR("v "), true)                          : oled_write_P(PSTR("v "), false);
            current_mods == MOD_BIT(KC_LALT) ? oled_write(get_u8_str(rgb_matrix_get_val(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_val(), ' '), false);
            oled_set_cursor(col, row + 5);
            current_mods == MOD_BIT(KC_LGUI) ? oled_write_P(PSTR("s "), true)                            : oled_write_P(PSTR("s "), false);
            current_mods == MOD_BIT(KC_LGUI) ? oled_write(get_u8_str(rgb_matrix_get_speed(), ' '), true) : oled_write(get_u8_str(rgb_matrix_get_speed(), ' '), false);
        } else {
            oled_write_P(PSTR("  on "), false);
        }
    } else {
        bool toggle_ready = (get_highest_layer(layer_state) == _FUNCTION && current_mods == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL)));
        toggle_ready ? oled_write_P(PSTR(" off "), true) : oled_write_P(PSTR(" off "), false);
    }
}
#endif // RGB_MATRIX_ENABLE


#if defined(POINTING_DEVICE_ENABLE)
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
__attribute__((weak)) void render_pointercpi_keymap(uint8_t row, uint8_t col) {
}
#endif // POINTING_DEVICE_ENABLE

// Render each screen
bool oled_task_user (void) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();
    //process_record_user is only processed on master side
    //split side OLED does not respond to key presses custom behaviors
    if (is_keyboard_master()) {
        render_default_layer_state(0,0);
        render_layer_state_list(1,0);
#if defined(POINTING_DEVICE_ENABLE)
        render_pointercpi_keymap(6,0);
#endif // POINTING_DEVICE_ENABLE
#if defined(RGB_MATRIX_ENABLE)
        render_rgb_status(9,0);
#endif // RGB_MATRIX_ENABLE
    } else {
        render_mod_shift(0,0, current_mods);
        render_mod_ctrl(4,0, current_mods);
        render_mod_alt(7,0, current_mods);
        render_mod_gui(11,0, current_mods);
        render_led_status(15,1);
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_270 for Rollow/Corne/Swoop
    return OLED_ROTATION_270;
}
