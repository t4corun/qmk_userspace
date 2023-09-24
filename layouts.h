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

enum keycodes {
  QWERTY = SAFE_RANGE,
  CLMAKDH,
  GAMING,

  //These are only here to make the case statements unique in taphold.c
  TH_LBRC,
  TH_LABK,
  TH_SQUO,
  TH_DQUO,
  TH_LPRN,
  TH_PERC,
  TH_COMM,
  TH_DOT
};

#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#define _DEFAULT_LAYER_3 (FIRST_DEFAULT_LAYER + 2)

#define ___x___ KC_NO

#	define         __________NONE_3_________				  ___x___, ___x___, ___x___
#   define __________________NONE_5___________________        ___x___, ___x___, ___x___, ___x___, ___x___

#define LAYOUT_cnano_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)

#define BASETEST \
	___x___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, \
	___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,	  KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, KC_TAB,  KC_LSFT, KC_ENT,  KC_ENT,  KC_LSFT, KC_TAB,  __________NONE_3_________



#define C_35(k) L_4x12_TO_3x5_nano(k)
#define L_4x12_TO_3x5_nano( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b  \
) \
         k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a,      \
		 k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a,      \
         k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a,      \
         		   k33, k34, k35, k36, k37