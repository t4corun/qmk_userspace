#include "tapping.h"

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        case HRM_A:
            return false;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);

}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case HRM_A:
        case HRM_QT:
        case HRM_O:
            return TAPPING_TERM + 400;
        default:
            return TAPPING_TERM;
    }

}