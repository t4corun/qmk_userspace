#pragma once

enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,
  _COLEMAK_DH,
  _NAVIGATION,
  _NUMBER,
  _SYMBOL,
  _FUNCTION,
  _MOUSE,
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

#define _BASE_L4_________________                   TR_BTN1, NUM,     TR_LSFT
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
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_QUOT, \
  TR_MOUZ, KC_X,    TR_MOUC, KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________


#define LAYER_COLEMAK_DH \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TR_QUOT, \
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
  TR_MOUZ, KC_X,    TR_MOUC, KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________


#define LAYER_NAVIGATION \
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,  VS_FOLD, ___x___, VS_UFLD, CONFIG,  \
  ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
  _UCCPR_L___________________________________, KC_DEL,  KC_APP,  KC_VOLD, KC_VOLU, KC_MUTE, \
                    KC_TAB,  _______, KC_ENT,  _LAYER_TRANS_____________


#define LAYER_NUMBER \
  KC_ESC,  SC_SNIP, SC_FILE, FUNC,    TR_GRV,  KC_ENT,  KC_7,    KC_8,    KC_9,    KC_TAB,  \
  _GACS_MODS________________________, TR_SCLN, KC_BSPC, KC_4,    KC_5,    KC_6,    KC_DOT,  \
  _UCCPR_L___________________________________, KC_DEL,  KC_1,    KC_2,    KC_3,    TR_MINS, \
                    _LAYER_TRANS_____________, _BASE_R4_________________


#define LAYER_SYMBOL \
  KC_ESC,  ___x___, KC_AT,   KC_DLR,  TR_GRV,  TR_EQL,  KC_HASH, KC_ASTR, ___x___, TR_DQUO, \
  KC_AMPR, TR_LCBR, KC_RCBR, KC_PIPE, TR_SCLN, KC_BSPC, KC_QUES, TR_LBRC, KC_RBRC, TR_SQUO, \
  TR_PERC, TR_LABK, KC_RABK, KC_BSLS, KC_EXLM, KC_DEL,  KC_SLSH, TR_LPRN, TR_DOT,  TR_MINS, \
                    _LAYER_TRANS_____________, _LAYER_TRANS_____________


#define LAYER_FUNCTION \
  TR_DMP2, TR_DMR2, ___x___, _______, ___x___, KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  ___x___, ___x___, ___x___, ___x___, KC_SCRL, KC_CAPS, KC_F4,   KC_F5,   KC_F6,   KC_F11, \
  _UCCPR_L___________________________________, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F12, \
                    _LAYER_TRANS_____________, TR_DMP1, TR_DMR1, ___x___


#define LAYER_MOUSE \
  ___x___, ___x___, TR_MOUU, ___x___, TR_MWHU, TR_SDPI, TR_PDPI, ___x___, ___x___, ___x___, \
  ___x___, TR_MOUL, TR_MOUD, TR_MOUR, TR_MWHD, ___x___, _SCAG_MODS________________________, \
  _______, ___x___, _______, TR_DRGS, TR_SNIP, ___x___, TR_BTN1, TR_BTN2, TR_BTN3, ___x___, \
                    TR_BTN1, TR_BTN2, TR_BTN3, TR_BTN5, TR_BTN4, ___x___


#define LAYER_CONFIG \
  ___x___, ___x___, ___x___, ___x___, ___x___, EE_CLR,  QK_RBT,  QK_BOOT, ___x___, _______, \
  TR_RTOG, TR_RMOD, ___x___, ___x___, ___x___, ___x___, _SCAG_MODS________________________, \
  TR_RHUI, TR_RSAI, TR_RVAI, TR_RSPI, ___x___, _NONE_5____________________________________, \
                    ___x___, CLMAKDH, QWERTY,  _LAYER_TRANS_____________
