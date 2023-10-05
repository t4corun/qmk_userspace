#pragma once
#include "t4corun.h"

#define RGB_MATRIX_INDICATOR_SET_COLOR_wrapper(...) RGB_MATRIX_INDICATOR_SET_COLOR(__VA_ARGS__)

//qmk_firmware\keyboards\crkbd\rev1\rev1.c
#if defined(KEYBOARD_crkbd_rev1)
//layers
#   define LED_SYMBOL 13
#   define LED_NAVIGATION 40
#   define LED_MOUSE 33
#   define LED_NUMBER_L 13
#   define LED_NUMBER_R 40
#   define LED_CONFIG 50
#   define LED_GAMENUMBER 22

//base layers
#   define LED_QWERTY 6
#   define LED_COLEMAKDH 13
#   define LED_GAME 14

//indicators
#   define LED_CAPSLOCK 35
#   define LED_SCRLOCK 8

//dynamic macros
#   define LED_DMACRO_R1 17
#   define LED_DMACRO_P1 10
#   define LED_DMACRO_R2 16
#   define LED_DMACRO_P2 11

//shift keys
#   define LED_SHIFT_L 11
#   define LED_SHIFT_R 38

//control keys
#   define LED_CTRL_L 16
#   define LED_CTRL_R 43

//alt keys
#   define LED_ALT_L 19
#   define LED_ALT_R 46

//GUI keys
#   define LED_GUI_L 22
#   define LED_GUI_R 49

//Reset LED
#   define LED_RESET 44

#   define BACKLED_MIN 0
#   define BACKLED_MAX RGB_MATRIX_LED_COUNT

//qmk_firmware\keyboards\bastardkb\charybdis\3x5\3x5.c
#elif defined(KEYBOARD_bastardkb_charybdis_3x5)
//layers
#   define LED_SYMBOL 16
#   define LED_NAVIGATION 34
#   define LED_MOUSE 17
#   define LED_NUMBER_L 16
#   define LED_NUMBER_R 34
#   define LED_CONFIG 20
#   define LED_GAMENUMBER 1

//base layers
#   define LED_QWERTY 17
#   define LED_COLEMAKDH 16
#   define LED_GAME 15

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

#elif defined(KEYBOARD_planck_rev6)

#   define BACKLED_MIN 0
#   define BACKLED_MAX RGB_MATRIX_LED_COUNT

#endif

#define LAYER_GAMING_COLOR RGB_RED
#define LAYER_NAVIGATION_COLOR RGB_AZURE
#define LAYER_SYMBOL_COLOR RGB_CYAN
#define LAYER_NUMBER_COLOR RGB_PURPLE
#define LAYER_MOUSE_COLOR RGB_CORAL
#define LAYER_CONFIG_COLOR RGB_GOLDENROD

#define KEY_LAYER_COLOR RGB_AZURE
#define KEY_TRILAYER_COLOR RGB_PURPLE
#define KEY_DEFAULTLAYER_COLOR RGB_PURPLE
#define KEY_RESET_COLOR RGB_BLUE
#define KEY_MACROREC_COLOR RGB_RED
#define KEY_MACROPLY_COLOR RGB_GREEN


#define MOD_SHIFT_COLOR RGB_WHITE
#define MOD_CTRL_COLOR RGB_CORAL
#define MOD_ALT_COLOR RGB_PINK
#define MOD_GUI_COLOR RGB_GOLDENROD

#define CAPSLOCK_COLOR RGB_WHITE
#define SCROLLOCK_COLOR RGB_WHITE