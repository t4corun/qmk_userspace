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

#define _NONE_3__________________                   ___x___, ___x___, ___x___
#define _NONE_5____________________________________ ___x___, ___x___, ___x___, ___x___, ___x___
#define _GACS_MODS________________________          TR_LGUI, TR_LALT, TR_LCTL, TR_LSFT
#define _SCAG_MODS________________________          TR_LSFT, TR_LCTL, TR_LALT, TR_LGUI
#define _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define _BASE_L4_________________                   TR_BTN1, SYM,     MOUSE
#define _BASE_R4_________________                   KC_SPC,  NAV,     ___x___
#define _LAYER_TRANS_____________                   ___x___, _______, ___x___


  //___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,

#define BASETEST \
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, \
	                  KC_TAB,  KC_LSFT, KC_ENT,  KC_ENT,  KC_LSFT, KC_TAB


#define LAYER_QWERTY \
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_REP,  \
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  KC_MINS, \
	                  _BASE_L4_________________, _BASE_R4_________________


#define LAYER_COLEMAK_DH \
	KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_O,    \
	KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    TR_REP,  \
	KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  KC_MINS, \
	                  _BASE_L4_________________, _BASE_R4_________________


#define LAYER_NAVIGATION \
	KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, ___x___, KC_INS,  ___x___, ___x___, CONFIG,  \
	___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
	_UCCPR_L___________________________________, KC_DEL,  KC_APP,  KC_VOLD, KC_VOLU, KC_MUTE, \
	                  KC_TAB,  _______, KC_ENT,  _LAYER_TRANS_____________


#define LAYER_SYMBOL \
	KC_ESC,  KC_AMPR, KC_AT,   KC_DLR,  TR_PERC, KC_EQL,  KC_HASH, TR_LABK, KC_RABK, KC_GRV,  \
	KC_ENT,  KC_ASTR, KC_EXLM, KC_BSLS, KC_SCLN, KC_BSPC, KC_SLSH, TR_LBRC, KC_RBRC, TR_REP,  \
	_UCCPR_L___________________________________, KC_DEL,  KC_QUOT, TR_LPRN, TR_DOT,  KC_MINS, \
	                  _LAYER_TRANS_____________, _BASE_R4_________________


#define LAYER_NUMBER \
	KC_9,    KC_5,    KC_1,    KC_3,    KC_7,    KC_6,    KC_2,    KC_0,    KC_4,    KC_8,    \
	_GACS_MODS________________________, KC_F11,  KC_BSPC, KC_SPC,  ___x___, KC_F12,  TR_REP,  \
	KC_F9,   KC_F5,   KC_F1,   KC_F3,   KC_F7,   KC_F6,   KC_F2,   KC_F10,  KC_F4,   KC_F8,   \
	                  _LAYER_TRANS_____________, _LAYER_TRANS_____________


#define LAYER_CONFIG \
	___x___, ___x___, TR_DMR1, TR_DMP1, KC_PSCR, ___x___, ___x___, QK_BOOT, ___x___, _______, \
	TR_RTOG, TR_RMOD, TR_DMR2, TR_DMP2, KC_SCRL, KC_CAPS, _SCAG_MODS________________________, \
	TR_RHUI, TR_RSAI, TR_RVAI, TR_RSPI, KC_PAUS, _NONE_5____________________________________, \
	                  TR_GAME, CLMAKDH, QWERTY,  _LAYER_TRANS_____________


#define LAYER_MOUSE \
	___x___, ___x___, TR_MOUU, ___x___, TR_MWHU, TR_SDPI, TR_PDPI, ___x___, ___x___, ___x___, \
	___x___, TR_MOUL, TR_MOUD, TR_MOUR, TR_MWHD, ___x___, _SCAG_MODS________________________, \
	TR_SNIP, TR_BTN3, TR_BTN2, TR_BTN1, TR_DRGS, ___x___, TR_BTN1, TR_BTN2, TR_BTN3, ___x___, \
	                  ___x___, ___x___, _______, TR_BTN5, TR_BTN4, ___x___


#define LAYER_GAMING \
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    _NONE_5____________________________________, \
	GAMENUM, KC_A,    KC_S,    KC_D,    KC_F,    _NONE_5____________________________________, \
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _NONE_5____________________________________, \
	                  KC_LCTL, KC_SPC,  KC_LSFT, TR_ASTG, NAV,     ___x___


#define LAYER_GAMENUMBER \
	___x___, KC_ESC,  KC_TILD, KC_G,    KC_T,    _NONE_5____________________________________, \
	_______, KC_1,    KC_2,    KC_3,    KC_4,    _NONE_5____________________________________, \
	___x___, KC_5,    KC_6,    KC_7,    KC_8,    _NONE_5____________________________________, \
	                  KC_LALT, ___x___, KC_ENT,  TR_ASTG, NAV,     ___x___
