#pragma once

#include "t4corun.h"

#define OLED_RENDER_DEFAULT_LAYER1    "Qwrty"
#define OLED_RENDER_DEFAULT_LAYER2    "Clmak"
#define OLED_RENDER_DEFAULT_LAYER3    "Game "
#define OLED_RENDER_LAYER_2           " Nav "
#define OLED_RENDER_LAYER_3           " Num "
#define OLED_RENDER_LAYER_4           " Sym "
#define OLED_RENDER_LAYER_5           " Fun "
#define OLED_RENDER_BLANK             "     "

extern const uint8_t shift_up;   //move RGB parameter display up

void render_led_status (uint8_t row, uint8_t col);
#if defined(RGB_MATRIX_ENABLE)
void render_rgb_status (uint8_t row, uint8_t col);
#endif // RGB_MATRIX_ENABLE
#if defined(POINTING_DEVICE_ENABLE)
__attribute__((weak)) void render_pointercpi_keymap(uint8_t row, uint8_t col);
#endif // POINTING_DEVICE_ENABLE
