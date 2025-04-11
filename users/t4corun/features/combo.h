#pragma once

#include "t4corun.h"

enum combos {
    LYR_FUNCTION,
    JK_ENTER,
    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lyr_fun_combo[]  = { OSM_SFT, SYM_BSP, COMBO_END };
const uint16_t PROGMEM jk_ent_combo[]   = { KC_J,    KC_K, COMBO_END };


combo_t key_combos[COMBO_LENGTH] = {
    [LYR_FUNCTION]  = COMBO(lyr_fun_combo,  FUNC),
    [JK_ENTER]      = COMBO(jk_ent_combo,   KC_ENT),
};
