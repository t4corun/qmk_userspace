#pragma once

#include "t4corun.h"

enum combos {
    MOUSE_DRGTOG,
    LYR_FUNCTION,
    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM mou_drg_combo[]  = { KC_X,    KC_V,    COMBO_END };
const uint16_t PROGMEM lyr_fun_combo[]  = { NUM,     TR_LSFT, COMBO_END };

combo_t key_combos[COMBO_LENGTH] = {
    [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS),
    [LYR_FUNCTION]  = COMBO(lyr_fun_combo,  FUNC)
};
