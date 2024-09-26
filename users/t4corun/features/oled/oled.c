#include "oled.h"
#include "oled_common.c"

// 5 x 16 characters

// Indicates which modifies are enabled
void render_mod_status (uint8_t col, uint8_t line) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(col,line);
    current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L1, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+1);
    current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L2, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+2);
    current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L3, false) : oled_write_P(off, false );

    oled_set_cursor(col,line+4);
    current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_L1, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+5);
    current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_L2, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+6);
    current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_L3, false) : oled_write_P(off, false );

    oled_set_cursor(col,line+7);
    current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_L1, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+8);
    current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_L2, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+9);
    current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_L3, false) : oled_write_P(off, false );

    oled_set_cursor(col,line+11);
    current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_L1, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+12);
    current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_L2, false) : oled_write_P(off, false );
    oled_set_cursor(col,line+13);
    current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_L3, false) : oled_write_P(off, false );
}

// Coordinate the OLED rendering
bool oled_task_user (void) {
    //process_record_user is only processed on master side
    //split side OLED does not respond to key presses custom behaviors
    if (is_keyboard_master()) {
        render_default_layer_state(0,1,true);
        render_layer_state_list(0,2,true);
        render_lock_status(1,14);
    } else {
        render_mod_status(0,2);
        //render_lock_status(1,14);
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_270 for Rollow/Corne/Swoop
    return OLED_ROTATION_270;
}
