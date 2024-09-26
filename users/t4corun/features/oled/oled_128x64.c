#include "oled_128x64.h"
#include "oled_common.c"

/* render horizonal OLED
 * 21 x 8 characters
 *
 * base lyr: current lyr
 * ---------------------
 *
 *  mod  mod  mod  mod
 *  mod  mod  mod  mod
 *
 * -------------- xxxxx
 *  NCS xx xx xx  xxxxx
 */

// Indicates which modifies are enabled
void render_mod_status (uint8_t col, uint8_t line) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    // draw the top line
    oled_set_cursor(col, line);
    current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_upper, false) : oled_write_P(shift_off_upper, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_upper, false ) : oled_write_P(ctrl_off_upper, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_upper, false ) : oled_write_P(alt_off_upper, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_upper, false ) : oled_write_P(gui_off_upper, false );

    // draw the lower line
    oled_set_cursor(col, line + 1);
    current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_lower, false) : oled_write_P(shift_off_lower, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_lower, false ) : oled_write_P(ctrl_off_lower, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_lower, false ) : oled_write_P(alt_off_lower, false );
    oled_write_P(mod_sep, false);
    current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_lower, false ) : oled_write_P(gui_off_lower, false );
}

void render_feature_status (uint8_t col, uint8_t line) {
    oled_set_cursor(col,line);
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_is_enabled() ? oled_write_P(rgb_matrix_on, false) : oled_write_P(rgb_matrix_off, false);
#else
    oled_write_P(rgb_matrix_off, false);
#endif //RGB_MATRIX_ENABLED

    oled_set_cursor(col+3,line);
#if defined(AUDIO_ENABLE)
    is_audio_on() ? oled_write_P(sound_on, false) : oled_write_P(sound_off, false);
#else
    oled_write_P(sound_off, false);
#endif //AUDIO_ENABLE

    oled_set_cursor(col+6,line);
#if defined(HAPTIC_ENABLE)
    haptic_get_enable() ? oled_write_P(haptic_on, false) : oled_write_P(haptic_off, false);
#else
    oled_write_P(haptic_off, false);
#endif //HAPTIC_ENABLE
}

void render_klor_face_small (uint8_t col, uint8_t line) {
    oled_set_cursor(col,line);
    oled_write_P(klor_small_face_1, false);

    oled_set_cursor(col,line+1);
    oled_write_P(klor_small_face_2, false);
}

// Coordinate the OLED rendering
bool oled_task_user (void) {
    if (is_keyboard_master()) {
        render_default_layer_state(0,0, true);
        render_layer_state(0,0, false);

        oled_set_cursor(0,1);
        oled_write_P(sep_v, false);

        render_mod_status(1,3);

        oled_set_cursor(0,6);
        oled_write_P(sep_short_v, false);

        render_lock_status(1,7);
        render_feature_status(5,7);
        render_klor_face_small(15,6);
    } else {
        oled_set_cursor(0,0);
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_180 for KLOR
    return OLED_ROTATION_180;
}
