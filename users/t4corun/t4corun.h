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
    DEFAULT_LAYER = 0,
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
#define     DEFAULT_LAYER_2    DEFAULT_LAYER + 1
#define     DEFAULT_LAYER_3    DEFAULT_LAYER + 2
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

// home row mods QWERTY
#define     HRM_A   LGUI_T(KC_A)
#define     HRM_S   LALT_T(KC_S)
#define     HRM_D   LCTL_T(KC_D)
#define     HRM_F   LSFT_T(KC_F)
#define     HRM_J   RSFT_T(KC_J)
#define     HRM_K   RCTL_T(KC_K)
#define     HRM_L   RALT_T(KC_L)
#define     HRM_QT  RGUI_T(KC_QUOT)

// home row mods COLEMAK DH
#define     HRM_R   LALT_T(KC_R)
#define     HRM_SC  LCTL_T(KC_S)
#define     HRM_T   LSFT_T(KC_T)
#define     HRM_N   RSFT_T(KC_N)
#define     HRM_E   RCTL_T(KC_E)
#define     HRM_I   RALT_T(KC_I)
#define     HRM_O   RGUI_T(KC_O)

#define     HRML(k1, k2, k3, k4) LGUI_T(k1), LALT_T(k2), LCTL_T(k3), LSFT_T(k4)
#define     HRMR(k1, k2, k3, k4) RSFT_T(k1), RCTL_T(k2), RALT_T(k3), RGUI_T(k4)

// tap hoLd. These will be intercepted and overridden. The LT will be ignored
// Brackets: open and close brackets and put the cursor inside
#define     BK_LCBR LT(DEFAULT_LAYER, TH_LCBR)
#define     BK_LABK LT(DEFAULT_LAYER, TH_LABK)
#define     BK_LBRC LT(DEFAULT_LAYER, TH_LBRC)
#define     BK_LPRN LT(DEFAULT_LAYER, TH_LPRN)
#define     BK_DQUO LT(DEFAULT_LAYER, TH_DQUO)
#define     BK_SQUO LT(DEFAULT_LAYER, TH_SQUO)

// double tap
#define     DT_BSLS LT(DEFAULT_LAYER, TH_BSLS)
#define     DT_SLSH LT(DEFAULT_LAYER, TH_SLSH)
#define     DT_PIPE LT(DEFAULT_LAYER, TH_PIPE)

// Custom override without holding shift
#define     OR_COMM LT(DEFAULT_LAYER, TH_COMM)
#define     OR_DOT  LT(DEFAULT_LAYER, TH_DOT)

// auto shift
#define     AS_MINS LT(DEFAULT_LAYER, TH_MINS)
#define     AS_QUOT LT(DEFAULT_LAYER, TH_QUOT)

// pointer specific control
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_non_tree_keyball39)
#   define  MS_SNIP SNIPING  //these mouse codes are defined in charybdis.h and keyball.h
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
#define     _GACS_MODS________________________          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT
#define     _SCAG_MODS________________________          KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI
#define     _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define     _BASE_L4_________________                   MS_BTN1, NUM,     KC_LSFT
#define     _BASE_R4________                            KC_SPC,  NAV
#define     _LYR_LTRANS______________                   ___x___, _______, ___x___
#define     _LYR_RTRANS_____                            ___x___, _______

//___x___, ___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                                \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    OR_COMM, OR_DOT,  AS_MINS, \
                      _BASE_L4_________________,      _BASE_R4________,                             \
                                        SCR_TOP,       KC_MUTE


#define LAYER_COLEMAK_DH                                                                            \
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    AS_QUOT, \
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    OR_COMM, OR_DOT,  AS_MINS, \
                      _BASE_L4_________________,      _BASE_R4________,                             \
                                        SCR_TOP,       KC_MUTE


#define LAYER_GAME                                                                                  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_LALT, KC_1,    KC_2,    KC_3,    TOG_CFG, \
                      KC_ENT,  KC_SPC,  KC_LSFT,       _BASE_R4________,                            \
                                        SCR_TOP,       KC_MUTE


#define LAYER_NAVIGATION                                                                            \
    ___x___, KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_INS,  KC_APP,  MS_BTN2, ___x___, ___x___, \
    ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_BSPC, _SCAG_MODS________________________, \
    ___x___, ___x___, MS_PDPI, MS_SDPI, MS_SNIP,       KC_DEL,  MS_BTN1, KC_VOLD, KC_VOLU, KC_MUTE, \
                      KC_TAB,  _______, KC_ENT,        _LYR_RTRANS_____,                            \
                                        SCR_TOP,       ___x___


#define LAYER_NUMBER                                                                                \
    KC_ESC,  MS_BTN5, MS_BTN3, MS_BTN4, ___x___,       KC_COMM, KC_7,    KC_8,    KC_9,    KC_F5,   \
    _GACS_MODS________________________, MS_BTN2,       KC_DOT,  KC_4,    KC_5,    KC_6,    KC_F2,   \
    _UCCPR_L___________________________________,       KC_MINS, KC_1,    KC_2,    KC_3,    KC_F3,   \
                      FUNC,    _______, ___x___,       KC_0,    _______,                            \
                                        ___x___,       ___x___


#define LAYER_SYMBOL                                                                                \
    KC_CIRC, KC_AMPR, KC_AT,   KC_DLR,  KC_GRV,        KC_TILD, KC_HASH, KC_ASTR, KC_PLUS, BK_DQUO, \
    KC_PERC, BK_LCBR, KC_RCBR, DT_PIPE, KC_SCLN,       KC_COLN, KC_EQL,  BK_LBRC, KC_RBRC, BK_SQUO, \
    ___x___, BK_LABK, KC_RABK, DT_BSLS, KC_EXLM,       KC_QUES, DT_SLSH, BK_LPRN, KC_RPRN, ___x___, \
                      _LYR_LTRANS______________,       _LYR_RTRANS_____,                            \
                                        ___x___,       ___x___


#define LAYER_FUNCTION                                                                              \
    QK_BOOT, GU_TOGG, CG_TOGG, KC_BRK,  KC_PSCR,       TOG_CFG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
    _GACS_MODS________________________, DM_PLY1,       FWD_CFG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
    ___x___, KC_NUM,  KC_CAPS, KC_SCRL, DM_REC1,       REV_CFG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
                      _______, ___x___, ___x___,       DM_PLY2, DM_REC2,                            \
                                        TOG_CFG,       TOG_CFG


#define HRM(k) HRM_LAYOUT(k)
#define HRM_LAYOUT(                                                  \
         k00, k01, k02, k03,  k04,    k05, k06, k07, k08, k09,       \
         k10, k11, k12, k13,  k14,    k15, k16, k17, k18, k19,       \
         k20, k21, k22, k23,  k24,    k25, k26, k27, k28, k29,       \
                   k32, k33,  k34,    k35, k36,                      \
                              e01,    e02                            \
)                                                                    \
         k00, k01, k02, k03,  k04,    k05, k06, k07, k08, k09,       \
    HRML(k10, k11, k12, k13), k14,    k15, HRMR(k16, k17, k18, k19), \
         k20, k21, k22, k23,  k24,    k25, k26, k27, k28, k29,       \
              k32, k33, k34,  k35,    k36,                           \
                              e01,    e02
