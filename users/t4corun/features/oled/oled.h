#pragma once

#include "t4corun.h"

#define OLED_RENDER_DEFAULT_LAYER1    "Qwrty"
#define OLED_RENDER_DEFAULT_LAYER2    "Clmak"
#define OLED_RENDER_DEFAULT_LAYER3    "Game "
#define OLED_RENDER_LAYER_2           " Nav "
#define OLED_RENDER_LAYER_3           " Num "
#define OLED_RENDER_LAYER_4           " Fun "
#define OLED_RENDER_BLANK             "     "

void render_led_status (uint8_t row, uint8_t col);

//elements correspond to the character position in the font array
static const char PROGMEM scroll_on[]   = {0x8F, 0};
static const char PROGMEM scroll_off[]  = {0x80, 0};
static const char PROGMEM num_on[]      = {0xC4, 0};
static const char PROGMEM num_off[]     = {0x80, 0};
static const char PROGMEM caps_on[]     = {0x87, 0};
static const char PROGMEM caps_off[]    = {0x80, 0};

static const char PROGMEM line_off[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0};
