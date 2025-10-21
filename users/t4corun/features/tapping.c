#include "tapping.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_N:
        case HOME_E:
        case HOME_I:
            return 800;
        default:
            return TAPPING_TERM;
    }
}