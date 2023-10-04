#include "rgbmatrix.h"

/*
Achieves the following
- layer tap key indicator when we are in layer
- Caps lock and scroll lock indicators when activated
- dpad backlight while in game mode
- mouse button backlight when in mouse layer
- modifier indicators when activated
- default layer indicator

Color preview

( 0, RGB_AZURE);
( 1, RGB_BLACK);
( 2, RGB_BLUE);
( 3, RGB_CHARTREUSE);
( 4, RGB_CORAL);
( 5, RGB_CYAN);
( 6, RGB_GOLD);
( 7, RGB_GOLDENROD);
( 8, RGB_GREEN);
( 9, RGB_MAGENTA);
( 10, RGB_ORANGE);
( 11, RGB_PINK);
( 14, RGB_PURPLE);
( 13, RGB_RED);
( 12, RGB_SPRINGGREEN);
( 32, RGB_TEAL);
( 29, RGB_TURQUOISE);
( 24, RGB_WHITE);
( 23, RGB_YELLOW);
*/



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){

  uint8_t current_layer = get_highest_layer(layer_state);
  uint8_t current_default_layer = get_highest_layer(default_layer_state);

#if defined(KEYBOARD_planck_rev6)

  RGB current_color = {RGB_OFF};

    switch(current_layer) {

      case _SYMBOL:
        current_color = { RGB_AZURE };
        break;

      case _NAVIGATION:
        current_color = { RGB_CORAL };
        break;

      case _MOUSE:
        current_color = { RGB_GOLDENROD };
        break;

      case _NUMBER:
        current_color = { RGB_PURPLE };
        break;

      case _CONFIG:
        current_color = { RGB_PINK };
        break;

      default:
        switch (current_default_layer) {
          case _DEFAULT_LAYER_1:
          case _DEFAULT_LAYER_2:
            break;

          case _DEFAULT_LAYER_3:
            current_color = { RGB_RED };
            break;
        }
        break;
    }

  if ( current_color != RGB_OFF ) {

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_INDICATOR_SET_COLOR_wrapper( i, current_color );
    }

  }
 

#else

  switch(current_layer) {

    case _SYMBOL:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SYMBOL, RGB_AZURE);
      break;

    case _NAVIGATION:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NAVIGATION, RGB_AZURE);
      break;

    case _MOUSE:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_MOUSE, RGB_AZURE);
      break;

    case _NUMBER:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NUMBER_L, RGB_PURPLE);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_NUMBER_R, RGB_PURPLE);
      break;

    case _CONFIG: 
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CONFIG, RGB_AZURE);

      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_RESET, RGB_BLUE);

      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_R1, RGB_RED);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_P1, RGB_GREEN);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_R2, RGB_RED);
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_DMACRO_P2, RGB_GREEN);

      switch (current_default_layer) {
        
        case _DEFAULT_LAYER_1:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_QWERTY, RGB_PURPLE);
          break;
        
        case _DEFAULT_LAYER_2:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_COLEMAKDH, RGB_PURPLE);
          break;
        
        case _DEFAULT_LAYER_3:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAME, RGB_PURPLE);
          break;
      }
      break;

    case _GAMENUMBER:
      RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAMENUMBER, RGB_AZURE);
      break;

    default:
      switch (current_default_layer) {
        case _DEFAULT_LAYER_1:
        case _DEFAULT_LAYER_2:
          break;
        
        case _DEFAULT_LAYER_3:
          RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GAME, RGB_PURPLE);
          break;
      }
      break;
  }

  uint8_t current_mod = get_mods();

#if defined(ONESHOT_ENABLE)
  uint8_t current_osm = get_oneshot_mods();

  bool isShift = ((current_mod & MOD_BIT(KC_LSFT)) || (current_osm & MOD_BIT(KC_LSFT)));
  bool isCtrl  = ((current_mod & MOD_BIT(KC_LCTL)) || (current_osm & MOD_BIT(KC_LCTL)));
  bool isAlt   = ((current_mod & MOD_BIT(KC_LALT)) || (current_osm & MOD_BIT(KC_LALT)));
  bool isGUI   = ((current_mod & MOD_BIT(KC_LGUI)) || (current_osm & MOD_BIT(KC_LGUI)));
#else
  bool isShift = (current_osm & MOD_BIT(KC_LSFT));
  bool isCtrl  = (current_osm & MOD_BIT(KC_LCTL));
  bool isAlt   = (current_osm & MOD_BIT(KC_LALT));
  bool isGUI   = (current_osm & MOD_BIT(KC_LGUI));
#endif //ONESHOT_ENABLE

  if(isShift){
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SHIFT_L, RGB_GOLDENROD);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SHIFT_R, RGB_GOLDENROD);
  }

  if(isCtrl){
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CTRL_L, RGB_CORAL);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CTRL_R, RGB_CORAL);
  }

  if(isAlt){
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_ALT_L, RGB_PINK);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_ALT_R, RGB_PINK);
  }

  if(isGUI){
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GUI_L, RGB_WHITE);
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_GUI_R, RGB_WHITE);
  }

  if (host_keyboard_led_state().caps_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CAPSLOCK, RGB_GOLDENROD);
  }

  if (host_keyboard_led_state().scroll_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_SCRLOCK, RGB_GOLDENROD);
  }

#if defined(CAPS_WORD_ENABLE)  
  if (is_caps_word_on()) {
    RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(LED_CAPSLOCK, RGB_ORANGE);
  }
#endif //CAPS_WORD_ENABLE





#endif //KEYBOARD_planck_rev6

  return false;
}