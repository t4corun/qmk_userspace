#pragma once

#include "t4corun.h"

enum combos {
    //LYR_FUNCTION,
    JK_ENTER,
    KL_ESC,
    DF_TAB,
    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

//const uint16_t PROGMEM lyr_fun_combo[]     = { BSP_NUM, OSM_SFT, COMBO_END };
const uint16_t PROGMEM jk_ent_combo[]      = { HOME_J,  HOME_K,  COMBO_END };
const uint16_t PROGMEM kl_esc_combo[]      = { HOME_K,  HOME_L,  COMBO_END };
const uint16_t PROGMEM df_tab_combo[]      = { HOME_D,  HOME_F,  COMBO_END };

combo_t key_combos[COMBO_LENGTH] = {
    //[LYR_FUNCTION] = COMBO(lyr_fun_combo,     FUNC),
    [JK_ENTER]     = COMBO(jk_ent_combo,      KC_ENT),
    [KL_ESC]       = COMBO(kl_esc_combo,      KC_ESC),
    [DF_TAB]       = COMBO(df_tab_combo,      KC_TAB)
};
