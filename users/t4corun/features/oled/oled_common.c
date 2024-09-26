#include "oled_common.h"

// Shows the currently enabled Layer name
void render_default_layer_state (uint8_t col, uint8_t line, bool moveCursor) {
    if(moveCursor) {
        oled_set_cursor(col, line);
    }

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
void render_layer_state (uint8_t col, uint8_t line, bool moveCursor) {
    if(moveCursor) {
        oled_set_cursor(col, line);
    }

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
        case _MOUSE:
            oled_write_P(PSTR(OLED_RENDER_LAYER_5), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR(OLED_RENDER_LAYER_6), false);
            break;
        default:
            oled_write_P(PSTR(OLED_RENDER_LAYER_1), false);
            break;
    }
}

// Shows the currently aenabled Layer name
// Renders a list of all the layers and highlights the active one
void render_layer_state_list (uint8_t col, uint8_t line, bool moveCursor) {
    if(moveCursor) {
        oled_set_cursor(col, line);
    }

    uint8_t current_layer = get_highest_layer(layer_state);

    oled_write_P(PSTR(OLED_RENDER_LAYER_2), current_layer == _NAVIGATION);
    oled_write_P(PSTR(OLED_RENDER_LAYER_3), current_layer == _NUMBER);
    oled_write_P(PSTR(OLED_RENDER_LAYER_4), current_layer == _SYMBOL);
    oled_write_P(PSTR(OLED_RENDER_LAYER_5), current_layer == _MOUSE);
    oled_write_P(PSTR(OLED_RENDER_LAYER_6), current_layer == _FUNCTION);
}

// Shows the Host LED State (Num lock, caps lock , scroll lock)
void render_lock_status (uint8_t col, uint8_t line) {
    oled_set_cursor(col, line);
    host_keyboard_led_state().num_lock ? oled_write_P(num_on, false ) : oled_write_P(num_off, false );
    host_keyboard_led_state().caps_lock || is_caps_word_on() ? oled_write_P(caps_on, false ) : oled_write_P(caps_off, false );
    host_keyboard_led_state().scroll_lock ? oled_write_P(scroll_on, false ) : oled_write_P(scroll_off, false );
}
