#pragma once
#include "t4corun.h"

/*
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



#define LAYER_NAVIGATION_COLOR RGB_AZURE
#define LAYER_SYMBOL_COLOR RGB_CYAN
#define LAYER_NUMBER_COLOR RGB_PURPLE
#define LAYER_MOUSE_COLOR RGB_CORAL
#define LAYER_CONFIG_COLOR RGB_GOLDENROD

#define KEY_LAYER_COLOR RGB_AZURE
#define KEY_TRILAYER_COLOR RGB_PURPLE
#define KEY_DEFAULTLAYER_COLOR RGB_PURPLE
#define KEY_RESET_COLOR RGB_MAGENTA
#define KEY_MACROREC_COLOR RGB_PINK
#define KEY_MACROPLY_COLOR RGB_TURQUOISE


#define MOD_SHIFT_COLOR RGB_WHITE
#define MOD_CTRL_COLOR RGB_CORAL
#define MOD_ALT_COLOR RGB_PINK
#define MOD_GUI_COLOR RGB_GOLDENROD

#define CAPSLOCK_COLOR RGB_WHITE
#define SCROLLOCK_COLOR RGB_WHITE

//so we can send the predefined RGB colors without requiring separate RGB values
#define RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(...) RGB_MATRIX_INDICATOR_SET_COLOR(__VA_ARGS__)

//qmk_firmware\keyboards\bastardkb\charybdis\3x5\3x5.c
#if defined(KEYBOARD_bastardkb_charybdis_3x5)
//layers
#   define LED_SYMBOL 16
#   define LED_NAVIGATION 34
#   define LED_MOUSE 17
#   define LED_NUMBER_L 16
#   define LED_NUMBER_R 34
#   define LED_CONFIG 20

//base layers
#   define LED_QWERTY 17
#   define LED_COLEMAKDH 16

//indicators
#   define LED_CAPSLOCK 31
#   define LED_SCRLOCK 13

//dynamic macros
#   define LED_DMACRO_R1 8
#   define LED_DMACRO_P1 9
#   define LED_DMACRO_R2 7
#   define LED_DMACRO_P2 10

//shift keys
#   define LED_SHIFT_L 10
#   define LED_SHIFT_R 28

//control keys
#   define LED_CTRL_L 7
#   define LED_CTRL_R 25

//alt keys
#   define LED_ALT_L 4
#   define LED_ALT_R 22

//GUI keys
#   define LED_GUI_L 1
#   define LED_GUI_R 19

//Reset LED
#   define LED_RESET 26

#endif