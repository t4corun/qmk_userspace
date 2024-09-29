#pragma once

#include "t4corun.h"

void render_default_layer_state (uint8_t row, uint8_t col);
void render_layer_state (uint8_t row, uint8_t col);
void render_layer_state_list (uint8_t row, uint8_t col);
void render_led_status (uint8_t row, uint8_t col);
void render_mod_shift (uint8_t row, uint8_t col, uint8_t mods);
void render_mod_ctrl (uint8_t row, uint8_t col, uint8_t mods);
void render_mod_alt (uint8_t row, uint8_t col, uint8_t mods);
void render_mod_gui (uint8_t row, uint8_t col, uint8_t mods);



//elements correspond to the character position in the font array
static const char PROGMEM mod_line_off[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0};
static const char PROGMEM shift_on_L1[]  = {0x80, 0x81, 0x82, 0x83, 0x80, 0};
static const char PROGMEM shift_on_L2[]  = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0};
static const char PROGMEM shift_on_L3[]  = {0x80, 0xC1, 0xC2, 0xC3, 0x80, 0};
static const char PROGMEM ctrl_on_L1[]   = {0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0};
static const char PROGMEM ctrl_on_L2[]   = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0};
static const char PROGMEM ctrl_on_L3[]   = {0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0};
static const char PROGMEM alt_on_L1[]    = {0x80, 0x80, 0x80, 0x88, 0x80, 0};
static const char PROGMEM alt_on_L2[]    = {0x80, 0x80, 0xA7, 0xA8, 0xA9, 0};
static const char PROGMEM alt_on_L3[]    = {0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0};
static const char PROGMEM gui_on_L1[]    = {0x80, 0x90, 0x91, 0x92, 0x93, 0};
static const char PROGMEM gui_on_L2[]    = {0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0};
static const char PROGMEM gui_on_L3[]    = {0x80, 0xD0, 0xD1, 0xD2, 0x80, 0};
