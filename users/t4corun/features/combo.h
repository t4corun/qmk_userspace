#pragma once

#include "t4corun.h"

enum combos {
    // Left side combos
    SD_ESC,
    DF_TAB,
    
    // right side combos
    JK_ENTER,
    KL_BACKSPACE,
    COMMDOT_DEL,

    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

//const uint16_t PROGMEM lyr_fun_combo[]     = { BSP_NUM, OSM_SFT, COMBO_END };
const uint16_t PROGMEM sd_esc_combo[]      = { HOME_S,  HOME_D,  COMBO_END };
const uint16_t PROGMEM df_tab_combo[]      = { HOME_D,  HOME_F,  COMBO_END };
const uint16_t PROGMEM jk_ent_combo[]      = { HOME_J,  HOME_K,  COMBO_END };
const uint16_t PROGMEM kl_bspc_combo[]     = { HOME_K,  HOME_L,  COMBO_END };
const uint16_t PROGMEM commdot_del_combo[] = { OR_COMM, OR_DOT,  COMBO_END };


combo_t key_combos[COMBO_LENGTH] = {
    [SD_ESC]       = COMBO(sd_esc_combo,      KC_ESC),
    [DF_TAB]       = COMBO(df_tab_combo,      KC_TAB),
    [JK_ENTER]     = COMBO(jk_ent_combo,      KC_ENT),
    [KL_BACKSPACE] = COMBO(kl_bspc_combo,     KC_ESC),
    [COMMDOT_DEL]  = COMBO(commdot_del_combo, KC_DEL)
};
