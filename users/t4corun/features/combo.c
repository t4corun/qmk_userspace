#include "combo.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // or with combo index, i.e. its name from enum.
    switch (index) {
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        default:
            return false;
    }
}

bool combo_should_trigger (uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        default:
            return true;
    }
}
