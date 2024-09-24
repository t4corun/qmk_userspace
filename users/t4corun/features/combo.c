#include "combo.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // or with combo index, i.e. its name from enum.
    switch (index) {
        case LYR_FUNCTION:
            return COMBO_TERM + 100;
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        case LYR_FUNCTION:
            return true;
        default:
            return false;
    }
}

bool combo_should_trigger (uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // These combos only work on base layers
#if defined(POINTING_DEVICE_ENABLE)
        case MOUSE_DRGTOG:
#endif // POINTING_DEVICE_ENABLE
        case LYR_FUNCTION:
            if ( get_highest_layer(layer_state | default_layer_state) > NUM_DEFAULT_LAYERS - 1 ) {
                return false;
            }
        default:
            return true;
    }
}
