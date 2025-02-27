#pragma once

#include "t4corun.h"

#define OLED_RENDER_DEFAULT_LAYER1    "QWERTY    :"
#define OLED_RENDER_DEFAULT_LAYER2    "COLEMAK DH:"
#define OLED_RENDER_DEFAULT_LAYER3    "GAME      :"
#define OLED_RENDER_LAYER_2           "Navigation"
#define OLED_RENDER_LAYER_3           "Number    "
#define OLED_RENDER_LAYER_4           "Symbol    "
#define OLED_RENDER_LAYER_5           "Function  "
#define OLED_RENDER_BLANK             "Base      "
#if !defined(OLED_KEYBOARD_NAME)
#   define OLED_KEYBOARD_NAME         "QMK Keyboard"
#endif // OLED_KEYBOARD_NAME

//elements correspond to the character position in the font array
extern const char PROGMEM scroll_off[];
extern const char PROGMEM scroll_on[];
extern const char PROGMEM num_off[];
extern const char PROGMEM num_on[];
extern const char PROGMEM caps_off[];
extern const char PROGMEM caps_on[];

extern const char PROGMEM rgb_matrix_off[];
extern const char PROGMEM rgb_matrix_on[];
extern const char PROGMEM sound_off[];
extern const char PROGMEM sound_on[];
extern const char PROGMEM haptic_off[];
extern const char PROGMEM haptic_on[];
extern const char PROGMEM combo_off[];
extern const char PROGMEM combo_on[];

extern const char PROGMEM kb_logo_L1[];
extern const char PROGMEM kb_logo_L2[];

extern const char *kb_logo[];

extern const char PROGMEM mod_sep[];

extern const char PROGMEM line_off[];
extern const char PROGMEM line_sep[];
extern const char PROGMEM line_sep_short[];

void render_feature_status (uint8_t row, uint8_t col);
void render_rgb_status (uint8_t row, uint8_t col);
void render_kb_logo (uint8_t row, uint8_t col);

