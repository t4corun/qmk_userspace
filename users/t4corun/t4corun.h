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
    _GRAPHITE,
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

    TH_COMM,
    TH_DOT,

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
#define     NUM_DEFAULT_LAYERS 2

#define     ___x___ KC_NO

// layer changes
#define     NUM     MO(_NUMBER)
#define     NAV     MO(_NAVIGATION)
#define     FUNC    MO(_FUNCTION)

// Encoders
#define     ZOOMRST LCTL(KC_0)
#define     SCR_TOP LCTL(KC_HOME)

// Windows Shortcuts
#define     SC_UNDO LCTL(KC_Z)
#define     SC_CUT  LCTL(KC_X)
#define     SC_COPY LCTL(KC_C)
#define     SC_PAST LCTL(KC_V)
#define     SC_REDO LCTL(KC_Y)
#define     W_SNIP  LSG(KC_S)

// home row mods QWERTY
#define     HRM_A   LGUI_T(KC_A)
#define     HRM_S   LALT_T(KC_S)
#define     HRM_D   LCTL_T(KC_D)
#define     HRM_F   LSFT_T(KC_F)
#define     HRM_J   RSFT_T(KC_J)
#define     HRM_K   RCTL_T(KC_K)
#define     HRM_L   RALT_T(KC_L)
#define     HRM_QT  RGUI_T(KC_QUOT)

// home row mods GRAPHITE
#define     HRM_N   LGUI_T(KC_N)
#define     HRM_R   LALT_T(KC_R)
#define     HRM_T   LCTL_T(KC_T)
#define     HRM_SG  LSFT_T(KC_S)
#define     HRM_H   RSFT_T(KC_H)
#define     HRM_AG  RCTL_T(KC_A)
#define     HRM_E   RALT_T(KC_E)
#define     HRM_I   RGUI_T(KC_I)

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

// Custom override without holding shift
#define     OR_COMM LT(DEFAULT_LAYER, TH_COMM)
#define     OR_DOT  LT(DEFAULT_LAYER, TH_DOT)

// pointer specific control
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_non_tree_keyball39)
#   define  MS_SNIP SNIPING  //these mouse codes are defined in charybdis.h and keyball.h
#   define  MS_STOG SNP_TOG
#   define  MS_DRGS DRGSCRL
#   define  MS_SDPI S_D_MOD  //sniping dlpi
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
#define     _MODS_GACS________________________          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT
#define     _MODS_SCAG________________________          KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI
#define     _SHORTCUTS_UCCPR___________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define     _BASE_L4_________________                   MS_BTN1, NUM,     KC_LSFT
#define     _BASE_R4_________________                   KC_SPC,  NAV,     KC_BSPC
#define     _LYR_TRANS_______________                   ___x___, _______, ___x___

//___x___, ___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                                \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    OR_COMM, OR_DOT,  KC_MINS, \
                      _BASE_L4_________________,      _BASE_R4_________________,                    \
                                        SCR_TOP,       KC_MUTE


#define LAYER_GRAPHITE                                                                              \
    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,          KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    \
    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,          KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    \
    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,          KC_K,    KC_P,    OR_DOT,  KC_MINS, OR_COMM, \
                      _BASE_L4_________________,      _BASE_R4_________________,                    \
                                        SCR_TOP,       KC_MUTE


#define LAYER_NAVIGATION                                                                            \
    KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_INS,  KC_APP,  ___x___, ___x___, ___x___, \
    ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_BSPC, _MODS_SCAG________________________, \
    _SHORTCUTS_UCCPR___________________________,       KC_DEL,  ___x___, KC_VOLD, KC_VOLU, ___x___, \
                      KC_TAB,  _______, ___x___,       _LYR_TRANS_______________,                   \
                                        SCR_TOP,       ___x___


#define LAYER_NUMBER                                                                                \
    KC_ESC,  MS_BTN5, MS_BTN3, MS_BTN4, W_SNIP,        KC_COMM, KC_7,    KC_8,    KC_9,    KC_SLSH, \
    _MODS_GACS________________________, MS_BTN2,       KC_DOT,  KC_4,    KC_5,    KC_6,    KC_ASTR, \
    _SHORTCUTS_UCCPR___________________________,       KC_MINS, KC_1,    KC_2,    KC_3,    KC_PLUS, \
                      FUNC,    _______, KC_SPC,        KC_0,    _______, KC_EQL,                    \
                                        ___x___,       ___x___


#define LAYER_SYMBOL                                                                                \
    KC_CIRC, KC_AT,   BK_LABK, KC_RABK, KC_GRV,        KC_PIPE, BK_LCBR, KC_RCBR, KC_DLR,  BK_DQUO, \
    ___x___, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,       KC_HASH, BK_LPRN, KC_RPRN, KC_SCLN, BK_SQUO, \
    KC_TILD, KC_PLUS, BK_LBRC, KC_RBRC, KC_PERC,       KC_BSLS, KC_COLN, KC_QUES, KC_EXLM, KC_MINS, \
                      _LYR_TRANS_______________,       _LYR_TRANS_______________,                   \
                                        ___x___,       ___x___

#define LAYER_FUNCTION                                                                              \
    QK_BOOT, GU_TOGG, CG_TOGG, KC_BRK,  KC_PSCR,       TOG_CFG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
    _MODS_GACS________________________, DM_PLY1,       FWD_CFG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
    ___x___, KC_NUM,  KC_CAPS, KC_SCRL, DM_REC1,       REV_CFG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
                      _______, ___x___, ___x___,       DM_PLY2, DM_REC2, ___x___,                   \
                                        TOG_CFG,       TOG_CFG


#define HRM(k) HRM_LAYOUT(k)
#define HRM_LAYOUT(                                                  \
         k00, k01, k02, k03,  k04,    k05, k06, k07, k08, k09,       \
         k10, k11, k12, k13,  k14,    k15, k16, k17, k18, k19,       \
         k20, k21, k22, k23,  k24,    k25, k26, k27, k28, k29,       \
                   k32, k33,  k34,    k35, k36, k37,                 \
                              e01,    e02                            \
)                                                                    \
         k00, k01, k02, k03,  k04,    k05, k06, k07, k08, k09,       \
    HRML(k10, k11, k12, k13), k14,    k15, HRMR(k16, k17, k18, k19), \
         k20, k21, k22, k23,  k24,    k25, k26, k27, k28, k29,       \
              k32, k33, k34,  k35,    k36, k37,                      \
                              e01,    e02
