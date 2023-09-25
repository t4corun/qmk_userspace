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

//momentary layer
#define NAV        MO(_NAVIGATION)
#define SYM        MO(_SYMBOL)
#define CONFIG     MO(_CONFIG)
#define MOUSE      MO(_MOUSE)
#define GAMENUM    MO(_GAMENUMBER)

//Windows Shortcuts
#define SC_COPY    LCTL(KC_C)
#define SC_CUT     LCTL(KC_X)
#define SC_UNDO    LCTL(KC_Z)
#define SC_PAST    LCTL(KC_V)
#define SC_REDO    LCTL(KC_Y)


/*
- Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
- If the feature is disabled then the key is just the normal key
- We will only define things that are used across different layers. Entire layers are turned off in the keymap
*/

#if defined(ONESHOT_ENABLE)
#   define TR_LSFT OSM(MOD_LSFT)
#   define TR_LCTL OSM(MOD_LCTL)
#   define TR_LALT OSM(MOD_LALT)
#   define TR_LGUI OSM(MOD_LGUI)
#else
#   define TR_LSFT KC_LSFT
#   define TR_LCTL KC_LCTL
#   define TR_LALT KC_LALT
#   define TR_LGUI KC_LGUI
#endif //ONESHOT_ENABLE

#if defined(MOUSELAYER_ENABLE)
#   define MOUSE   MO(_MOUSE)
#   define TR_BTN1 KC_BTN1
#   define TR_BTN2 KC_BTN2
#   define TR_BTN3 KC_BTN3
#   define TR_BTN4 KC_BTN4
#   define TR_BTN5 KC_BTN5
#else
#   define MOUSE   ___x___
#   define TR_BTN1 ___x___
#   define TR_BTN2 ___x___
#   define TR_BTN3 ___x___
#   define TR_BTN4 ___x___
#   define TR_BTN5 ___x___
#endif //MOUSELAYER_ENABLE

#if defined(MOUSEKEY_ENABLE)
#   define TR_MOUU KC_MS_U
#   define TR_MOUD KC_MS_D
#   define TR_MOUL KC_MS_L
#   define TR_MOUR KC_MS_R
#   define TR_MWHU KC_WH_U
#   define TR_MWHD KC_WH_D
#else
#   define TR_MOUU ___x___
#   define TR_MOUD ___x___
#   define TR_MOUL ___x___
#   define TR_MOUR ___x___
#   define TR_MWHU ___x___
#   define TR_MWHD ___x___
#endif //MOUSEKEY_ENABLE

//these keycodes come from the cnano
#if defined(POINTING_DEVICE_ENABLE)
#   define TR_SNIP SNIPING
#   define TR_SNIT SNP_TOG
#   define TR_DRGS DRGSCRL
#   define TR_DRGT DRG_TOG
#   define TR_SDPI S_D_MOD
#   define TR_PDPI DPI_MOD
#else
#   define TR_SNIP ___x___
#   define TR_SNIT ___x___
#   define TR_DRGS ___x___
#   define TR_DRGT ___x___
#   define TR_SDPI ___x___
#   define TR_PDPI ___x___
#endif //POINTING_DEVICE_ENABLE

#if defined(GAMELAYER_ENABLE) 
#   define TR_GAME GAMING
#else
#   define TR_GAME ___x___
#endif //GAMELAYER_ENABLE

//For tap hold keys we will override the hold to issue alternate keystrokes rather than enable the layer
#if defined(TAPHOLD_ENABLE)
//Brackets
#   define TR_LBRC  LT(_DEFAULT_LAYER_1, TH_LBRC)
#   define TR_LABK  LT(_DEFAULT_LAYER_1, TH_LABK)
//Custom
#   define TR_LPRN  LT(_DEFAULT_LAYER_1, TH_LPRN)
#   define TR_PERC  LT(_DEFAULT_LAYER_1, TH_PERC)
#   define TR_COMM  LT(_DEFAULT_LAYER_1, TH_COMM)
#   define TR_DOT   LT(_DEFAULT_LAYER_1, TH_DOT)
#else
//Brackets
#   define TR_LBRC  KC_LBRC
#   define TR_LABK  KC_LABK
//Custom
#   define TR_LPRN  KC_LPRN
#   define TR_PERC  KC_PERC //TODO when tap hold is off typing ^ will not be possible
#   define TR_COMM  KC_COMM
#   define TR_DOT   KC_DOT
#endif //TAPHOLD_ENABLE

#if defined(DYNAMIC_MACRO_ENABLE)
#   define TR_DMR1 DM_REC1
#   define TR_DMP1 DM_PLY1
#   define TR_DMR2 DM_REC2
#   define TR_DMP2 DM_PLY2
#else
#   define TR_DMR1 ___x___
#   define TR_DMP1 ___x___
#   define TR_DMR2 ___x___
#   define TR_DMP2 ___x___
#endif //DYNAMIC_MACRO_ENABLE

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#   define TR_RHUI RGB_HUI
#   define TR_RSAI RGB_SAI
#   define TR_RVAI RGB_VAI
#   define TR_RSPI RGB_SPI
#   define TR_RTOG RGB_TOG
#   define TR_RMOD RGB_MOD
#else
#   define TR_RHUI ___x___
#   define TR_RSAI ___x___
#   define TR_RVAI ___x___
#   define TR_RSPI ___x___
#   define TR_RTOG ___x___
#   define TR_RMOD ___x___
#endif //RGB_MATRIX_ENABLE or RGBLIGHT_ENABLE

#if defined(REPEAT_KEY_ENABLE)
#   define TR_REP QK_REP
#else
#   define TR_REP TR_LSFT
#endif //REPEAT_KEY_ENABLE

#if defined(AUTO_SHIFT_ENABLE)
#   define TR_ASDN AS_DOWN
#   define TR_ASUP AS_UP
#   define TR_ASRP AS_RPT
#   define TR_ASTG AS_TOGG
#else
#   define TR_ASDN ___x___
#   define TR_ASUP ___x___
#   define TR_ASRP ___x___
#   define TR_ASTG ___x___
#endif //REPEAT_KEY_ENABLE




#	define         __________NONE_3_________				  ___x___, ___x___, ___x___
#   define __________________NONE_5___________________        ___x___, ___x___, ___x___, ___x___, ___x___
#   define _________________UCCPR_L___________________        SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#   define    _____________GACS_MODS____________              TR_LGUI, TR_LALT, TR_LCTL, TR_LSFT
#   define    _____________SCAG_MODS____________              TR_LSFT, TR_LCTL, TR_LALT, TR_LGUI

#   define         _________BASE_L4_________                  TR_BTN1, SYM,     MOUSE
#   define         _________TRANS_L4________                  ___x___, _______, ___x___

//right side only has two thumb keys
#if defined(KEYBOARD_bastardkb_charybdis_3x5)
#   define         _________BASE_R4_________                  KC_SPC,  NAV
#   define         _________TRANS_R4________                  ___x___, _______
#else
#   define         _________BASE_R4_________                  KC_SPC,  NAV,     ___x___
#   define         _________TRANS_R4________                  ___x___, _______, ___x___
#endif //KEYBOARD_bastardkb_charybdis_3x5

#define BASETEST \
	___x___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, \
	___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,	  KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, KC_TAB,	KC_LSFT, KC_ENT,  KC_ENT,  KC_LSFT, KC_TAB,  __________NONE_3_________

#define LAYER_QWERTY \
	___x___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, \
	___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,	  KC_H,    KC_J,    KC_K,    KC_L,    TR_REP,  ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, _________BASE_L4_________, _________BASE_R4_________, __________NONE_3_________


#define LAYER_COLEMAK_DH \
	___x___, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_O,    ___x___, \
	___x___, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,	  KC_M,    KC_N,    KC_E,    KC_I,    TR_REP,  ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, _________BASE_L4_________, _________BASE_R4_________, __________NONE_3_________


#define LAYER_NAVIGATION \
	___x___, KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, ___x___, KC_INS,  ___x___, ___x___, CONFIG,  ___x___, \
	___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _____________SCAG_MODS____________, ___x___, \
	___x___, _________________UCCPR_L___________________, KC_DEL,  KC_APP,  KC_VOLD, KC_VOLU, KC_MUTE, ___x___, \
	__________NONE_3_________, KC_TAB,  _______, KC_ENT,  _________TRANS_R4________, __________NONE_3_________


#define LAYER_SYMBOL \
	___x___, KC_ESC,  KC_AMPR, KC_AT,   KC_DLR,  TR_PERC, KC_EQL,  KC_HASH, TR_LABK, KC_RABK, KC_GRV,  ___x___, \
	___x___, KC_ENT,  KC_ASTR, KC_EXLM, KC_BSLS, KC_SCLN, KC_BSPC, KC_SLSH, TR_LBRC, KC_RBRC, TR_REP,  ___x___, \
	___x___, _________________UCCPR_L___________________, KC_DEL,  KC_QUOT, TR_LPRN, TR_DOT,  KC_MINS, ___x___, \
	__________NONE_3_________, _________TRANS_L4________, _________BASE_R4_________, __________NONE_3_________


#define LAYER_NUMBER \
	___x___, KC_9,    KC_5,    KC_1,    KC_3,    KC_7,    KC_6,    KC_2,    KC_0,    KC_4,    KC_8,    ___x___, \
	___x___, _____________GACS_MODS____________, KC_F11,  KC_BSPC, KC_SPC,  ___x___, KC_F12,  TR_REP,  ___x___, \
	___x___, KC_F9,   KC_F5,   KC_F1,   KC_F3,   KC_F7,   KC_F6,   KC_F2,   KC_F10,  KC_F4,   KC_F8,   ___x___, \
	__________NONE_3_________, _________TRANS_L4________, _________TRANS_R4________, __________NONE_3_________


#define LAYER_CONFIG \
	___x___, ___x___, ___x___, TR_DMR1, TR_DMP1, KC_PSCR, ___x___, ___x___, QK_BOOT, ___x___, _______, ___x___, \
	___x___, TR_RTOG, TR_RMOD, TR_DMR2, TR_DMP2, KC_SCRL, KC_CAPS, _____________SCAG_MODS____________, ___x___, \
	___x___, TR_RHUI, TR_RSAI, TR_RVAI, TR_RSPI, KC_PAUS, __________________NONE_5___________________, ___x___, \
	__________NONE_3_________, TR_GAME, CLMAKDH, QWERTY,  _________TRANS_R4________, __________NONE_3_________


#define LAYER_MOUSE \
	___x___, ___x___, ___x___, TR_MOUU, ___x___, TR_MWHU, TR_SDPI, TR_PDPI, ___x___, ___x___, ___x___, ___x___, \
	___x___, ___x___, TR_MOUL, TR_MOUD, TR_MOUR, TR_MWHD, ___x___, _____________SCAG_MODS____________, ___x___, \
	___x___, TR_SNIP, TR_BTN3, TR_BTN2, TR_BTN1, TR_DRGS, ___x___, TR_BTN1, TR_BTN2, TR_BTN3, ___x___, ___x___, \
	__________NONE_3_________, ___x___, ___x___, _______, TR_BTN5, TR_BTN4, ___x___, __________NONE_3_________


#define LAYER_GAMING \
	___x___, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    __________________NONE_5___________________, ___x___, \
	___x___, GAMENUM, KC_A,    KC_S,    KC_D,    KC_F,    __________________NONE_5___________________, ___x___, \
	___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    __________________NONE_5___________________, ___x___, \
	__________NONE_3_________, KC_LCTL, KC_SPC,  KC_LSFT, TR_ASTG, NAV,     ___x___, __________NONE_3_________


#define LAYER_GAMENUMBER \
	___x___, ___x___, KC_ESC,  KC_TILD, KC_G,    KC_T,    __________________NONE_5___________________, ___x___, \
	___x___, _______, KC_1,    KC_2,    KC_3,    KC_4,    __________________NONE_5___________________, ___x___, \
	___x___, ___x___, KC_5,    KC_6,    KC_7,    KC_8,    __________________NONE_5___________________, ___x___, \
	__________NONE_3_________, KC_LALT, ___x___, KC_ENT,  TR_ASTG, NAV,     ___x___, __________NONE_3_________



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

#define LAYOUT_cnano_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)