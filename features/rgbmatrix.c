#include "rgbmatrix.h"

/*
Achieves the following
- layer tap key indicator when we are in layer
- Caps lock and scroll lock indicators when activated
- dpad backlight while in game mode
- mouse button backlight when in mouse layer
- modifier indicators when activated
- default layer indicator

Really only for the charybdis nano, and even then I don't really look down at the 
RGB
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){

  uint8_t current_layer = get_highest_layer(layer_state);
  uint8_t current_default_layer = get_highest_layer(default_layer_state);
  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  switch(current_layer) {

    case _SYMBOL:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SYMBOL, KEY_LAYER_COLOR);
      break;

    case _NAVIGATION:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NAVIGATION, KEY_LAYER_COLOR);
      break;

    case _MOUSE:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_MOUSE, KEY_LAYER_COLOR);
      break;

    case _NUMBER:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NUMBER_L, KEY_TRILAYER_COLOR);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NUMBER_R, KEY_TRILAYER_COLOR);
      break;

    case _CONFIG: 
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CONFIG, KEY_LAYER_COLOR);

      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_RESET, KEY_RESET_COLOR);

      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_R1, KEY_MACROREC_COLOR);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_P1, KEY_MACROPLY_COLOR);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_R2, KEY_MACROREC_COLOR);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_P2, KEY_MACROPLY_COLOR);

      switch (current_default_layer) {
        
        case _DEFAULT_LAYER_1:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_QWERTY, KEY_DEFAULTLAYER_COLOR);
          break;
        
        case _DEFAULT_LAYER_2:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_COLEMAKDH, KEY_DEFAULTLAYER_COLOR);
          break;
        
        case _DEFAULT_LAYER_3:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAME, KEY_DEFAULTLAYER_COLOR);
          break;
      }
      break;

    case _GAMENUMBER:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAMENUMBER, KEY_LAYER_COLOR);
      break;

    default:
      switch (current_default_layer) {
        case _DEFAULT_LAYER_3:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAME, KEY_DEFAULTLAYER_COLOR);
          break;
      }
      break;
  }

  if ( (current_mod | current_osm) & MOD_MASK_SHIFT ) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SHIFT_L, MOD_SHIFT_COLOR);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SHIFT_R, MOD_SHIFT_COLOR);
  }

  if ( (current_mod | current_osm) & MOD_MASK_CTRL ) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CTRL_L, MOD_CTRL_COLOR);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CTRL_R, MOD_CTRL_COLOR);
  }

  if ( (current_mod | current_osm) & MOD_MASK_ALT ) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_ALT_L, MOD_ALT_COLOR);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_ALT_R, MOD_ALT_COLOR);
  }

  if ( (current_mod | current_osm) & MOD_MASK_GUI ) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GUI_L, MOD_GUI_COLOR);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GUI_R, MOD_GUI_COLOR);
  }

  if (host_keyboard_led_state().caps_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CAPSLOCK, CAPSLOCK_COLOR);
  }

  if (host_keyboard_led_state().scroll_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SCRLOCK, SCROLLOCK_COLOR);
  }

#if defined(CAPS_WORD_ENABLE)  
  if (is_caps_word_on()) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CAPSLOCK, CAPSLOCK_COLOR);
  }
#endif //CAPS_WORD_ENABLE

  return false;
}