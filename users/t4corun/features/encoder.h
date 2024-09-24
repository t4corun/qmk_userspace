#pragma once

#include "t4corun.h"

// how long the mod will be held before releasing [ms]
#define HOLD_MOD_TIMEOUT 1000

bool process_record_user_encoder(uint16_t keycode, keyrecord_t *record);
