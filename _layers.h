#pragma once

enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,  
  _COLEMAK_DH,
  _GAMING,
  _NAVIGATION,
  _SYMBOL,
  _NUMBER,
  _MOUSE,
  _GAMENUMBER,
  _CONFIG
};

#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#define _DEFAULT_LAYER_3 (FIRST_DEFAULT_LAYER + 2)

#define __________NONE_3_________ ___x___, ___x___, ___x___

#define BASETEST \
	___x___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, \
	___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,	  KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, KC_TAB,	KC_LSFT, KC_ENT,  KC_ENT,  KC_LSFT, KC_TAB,  __________NONE_3_________