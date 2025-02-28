#pragma once

#include "t4corun.h"

enum mods {
    MOD_SHIFT = 0,
    MOD_CTRL,
    MOD_ALT,
    MOD_GUI
};

// these are screen specific and defined in those related files
extern const char PROGMEM scroll_on[];
extern const char PROGMEM scroll_off[];
extern const char PROGMEM num_on[];
extern const char PROGMEM num_off[];
extern const char PROGMEM caps_on[];
extern const char PROGMEM caps_off[];

extern const char PROGMEM line_off[];
extern const uint8_t line_count; //total line count
extern const uint8_t shift_up;   //move RGB up how many lines

// these variable are defined in oled_common.c
extern const char PROGMEM mod_line_off[];
extern const char PROGMEM shift_on_L1[];
extern const char PROGMEM shift_on_L2[];
extern const char PROGMEM shift_on_L3[];
extern const char PROGMEM ctrl_on_L1[];
extern const char PROGMEM ctrl_on_L2[];
extern const char PROGMEM ctrl_on_L3[];
extern const char PROGMEM alt_on_L1[];
extern const char PROGMEM alt_on_L2[];
extern const char PROGMEM alt_on_L3[];
extern const char PROGMEM gui_on_L1[];
extern const char PROGMEM gui_on_L2[];
extern const char PROGMEM gui_on_L3[];

extern const char *shift_on[];
extern const char *ctrl_on[];
extern const char *alt_on[];
extern const char *gui_on[];

extern const char *default_layer_render_strings[];
extern const char *layer_render_strings[];




void render_default_layer_state (uint8_t row, uint8_t col);
void render_layer_state (uint8_t row, uint8_t col);
void render_layer_state_list (uint8_t row, uint8_t col);
void render_led_status (uint8_t row, uint8_t col);
void render_mods (uint8_t row, uint8_t col, uint8_t target_mod, uint8_t current_mods);
void render_mod_os (uint8_t row, uint8_t col);
void clear_lines (uint8_t row, uint8_t col, uint8_t lines);