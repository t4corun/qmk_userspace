#pragma once

#include "t4corun.h"

enum combos {
    // Left side combos
    C_TAB,
    
    // right side combos
    C_ENTER,
    C_ESCAPE,
    C_MBTN1,
    C_FUNC,

    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

//const uint16_t PROGMEM lyr_fun_combo[]     = { BSP_NUM, OSM_SFT, COMBO_END };
const uint16_t PROGMEM tab_combo[]   = { HOME_D,  HOME_F,  COMBO_END };
const uint16_t PROGMEM ent_combo[]   = { HOME_J,  HOME_K,  COMBO_END };
const uint16_t PROGMEM esc_combo[]   = { KC_M,    OR_COMM, COMBO_END };
const uint16_t PROGMEM mbtn1_combo[] = { HOME_K,  HOME_L,  COMBO_END };
const uint16_t PROGMEM func_combo[]  = { OR_DOT,  AS_MINS, COMBO_END };


combo_t key_combos[COMBO_LENGTH] = {
    [C_TAB]    = COMBO(tab_combo,   KC_TAB),
    [C_ENTER]  = COMBO(ent_combo,   KC_ENT),
    [C_ESCAPE] = COMBO(esc_combo,   KC_ESC),
    [C_MBTN1]  = COMBO(mbtn1_combo, KC_BTN1),
    [C_FUNC]   = COMBO(func_combo,  FUNC)
};
