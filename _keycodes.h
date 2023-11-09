#pragma once

#include "quantum/quantum_keycodes.h"

enum keycodes {
  QWERTY = SAFE_RANGE,
  CLMAKDH,
  GAMING,

  //These are only here to make the case statements unique in taphold.c
  TH_LCBR,
  TH_LABK,
  TH_LBRC,
  TH_SQUO,
  TH_DQUO,
  TH_LPRN,
  TH_COMM,
  TH_DOT,
  TH_PERC,
  TH_EQL,
  TH_MINS,
  TH_GRV,
  TH_SCLN,
  TH_QUOT
};

#define ___x___ KC_NO

// momentary layer
#define NAV        LT(_NAVIGATION, KC_0)
#define NUM        MO(_NUMBER)
#define CONFIG     MO(_CONFIG)
#define FUNC       MO(_FUNCTION)

// Windows Shortcuts
#define SC_COPY    LCTL(KC_C)
#define SC_CUT     LCTL(KC_X)
#define SC_UNDO    LCTL(KC_Z)
#define SC_PAST    LCTL(KC_V)
#define SC_REDO    LCTL(KC_Y)
#define SC_SNIP    LGUI(LSFT(KC_S))
#define SC_FILE    LGUI(KC_E)

// Visual Studio Code

#define VS_FOLD    LCTL(LSFT(KC_7))
#define VS_UFLD    LCTL(LSFT(KC_9))

/*
- Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
- If the feature is disabled then the key is just the normal key
- We will only define things that are used across different layers. Entire layers are turned off in the keymap
*/


// one shot mods
#define TR_LSFT OSM(MOD_LSFT)
#define TR_LCTL OSM(MOD_LCTL)
#define TR_LALT OSM(MOD_LALT)
#define TR_LGUI OSM(MOD_LGUI)



//tap hoLd
#define TR_LCBR  LT(_DEFAULT_LAYER_1, TH_LCBR) // bracket behvavior
#define TR_LABK  LT(_DEFAULT_LAYER_1, TH_LABK)
#define TR_LBRC  LT(_DEFAULT_LAYER_1, TH_LBRC) 
#define TR_SQUO  LT(_DEFAULT_LAYER_1, TH_SQUO)
#define TR_DQUO  LT(_DEFAULT_LAYER_1, TH_DQUO)

#define TR_LPRN  LT(_DEFAULT_LAYER_1, TH_LPRN) // custom behavior0' 
#define TR_COMM  LT(_DEFAULT_LAYER_1, TH_COMM)
#define TR_DOT   LT(_DEFAULT_LAYER_1, TH_DOT)
#define TR_PERC  LT(_DEFAULT_LAYER_1, TH_PERC)

#define TR_EQL   LT(_DEFAULT_LAYER_1, TH_EQL)  // auto shift
#define TR_MINS  LT(_DEFAULT_LAYER_1, TH_MINS)
#define TR_GRV   LT(_DEFAULT_LAYER_1, TH_GRV)
#define TR_SCLN  LT(_DEFAULT_LAYER_1, TH_SCLN)
#define TR_QUOT  LT(_DEFAULT_LAYER_1, TH_QUOT)



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

//Layer tap key is dependent on if mouse pointer or mouse keys
//c for pointer, z for keys
#if defined(MOUSELAYER_ENABLE) && !defined(MOUSEKEY_ENABLE)
#   define TR_MOUC LT(_MOUSE, KC_C)
#   define TR_MOUZ KC_Z
#elif defined(MOUSELAYER_ENABLE) && defined(MOUSEKEY_ENABLE)
#   define TR_MOUC KC_C
#   define TR_MOUZ LT(_MOUSE, KC_Z)
#else
#   define TR_MOUZ KC_Z
#   define TR_MOUC KC_C
#endif //defined(MOUSELAYER_ENABLE) && !defined(MOUSEKEY_ENABLE)


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

