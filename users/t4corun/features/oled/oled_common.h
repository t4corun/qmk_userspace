#pragma once

#include "t4corun.h"

void render_default_layer_state (uint8_t col, uint8_t line, bool moveCursor);
void render_layer_state (uint8_t col, uint8_t line, bool moveCursor);
void render_layer_state_list (uint8_t col, uint8_t line, bool moveCursor);
void render_keylock_status (uint8_t col, uint8_t line);

/*
#if defined(OLED_DISPLAY_128X64)
#   define OLED_RENDER_DEFAULT_LAYER1    "QWERTY    :"
#   define OLED_RENDER_DEFAULT_LAYER2    "COLEMAK DH:"
#   define OLED_RENDER_DEFAULT_LAYER3    "GAME      :"
#   define OLED_RENDER_LAYER_1           "Base      "
#   define OLED_RENDER_LAYER_2           "Navigation"
#   define OLED_RENDER_LAYER_3           "Number    "
#   define OLED_RENDER_LAYER_4           "Symbol    "
#   define OLED_RENDER_LAYER_5           "Mouse     "
#   define OLED_RENDER_LAYER_6           "Function  "
#else
#   define OLED_RENDER_DEFAULT_LAYER1    "Qwrty"
#   define OLED_RENDER_DEFAULT_LAYER2    "Clmak"
#   define OLED_RENDER_DEFAULT_LAYER3    "Game "
#   define OLED_RENDER_LAYER_1           "     "
#   define OLED_RENDER_LAYER_2           " Nav "
#   define OLED_RENDER_LAYER_3           " Num "
#   define OLED_RENDER_LAYER_4           " Sym "
#   define OLED_RENDER_LAYER_5           " Mou "
#   define OLED_RENDER_LAYER_6           " Fun "
#endif // OLED_DISPLAY_128X64
*/
