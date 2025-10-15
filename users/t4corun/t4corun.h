#pragma once

#include QMK_KEYBOARD_H

#include "features/taphold.h"

#if defined(ENCODER_ENABLE)
#   include "features/encoder.h"
#endif // ENCODER_ENABLE

#if defined(PLOOPYNANO_ENABLE)
#   include "features/ploopynano.h"
#endif // PLOOPYNANO_ENABLE

layer_state_t layer_state_set_keymap(layer_state_t state);
void          set_default_layer(bool forward);


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

    TH_COMM,
    TH_DOT,

    TH_MINS,
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

#define     MOD_MASK_RESET         MOD_BIT(KC_LSFT)
#define     MOD_MAST_EECONFIG_INIT MOD_BIT(KC_LCTL)

#if defined(RGB_MATRIX_ENABLE)
#   define  MOD_MASK_RGB_TOGGLE    (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
#   define  MOD_MASK_RGB_MODE      MOD_MASK_RGB_TOGGLE
#   define  MOD_MASK_RGB_HUE       MOD_BIT(KC_LSFT)
#   define  MOD_MASK_RGB_SAT       MOD_BIT(KC_LCTL)
#   define  MOD_MASK_RGB_VAL       MOD_BIT(KC_LALT)
#   define  MOD_MASK_RGB_SPD       MOD_BIT(KC_LGUI)
#endif

#if defined(AUDIO_ENABLE)
#   define  MOD_MASK_AUDIO_TOGGLE  (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI))
#   define  MOD_MASK_CLICKY_TOGGLE (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))
#   define  MOD_MASK_CLICKY_ADJUST MOD_MASK_CLICKY_TOGGLE
#endif // AUDIO_ENABLE

#if defined(HAPTIC_ENABLE)
#   define  MOD_MASK_HAPTIC_TOGGLE     (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))
#   define  MOD_MASK_HAPTIC_MODE       MOD_MASK_HAPTIC_TOGGLE
#   define  MOD_MASK_HAPTIC_RESET      (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI))
#   define  MOD_MASK_FEEDBACK_TOGGLE   (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))
#   define  MOD_MASK_CONTINUOUS_TOGGLE (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))
#endif // HAPTIC_ENABLE

#if defined(PLOOPYNANO_ENABLE)
#   define  MOD_MASK_PLOOPY_RESET  MOD_BIT(KC_LALT)
#endif // PLOOPYNANO_ENABLE

// start at the second layer
#define     DEFAULT_LAYER_2    FIRST_DEFAULT_LAYER + 1
#define     DEFAULT_LAYER_3    FIRST_DEFAULT_LAYER + 2
#define     NUM_DEFAULT_LAYERS 3

#define     ___x___ KC_NO

// layer changes
#define     NUM     MO(_NUMBER)
#define     NAV     MO(_NAVIGATION)
#define     FUNC    MO(_FUNCTION)

// Encoders
#define     ZOOMRST LCTL(KC_0)
#define     SCR_TOP LCTL(KC_HOME)

// Windows Shortcuts
#define     SC_COPY LCTL(KC_C)
#define     SC_CUT  LCTL(KC_X)
#define     SC_UNDO LCTL(KC_Z)
#define     SC_PAST LCTL(KC_V)
#define     SC_REDO LCTL(KC_Y)
#define     SC_SNIP LSG(KC_S)

/*
 * If the feature is disabled then the key is just the normal key
 * Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
 * We will only define things that are used across different layers. Entire layers are turned off in the keymap
 */

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

// Custom override without holding shift
#define     OR_COMM LT(FIRST_DEFAULT_LAYER, TH_COMM)
#define     OR_DOT  LT(FIRST_DEFAULT_LAYER, TH_DOT)

// auto shift
#define     AS_MINS LT(FIRST_DEFAULT_LAYER, TH_MINS)
#define     AS_QUOT LT(FIRST_DEFAULT_LAYER, TH_QUOT)

// pointer specific control
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_non_tree_keyball39)
//these mouse codes are defined in charybdis.h and keyball.h
#   define  MS_SNIP SNIPING
#   define  MS_STOG SNP_TOG
#   define  MS_DRGS DRGSCRL
#   define  MS_SDPI S_D_MOD  //sniping dpi
#   define  MS_PDPI DPI_MOD  //pointer dpi
#else
#   define  MS_SNIP ___x___
#   define  MS_STOG ___x___
#   define  MS_DRGS KC_SCRL  //use host status for ploopy nano drag scroll
#   define  MS_SDPI ___x___
#   define  MS_PDPI KC_NUM   //use host status for ploopy nano dpi switch
#endif // KEYBOARD_bastardkb_charybdis_3x5 || KEYBOARD_keyball39

#define     _NONE_3__________________                   ___x___, ___x___, ___x___
#define     _NONE_5____________________________________ ___x___, ___x___, ___x___, ___x___, ___x___
#define     _GACS_MODS________________________          OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT
#define     _SCAG_MODS________________________          OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI
#define     _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define     _BASE_L4_________________                   MS_BTN1, NUM,     OSM_SFT
#define     _BASE_R4________                            KC_SPC,  NAV
#define     _LYR_LTRANS______________                   ___x___, _______, ___x___
#define     _LYR_RTRANS_____                            ___x___, _______

//___x___, ___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                                     \
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    AS_QUOT, \
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    OR_COMM, OR_DOT,  AS_MINS, \
_NONE_3__________________, _BASE_L4_________________,      _BASE_R4________,                    KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_COLEMAK_DH                                                                                 \
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    AS_QUOT, \
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    OR_COMM, OR_DOT,  AS_MINS, \
_NONE_3__________________, _BASE_L4_________________,       _BASE_R4________,                   KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_GAME                                                                                       \
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
         KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_LALT, KC_1,    KC_2,    KC_3,    TOG_CFG, \
FUNC,    MS_BTN2, MS_BTN1, KC_ENT,  KC_SPC,  KC_LSFT,       _BASE_R4________,                   KC_MUTE, \
                                             SCR_TOP,       KC_MUTE


#define LAYER_NAVIGATION                                                                                 \
         ___x___, KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_INS,  KC_APP,  MS_BTN2, MS_PDPI, MS_SDPI, \
         ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_BSPC, _SCAG_MODS________________________, \
         _UCCPR_L___________________________________,       KC_DEL,  MS_BTN1, KC_VOLD, KC_VOLU, KC_MUTE, \
_NONE_3__________________, KC_TAB,  _______, KC_ENT,        _LYR_RTRANS_____,                   ___x___, \
                                             SCR_TOP,       ___x___


#define LAYER_NUMBER                                                                                     \
         KC_ESC,  MS_BTN5, MS_BTN3, MS_BTN4, SC_SNIP,       KC_COMM, KC_7,    KC_8,    KC_9,    KC_F5,   \
         _GACS_MODS________________________, MS_BTN2,       KC_DOT,  KC_4,    KC_5,    KC_6,    KC_F2,   \
         _UCCPR_L___________________________________,       KC_MINS, KC_1,    KC_2,    KC_3,    KC_F3,   \
_NONE_3__________________, FUNC,    _______, ___x___,       KC_0,    _______,                   ___x___, \
                                             ___x___,       ___x___


#define LAYER_SYMBOL                                                                                     \
         KC_CIRC, KC_AMPR, KC_AT,   KC_DLR,  KC_GRV,        KC_TILD, KC_HASH, KC_ASTR, KC_PLUS, BK_DQUO, \
         KC_PERC, BK_LCBR, KC_RCBR, DT_PIPE, KC_SCLN,       KC_COLN, KC_EQL,  BK_LBRC, KC_RBRC, BK_SQUO, \
         FUNC,    BK_LABK, KC_RABK, DT_BSLS, KC_EXLM,       KC_QUES, DT_SLSH, BK_LPRN, KC_RPRN, ___x___, \
_NONE_3__________________, _LYR_LTRANS______________,       _LYR_RTRANS_____,                   ___x___, \
                                             ___x___,       ___x___


#define LAYER_FUNCTION                                                                                   \
         QK_BOOT, GU_TOGG, CG_TOGG, KC_BRK,  KC_PSCR,       TOG_CFG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
         _GACS_MODS________________________, DM_PLY1,       FWD_CFG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
         ___x___, KC_NUM,  KC_CAPS, KC_SCRL, DM_REC1,       REV_CFG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
_NONE_3__________________, _______, ___x___, ___x___,       DM_PLY2, DM_REC2,                   QK_BOOT, \
                                             TOG_CFG,       TOG_CFG
