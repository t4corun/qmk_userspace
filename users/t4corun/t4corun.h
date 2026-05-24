#pragma once

#include QMK_KEYBOARD_H

#include "bindings.h"
#include "features/taphold.h"

#if defined(ENCODER_ENABLE)
#   include "features/encoder.h"
#endif // ENCODER_ENABLE

#if defined(PLOOPYNANO_ENABLE)
#   include "features/ploopynano.h"
#endif // PLOOPYNANO_ENABLE

layer_state_t layer_state_set_keymap(layer_state_t state);
void          set_default_layer(bool forward);


//___x___, ___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                                \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, \
                      _BASE_L4_________________,      _BASE_R4_________________,                    \
                                        SCR_TOP,       KC_MUTE


#define LAYER_GRAPHITE                                                                              \
    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,          KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    \
    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,          KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    \
    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,          KC_K,    KC_P,    KC_DOT,  KC_MINS, KC_COMM, \
                      _BASE_L4_________________,      _BASE_R4_________________,                    \
                                        SCR_TOP,       KC_MUTE


#define LAYER_NAVIGATION                                                                            \
    KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_INS,  KC_APP,  ___x___, ___x___, ___x___, \
    ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_BSPC, _MODS_SCAG________________________, \
    _SHORTCUTS_UCCPR___________________________,       KC_DEL,  ___x___, KC_VOLD, KC_VOLU, ___x___, \
                      KC_TAB,  _______, ___x___,       _LAYER_TRANS_____________,                   \
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
                      _LAYER_TRANS_____________,       _LAYER_TRANS_____________,                   \
                                        ___x___,       ___x___

#define LAYER_FUNCTION                                                                              \
    ___x___, GU_TOGG, CG_TOGG, KC_BRK,  KC_PSCR,       TOG_CFG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
    _MODS_GACS________________________, DM_PLY1,       FWD_CFG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
    QK_BOOT, KC_NUM,  KC_CAPS, KC_SCRL, DM_REC1,       REV_CFG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
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
                   k32, k33,  k34,    k35, k36, k37,                 \
                              e01,    e02
