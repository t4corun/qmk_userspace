#pragma once

#include "t4corun.h"

//128x32 are ? x 5 char wide
#define OLED_RENDER_DEFAULT_LAYER1    "Qwrty"
#define OLED_RENDER_DEFAULT_LAYER2    "Clmak"
#define OLED_RENDER_DEFAULT_LAYER3    "Game "
#define OLED_RENDER_LAYER_1           "     "
#define OLED_RENDER_LAYER_2           " Nav "
#define OLED_RENDER_LAYER_3           " Num "
#define OLED_RENDER_LAYER_4           " Sym "
#define OLED_RENDER_LAYER_5           " Mou "
#define OLED_RENDER_LAYER_6           " Fun "

void render_mod_status (uint8_t col, uint8_t line);

static const char PROGMEM off[]            = {0x80, 0x80, 0x80, 0x80, 0x80, 0};
static const char PROGMEM shift_on_L1[]    = {0x80, 0x81, 0x82, 0x83, 0x84, 0};
static const char PROGMEM shift_on_L2[]    = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0};
static const char PROGMEM shift_on_L3[]    = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
static const char PROGMEM ctrl_on_L1[]     = {0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0};
static const char PROGMEM ctrl_on_L2[]     = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0};
static const char PROGMEM ctrl_on_L3[]     = {0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0};
static const char PROGMEM alt_on_L1[]      = {0x85, 0x86, 0x87, 0x88, 0x89, 0};
static const char PROGMEM alt_on_L2[]      = {0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0};
static const char PROGMEM alt_on_L3[]      = {0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0};
static const char PROGMEM gui_on_L1[]      = {0x8F, 0x90, 0x91, 0x92, 0x93, 0};
static const char PROGMEM gui_on_L2[]      = {0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0};
static const char PROGMEM gui_on_L3[]      = {0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0};

static const char PROGMEM scroll_off[]        = {0x9E, 0};
static const char PROGMEM scroll_on[]         = {0x9F, 0};

static const char PROGMEM num_off[]           = {0xBE, 0};
static const char PROGMEM num_on[]            = {0xBF, 0};

static const char PROGMEM caps_off[]          = {0xDE, 0};
static const char PROGMEM caps_on[]           = {0xDF, 0};
