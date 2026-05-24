#pragma once

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

#define     _BASE_L4_________________                   MS_BTN1, NUM,     OS_LSFT
#define     _BASE_R4_________________                   KC_SPC,  NAV,     KC_BSPC
#define     _LAYER_TRANS_____________                   ___x___, _______, ___x___