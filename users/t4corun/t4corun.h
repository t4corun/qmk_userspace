#pragma once

#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/taphold.h"

#if defined(ENCODER_ENABLE)
#   include "features/encoder.h"
#endif // ENCODER_ENABLE

#if defined(PLOOPYNANO_ENABLE)
#   include "features/ploopynano.h"
#endif // PLOOPYNANO_ENABLE

layer_state_t layer_state_set_keymap(layer_state_t state);
void          set_default_layer(bool forward);
void          toggle_features(uint16_t keycode, uint8_t current_mods);
#if defined(RGB_MATRIX_ENABLE)
void          handle_rgbmatrix(uint16_t keycode, uint8_t current_mods);
#endif // RGB_MATRIX_ENABLE
#if defined(AUDIO_ENABLE)
void          handle_audio(uint16_t keycode);
#endif //AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
void          handle_haptic(uint16_t keycode);
#endif // HAPTIC_ENABLE


// put the default base layers first
enum layers {
    _QWERTY = 0,
    FIRST_DEFAULT_LAYER = 0,
    _COLEMAK_DH,
    _GAME,
    _NAVIGATION,
    _NUMBER,
    _SYMBOL,
    _FUNCTION
};

enum keycodes {
    //These are only here to make the taphold/defines unique
    TH_LCBR = QK_USER,
    TH_LABK,
    TH_LBRC,
    TH_LPRN,
    TH_DQUO,
    TH_SQUO,

    TH_BSLS,
    TH_SLSH,
    TH_PIPE,
    TH_EQL,
    TH_PLUS,

    TH_COMM,
    TH_DOT,
    TH_PERC,

    TH_MINS,
    TH_GRV,
    TH_SCLN,
    TH_QUOT,

#if defined(ENCODER_ENABLE)
    FWD_TAB,  // turn encoder for tab and shift tab
    REV_TAB,  // hold alt or ctrl while turning for window / tab switching

    ZOOMIN,   // turn encoder for mouse wheel zoom
    ZOOMOUT,
#endif // ENCODER_ENABLE

    FWD_CFG,  // turn encoder while holding mod combinations to adjust features
    REV_CFG,  // e.g. RGB settings, haptic frequency, click frequency, base layer

    TOG_CFG   // press key while holding mod combinations to toggle features or enter bootloader
};

// defining aliases for config key overloading
#define     MOD_MASK_RGB_MODE  (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
#define     MOD_MASK_RGB_HUE   MOD_BIT(KC_LSFT)
#define     MOD_MASK_RGB_SAT   MOD_BIT(KC_LCTL)
#define     MOD_MASK_RGB_VAL   MOD_BIT(KC_LALT)
#define     MOD_MASK_RGB_SPD   MOD_BIT(KC_LGUI)

// start at the second layer
#define     DEFAULT_LAYER_2    FIRST_DEFAULT_LAYER + 1
#define     DEFAULT_LAYER_3    FIRST_DEFAULT_LAYER + 2
#define     NUM_DEFAULT_LAYERS 3

#define     ___x___ KC_NO

// layer changes
#define     NAV     MO(_NAVIGATION)
#define     NUM     MO(_NUMBER)
#define     FUNC    MO(_FUNCTION)

// Windows Shortcuts
#define     SC_COPY LCTL(KC_C)
#define     SC_CUT  LCTL(KC_X)
#define     SC_UNDO LCTL(KC_Z)
#define     SC_PAST LCTL(KC_V)
#define     SC_REDO LCTL(KC_Y)
#define     SC_WIN  LGUI(KC_TAB)

// Encoders
#define     ZOOMRST LCTL(KC_0)
#define     SCR_TOP LCTL(KC_HOME)

/*
 * If the feature is disabled then the key is just the normal key
 * Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
 * We will only define things that are used across different layers. Entire layers are turned off in the keymap
 */

// home row mods QWERTY
#define     HOME_A  MT(MOD_LGUI, KC_A)
#define     HOME_S  MT(MOD_LALT, KC_S)
#define     HOME_D  MT(MOD_LCTL, KC_D)
#define     HOME_F  MT(MOD_LSFT, KC_F)
#define     HOME_J  MT(MOD_RSFT, KC_J)
#define     HOME_K  MT(MOD_RCTL, KC_K)
#define     HOME_L  MT(MOD_RALT, KC_L)
#define     HOME_QT MT(MOD_RGUI, KC_QUOT)

// home row mods COLEMAK DH
#define     HOME_R  MT(MOD_LALT, KC_R)
#define     HOME_SC MT(MOD_LCTL, KC_S)
#define     HOME_T  MT(MOD_LSFT, KC_T)
#define     HOME_N  MT(MOD_RSFT, KC_N)
#define     HOME_E  MT(MOD_RCTL, KC_E)
#define     HOME_I  MT(MOD_RALT, KC_I)
#define     HOME_O  MT(MOD_RGUI, KC_O)

// one shot mods
#define     OSM_SFT OSM(MOD_LSFT)
#define     OSM_CTL OSM(MOD_LCTL)
#define     OSM_ALT OSM(MOD_LALT)
#define     OSM_GUI OSM(MOD_LGUI)

// tap hoLd. These will be intercepted and overridden. The LT will be ignored
// Brackets: open and close brackets and put the cursor inside
#define     BK_LCBR LT(FIRST_DEFAULT_LAYER, TH_LCBR)
#define     BK_LABK LT(FIRST_DEFAULT_LAYER, TH_LABK)
#define     BK_LBRC LT(FIRST_DEFAULT_LAYER, TH_LBRC)
#define     BK_LPRN LT(FIRST_DEFAULT_LAYER, TH_LPRN)
#define     BK_DQUO LT(FIRST_DEFAULT_LAYER, TH_DQUO)
#define     BK_SQUO LT(FIRST_DEFAULT_LAYER, TH_SQUO)

// double tap
#define     DT_BSLS LT(FIRST_DEFAULT_LAYER, TH_BSLS)
#define     DT_SLSH LT(FIRST_DEFAULT_LAYER, TH_SLSH)
#define     DT_PIPE LT(FIRST_DEFAULT_LAYER, TH_PIPE)
#define     DT_EQL  LT(FIRST_DEFAULT_LAYER, TH_EQL)
#define     DT_PLUS LT(FIRST_DEFAULT_LAYER, TH_PLUS)

// Custom override without holding shift
#define     OR_COMM LT(FIRST_DEFAULT_LAYER, TH_COMM)
#define     OR_DOT  LT(FIRST_DEFAULT_LAYER, TH_DOT)
#define     OR_PERC LT(FIRST_DEFAULT_LAYER, TH_PERC)

// auto shift
#define     AS_MINS LT(FIRST_DEFAULT_LAYER, TH_MINS)
#define     AS_GRV  LT(FIRST_DEFAULT_LAYER, TH_GRV)
#define     AS_SCLN LT(FIRST_DEFAULT_LAYER, TH_SCLN)
#define     AS_QUOT LT(FIRST_DEFAULT_LAYER, TH_QUOT)

// pointer specific control
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_non_tree_keyball39)
//these mouse codes are defined in charybdis.h and keyball.h
#   define  MS_SNIP SNIPING
#   define  MS_DRGS DRGSCRL
#   define  MS_SDPI S_D_MOD  //sniping dpi
#   define  MS_PDPI DPI_MOD  //pointer dpi
#else
#   define  MS_SNIP ___x___
#   define  MS_DRGS KC_SCRL  //use host status for ploopy nano drag scroll
#   define  MS_SDPI ___x___
#   define  MS_PDPI KC_NUM   //use host status for ploopy nano dpi switch
#endif // KEYBOARD_bastardkb_charybdis_3x5 || KEYBOARD_keyball39

#define     _NONE_3__________________                   ___x___, ___x___, ___x___
#define     _NONE_5____________________________________ ___x___, ___x___, ___x___, ___x___, ___x___
#define     _GACS_MODS________________________          OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT
#define     _SCAG_MODS________________________          OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI
#define     _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define     _BASE_L4_________________                   KC_BTN1, NUM,     OSM_SFT
#define     _BASE_R4________                            KC_SPC,  NAV
#define     _BASE_KEYBALL____________                   FUNC,    MS_SNIP, KC_BTN2
#define     _LYR_LTRANS______________                   ___x___, _______, ___x___
#define     _LYR_RTRANS_____                            ___x___, _______

//___x___, ___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                                     \
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
         HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,          KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_QT, \
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    OR_COMM, OR_DOT,  AS_MINS, \
_BASE_KEYBALL____________, _BASE_L4_________________,      _BASE_R4________,                    KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_COLEMAK_DH                                                                                 \
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    AS_QUOT, \
         HOME_A,  HOME_R,  HOME_SC, HOME_T,  KC_G,          KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  \
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    OR_COMM, OR_DOT,  AS_MINS, \
_BASE_KEYBALL____________, _BASE_L4_________________,       _BASE_R4________,                   KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_GAME                                                                                       \
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
         KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_LALT, KC_1,    KC_2,    KC_3,    TOG_CFG, \
FUNC,    KC_BTN2, KC_BTN1, KC_ENT,  KC_SPC,  KC_LSFT,       _BASE_R4________,                   KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_NAVIGATION                                                                                 \
         KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,       ___x___, KC_APP,  KC_MPRV, KC_MNXT, KC_MPLY, \
         ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_BSPC, _SCAG_MODS________________________, \
         _UCCPR_L___________________________________,       KC_DEL,  KC_TAB,  KC_VOLD, KC_VOLU, KC_MUTE, \
_NONE_3__________________, KC_TAB,  NUM,     KC_ENT,        _LYR_RTRANS_____,                   ___x___, \
                                             SCR_TOP,       ___x___


#define LAYER_NUMBER                                                                                     \
         KC_ESC,  MS_DRGS, KC_BTN3, KC_BTN4, KC_BTN5,       ___x___, KC_7,    KC_8,    KC_9,    KC_COMM, \
         _GACS_MODS________________________, KC_BTN1,       KC_BSPC, KC_4,    KC_5,    KC_6,    KC_DOT,  \
         MS_PDPI, MS_SDPI, ___x___, KC_BTN2, ___x___,       KC_DEL,  KC_1,    KC_2,    KC_3,    KC_MINS, \
_NONE_3__________________, _LYR_LTRANS______________,       KC_0,    NAV,                       ___x___, \
                                             ___x___,       SC_WIN


#define LAYER_SYMBOL                                                                                     \
         ___x___, ___x___, KC_AT,   KC_DLR,  AS_GRV,        DT_EQL,  KC_HASH, KC_ASTR, DT_PLUS, BK_DQUO, \
         KC_AMPR, BK_LCBR, KC_RCBR, DT_PIPE, AS_SCLN,       KC_BSPC, KC_QUES, BK_LBRC, KC_RBRC, BK_SQUO, \
         OR_PERC, BK_LABK, KC_RABK, DT_BSLS, KC_EXLM,       KC_DEL,  DT_SLSH, BK_LPRN, KC_RPRN, AS_MINS, \
_NONE_3__________________, _LYR_LTRANS______________,       _LYR_RTRANS_____,                   ___x___, \
                                             ___x___,       ___x___


#define LAYER_FUNCTION                                                                                   \
         QK_BOOT, ___x___, GU_TOGG, CG_TOGG, DM_REC1,       KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
         _GACS_MODS________________________, DM_PLY1,       KC_BRK,  KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
         ___x___, KC_NUM,  KC_CAPS, KC_SCRL, KC_INS,        TOG_CFG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
_______, ___x___, ___x___, _NONE_3__________________,       REV_CFG, FWD_CFG,                   QK_BOOT, \
                                             TOG_CFG,       TOG_CFG
