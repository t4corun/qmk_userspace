#pragma once

#include "t4corun.h"

enum combos {
    JK_ENTER,
    MCOMMA_DEL,
    KL_ESC,
    COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_ent_combo[]     = { KC_J, KC_K,    COMBO_END };
const uint16_t PROGMEM mcomma_del_combo[] = { KC_M, BRM_COM, COMBO_END };
const uint16_t PROGMEM kl_esc_combo[]     = { KC_K, FUN_L,   COMBO_END };

combo_t key_combos[COMBO_LENGTH] = {
    [JK_ENTER]   = COMBO(jk_ent_combo,     KC_ENT),
    [MCOMMA_DEL] = COMBO(mcomma_del_combo, KC_DEL),
    [KL_ESC]     = COMBO(kl_esc_combo,     KC_ESC)
};
