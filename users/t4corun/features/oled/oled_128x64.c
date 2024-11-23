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
typedef struct {
    uint8_t mod;
    const char *label;
    uint8_t (*get_value)(void);
    uint8_t col_offset;
    uint8_t row_offset;
} ModDisplay;

ModDisplay mod_displays[] = {
    {MOD_MASK_RGB_MODE, "rgb matrix mode: ", rgb_matrix_get_mode,  0,  0},
    {MOD_MASK_RGB_HUE,  "hue: ",             rgb_matrix_get_hue,   0,  1},
    {MOD_MASK_RGB_SAT,  "sat: ",             rgb_matrix_get_sat,   12, 1},
    {MOD_MASK_RGB_VAL,  "val: ",             rgb_matrix_get_val,   0,  2},
    {MOD_MASK_RGB_SPD,  "spd: ",             rgb_matrix_get_speed, 12, 2},
};

void render_rgb_status (uint8_t row, uint8_t col) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();
    bool setting_enabled = false;

    oled_set_cursor(col, row);
    for ( int i = 0; i < 4; i++ ) {
        oled_write_P(line_off, false);
    }

    oled_set_cursor(col, row);
    if (rgb_matrix_is_enabled()) {
        for (uint8_t i = 0; i < sizeof(mod_displays) / sizeof(mod_displays[0]); i++) {
            setting_enabled = (get_highest_layer(layer_state) == _FUNCTION && current_mods == mod_displays[i].mod);
            oled_set_cursor(col + mod_displays[i].col_offset, row + mod_displays[i].row_offset);
            oled_write_P(PSTR(mod_displays[i].label), false);
            oled_write(get_u8_str(mod_displays[i].get_value(), ' '), setting_enabled);
        }
    } else {
        setting_enabled = (get_highest_layer(layer_state) == _FUNCTION && current_mods == MOD_MASK_RGB_MODE);
        oled_write_P(PSTR("rgb matrix:      "), false);
        oled_write_P(PSTR("off"), setting_enabled);
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
        render_mods(2, 0,  MOD_SHIFT, current_mods);
        render_mods(2, 5,  MOD_CTRL,  current_mods);
        render_mods(2, 10, MOD_ALT,   current_mods);
        render_mods(2, 15, MOD_GUI,   current_mods);
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
