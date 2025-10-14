#pragma once

#include "t4corun.h"

// Tells the process_tap_hold what kind of hold action is wanted
enum taphold_action {
    HOLD_SINGLETP = 0,
    HOLD_DOUBLETP,
    HOLD_BRACKETS
};

void single_tap (uint16_t key);
void double_tap (uint16_t key, uint32_t ms);
void insert_brackets (uint16_t left, uint16_t right, uint32_t ms);
bool process_tap_hold (keyrecord_t* record, uint16_t tap_keycode, uint16_t hold_keycode, int mode);
bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record);
