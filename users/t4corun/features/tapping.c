#include "tapping.h"

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        case HRM_A:
            switch (other_keycode) {
                case KC_L:
                    return false;
                default:
                    return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);

}