#include "oled_common.h"

// Shows the currently enabled Layer name
void render_default_layer_state (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    switch (get_highest_layer(default_layer_state)) {
        case _DEFAULT_LAYER_2:
            oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER2), false);
            break;
        case _DEFAULT_LAYER_3:
            oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER3), false);
            break;
        default:
            oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER1), false);
            break;
    }
}

// Shows the currently enabled Layer name
// This only shows the name that is enabled
void render_layer_state (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    switch (get_highest_layer(layer_state)) {
        case _NAVIGATION:
            oled_write_P(PSTR(OLED_RENDER_LAYER_2), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR(OLED_RENDER_LAYER_3), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR(OLED_RENDER_LAYER_4), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR(OLED_RENDER_LAYER_5), false);
            break;
        default:
            oled_write_P(PSTR(OLED_RENDER_BLANK), false);
            break;
    }
}

// Shows the currently aenabled Layer name
// Renders a list of all the layers and highlights the active one
void render_layer_state_list (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    uint8_t current_layer = get_highest_layer(layer_state);
    oled_write_P(PSTR(OLED_RENDER_LAYER_2), current_layer == _NAVIGATION);
    oled_write_P(PSTR(OLED_RENDER_LAYER_3), current_layer == _NUMBER);
    oled_write_P(PSTR(OLED_RENDER_LAYER_4), current_layer == _SYMBOL);
    oled_write_P(PSTR(OLED_RENDER_LAYER_5), current_layer == _FUNCTION);
}

// Shows the Host LED State (Num lock, caps lock , scroll lock)
void render_led_status (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    host_keyboard_led_state().num_lock                       ? oled_write_P(num_on, false )    : oled_write_P(num_off, false);
    host_keyboard_led_state().caps_lock || is_caps_word_on() ? oled_write_P(caps_on, false )   : oled_write_P(caps_off, false);
    host_keyboard_led_state().scroll_lock                    ? oled_write_P(scroll_on, false ) : oled_write_P(scroll_off, false);
}

// render the mod icon only when specified modifier is held
void render_mod_shift (uint8_t row, uint8_t col, uint8_t mods) {
    oled_set_cursor(col, row);
    mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L1, false) : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 1);
    mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L2, false) : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 2);
    mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_L3, false) : oled_write_P(mod_line_off, false);
}

// render the mod icon only when specified modifier is held
void render_mod_ctrl (uint8_t row, uint8_t col, uint8_t mods) {
    oled_set_cursor(col, row);
    mods & MOD_MASK_CTRL  ? oled_write_P(ctrl_on_L1, false)  : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 1);
    mods & MOD_MASK_CTRL  ? oled_write_P(ctrl_on_L2, false)  : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 2);
    mods & MOD_MASK_CTRL  ? oled_write_P(ctrl_on_L3, false)  : oled_write_P(mod_line_off, false);
}

// render the mod icon only when specified modifier is held
void render_mod_alt (uint8_t row, uint8_t col, uint8_t mods) {
    oled_set_cursor(col, row);
    mods & MOD_MASK_ALT  ? oled_write_P(alt_on_L1, false)    : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 1);
    mods & MOD_MASK_ALT  ? oled_write_P(alt_on_L2, false)    : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 2);
    mods & MOD_MASK_ALT  ? oled_write_P(alt_on_L3, false)    : oled_write_P(mod_line_off, false);
}

// render the mod icon only when specified modifier is held
void render_mod_gui (uint8_t row, uint8_t col, uint8_t mods) {
    oled_set_cursor(col, row);
    mods & MOD_MASK_GUI  ? oled_write_P(gui_on_L1, false)    : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 1);
    mods & MOD_MASK_GUI  ? oled_write_P(gui_on_L2, false)    : oled_write_P(mod_line_off, false);
    oled_set_cursor(col, row + 2);
    mods & MOD_MASK_GUI  ? oled_write_P(gui_on_L3, false)    : oled_write_P(mod_line_off, false);
}
