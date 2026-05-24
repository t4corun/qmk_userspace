#pragma once

#include "t4corun.h"


enum combos {
    // Left side combos
    C_AT,
    C_TAB,
    
    // right side combos
    C_ENTER,

    COMBO_LENGTH
};


//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM at_combo[]    = { HRM_F,   KC_G,    COMBO_END };
const uint16_t PROGMEM tab_combo[]   = { KC_C,    KC_V,    COMBO_END };
const uint16_t PROGMEM ent_combo[]   = { KC_M,    KC_COMM, COMBO_END };

combo_t key_combos[COMBO_LENGTH] = {
    [C_AT]     = COMBO(at_combo,    KC_AT),
    [C_TAB]    = COMBO(tab_combo,   KC_TAB),
    [C_ENTER]  = COMBO(ent_combo,   KC_ENT)
};