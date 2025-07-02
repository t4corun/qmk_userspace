#include "combo.h"

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_TAB:
        case C_ENTER:
            return true;
        default:
            return false;
    }
}

bool get_combo_must_hold(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_SNIPING:
            return true;
        default:
            return false;
    }
}

bool combo_should_trigger (uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // These combos only work on base layers
        default:
            if ( get_highest_layer(layer_state | default_layer_state) > NUM_DEFAULT_LAYERS - 1 ) {
                return false;
            } else {
                return true;
            }
    }
}