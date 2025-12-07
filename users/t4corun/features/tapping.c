#include "tapping.h"

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        //Stop chordal from working for GUI and ALT
        case HRM_A:  // Qwerty GUI
            if (other_keycode == KC_SPC) {
                return true;        
            } else {
                return false;
            }
            break;
        case HRM_S:  // Qwerty Alt
        case HRM_L:  // Qwerty Alt
        case HRM_QT: // Qwerty GUI
        case HRM_R:  // ColemakDH Alt
        case HRM_I:  // ColemakDH Alt
        case HRM_O:  // ColemakDH GUI
            return false;
        default:
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);

}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // make GUI and ALT slower
        case HRM_A:  // Qwerty GUI
        case HRM_S:  // Qwerty Alt
        case HRM_L:  // Qwerty Alt
        case HRM_QT: // Qwerty GUI
        case HRM_R:  // ColemakDH Alt
        case HRM_I:  // ColemakDH Alt
        case HRM_O:  // ColemakDH GUI
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }

}