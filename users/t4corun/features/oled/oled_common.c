#include "oled_common.h"

//elements correspond to the character position in the font array
const char PROGMEM mod_line_off[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0};
const char PROGMEM shift_on_L1[]  = {0x80, 0x81, 0x82, 0x83, 0x80, 0};
const char PROGMEM shift_on_L2[]  = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0};
const char PROGMEM shift_on_L3[]  = {0x80, 0xC1, 0xC2, 0xC3, 0x80, 0};
const char PROGMEM ctrl_on_L1[]   = {0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0};
const char PROGMEM ctrl_on_L2[]   = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0};
const char PROGMEM ctrl_on_L3[]   = {0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0};
const char PROGMEM alt_on_L1[]    = {0x80, 0x80, 0x80, 0x88, 0x80, 0};
const char PROGMEM alt_on_L2[]    = {0x80, 0x80, 0xA7, 0xA8, 0xA9, 0};
const char PROGMEM alt_on_L3[]    = {0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0};
const char PROGMEM gui_on_L1[]    = {0x80, 0x90, 0x91, 0x92, 0x93, 0};
const char PROGMEM gui_on_L2[]    = {0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0};
const char PROGMEM gui_on_L3[]    = {0x80, 0xD0, 0xD1, 0xD2, 0x80, 0};

const char *shift_on[]            = {shift_on_L1, shift_on_L2, shift_on_L3};
const char *ctrl_on[]             = {ctrl_on_L1,  ctrl_on_L2,  ctrl_on_L3};
const char *alt_on[]              = {alt_on_L1,   alt_on_L2,   alt_on_L3};
const char *gui_on[]              = {gui_on_L1,   gui_on_L2, gui_on_L3};

// Define the default layer render strings in an array for easier maintenance
const char *default_layer_render_strings[] = {
    [0]                   = OLED_RENDER_DEFAULT_LAYER1,
    [DEFAULT_LAYER_2]     = OLED_RENDER_DEFAULT_LAYER2,
    [DEFAULT_LAYER_3]     = OLED_RENDER_DEFAULT_LAYER3,
};

// Define the layer render strings in an array for easier maintenance
const char *layer_render_strings[] = {
    [0]           = OLED_RENDER_BLANK,
    [_NAVIGATION] = OLED_RENDER_LAYER_2,
    [_NUMBER]     = OLED_RENDER_LAYER_3,
    [_SYMBOL]     = OLED_RENDER_LAYER_4,
    [_FUNCTION]   = OLED_RENDER_LAYER_5,
};

// Shows the currently enabled Layer name
void render_default_layer_state (uint8_t row, uint8_t col) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();
    uint8_t highest_default_layer = get_highest_layer(default_layer_state);

    //highlight the base layer when the funciton layer is enabled and no modifiers are held
    bool setting_enabled = (get_highest_layer(layer_state) == _FUNCTION && current_mods == 0);

    //it checks to make sure the array has enough elements defined or we may have unexpected behavior
    const char *layer_string = (highest_default_layer < sizeof(default_layer_render_strings) / sizeof(default_layer_render_strings[0]))
                               ? default_layer_render_strings[highest_default_layer]
                               : OLED_RENDER_BLANK;

    oled_set_cursor(col, row);
    oled_write_P(PSTR(layer_string), setting_enabled);
}

// Shows the currently enabled Layer name
// This only shows the name that is enabled
void render_layer_state(uint8_t row, uint8_t col) {
    uint8_t highest_layer = get_highest_layer(layer_state);

    const char *layer_string = (highest_layer < sizeof(layer_render_strings) / sizeof(layer_render_strings[0]))
                               ? layer_render_strings[highest_layer]
                               : OLED_RENDER_BLANK;

    oled_set_cursor(col, row);
    oled_write_P(PSTR(layer_string), false);
}

// Shows the currently aenabled Layer name
// Renders a list of all the layers and highlights the active one
void render_layer_state_list(uint8_t row, uint8_t col) {
    uint8_t highest_layer = get_highest_layer(layer_state);

    oled_set_cursor(col, row);
    for (uint8_t i = 1; i < sizeof(layer_render_strings) / sizeof(layer_render_strings[0]); i++) {
        if (layer_render_strings[i] != NULL) {
            oled_write_P(PSTR(layer_render_strings[i]), highest_layer == i);
        }
    }
}

// Shows the Host LED State (Num lock, caps lock , scroll lock)
void render_led_status (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
    oled_write_P(host_keyboard_led_state().num_lock                       ? num_on   : num_off, false);
    oled_write_P(host_keyboard_led_state().caps_lock || is_caps_word_on() ? caps_on  : caps_off, false);
    oled_write_P(host_keyboard_led_state().scroll_lock                    ? scroll_on: scroll_off, false);
}

// render the mod if it is held.
void render_mods (uint8_t row, uint8_t col, uint8_t target_mod, uint8_t current_mods) {
    const char **mod_graphic;
    uint8_t mod_mask;
    size_t num_lines;

    switch(target_mod) {
        case MOD_SHIFT:
            mod_graphic = shift_on;
            mod_mask = MOD_MASK_SHIFT;
            num_lines = sizeof(shift_on) / sizeof(shift_on[0]);
            break;
        case MOD_CTRL:
            mod_graphic = ctrl_on;
            mod_mask = MOD_MASK_CTRL;
            num_lines = sizeof(ctrl_on) / sizeof(ctrl_on[0]);
            break;
        case MOD_ALT:
            mod_graphic = alt_on;
            mod_mask = MOD_MASK_ALT;
            num_lines = sizeof(alt_on) / sizeof(alt_on[0]);
            break;
        case MOD_GUI:
            mod_graphic = gui_on;
            mod_mask = MOD_MASK_GUI;
            num_lines = sizeof(gui_on) / sizeof(gui_on[0]);
            break;
        default:
            return;
    }

    for (uint8_t i = 0; i < num_lines; i++) {
        oled_set_cursor(col, row + i);
        oled_write_P(current_mods & mod_mask ? mod_graphic[i] : mod_line_off, false);
    }
}
