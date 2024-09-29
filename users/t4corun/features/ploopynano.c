#include "ploopynano.h"

// helper function to put ploopy nano into bootloader
// my ploopy nano will reset when num/caps/scroll lock is enabled
void reset_ploopynano(void) {
    // turn on all three host states
    if(!host_keyboard_led_state().num_lock) { tap_code(KC_NUM); }
    if(!host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
    if(!host_keyboard_led_state().scroll_lock) { tap_code(KC_SCRL); }

    // then turn them off
    tap_code(KC_NUM);
    tap_code(KC_CAPS);
    tap_code(KC_SCRL);
}

bool process_record_user_ploopynano(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // makes scroll lock a hold instead of toggle
        // enables momentary drag scroll on ploopy nano
        case KC_SCRL:
            record->event.pressed ? tap_code(KC_SCRL) : tap_code(KC_SCRL);
            return false;
        // makes num lock a hold instead of toggle
        // prevents accidental ploopy nano going into bootloader
        case KC_NUM:
            record->event.pressed ? tap_code(KC_NUM) : tap_code(KC_NUM);
            return false;
    }
    return true;
}
