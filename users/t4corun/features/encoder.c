#include "encoder.h"

// enables encoder to handle alt/ctrl tab and ctrl scroll wheel
static bool     hold_forward_active = false;
static bool     hold_reverse_active = false;
static uint16_t hold_mod_timer = 0;

bool process_record_user_encoder(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // turn encoder for tab and shift tab
        // hold alt or ctrl while turning for window / tab switching
        case FWD_TAB:
        case REV_TAB:
            if (record->event.pressed) {
                if (keycode == FWD_TAB && !hold_forward_active) {
                    hold_forward_active = true;
                    hold_reverse_active = false;
                    unregister_mods(MOD_MASK_SHIFT);
                }
                if (keycode == REV_TAB && !hold_reverse_active) {
                    hold_forward_active = false;
                    hold_reverse_active = true;
                    register_mods(MOD_MASK_SHIFT);
                }
                hold_mod_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        // turn encoder for mouse wheel zoom
        case ZOOMIN:
        case ZOOMOUT:
            if (record->event.pressed) {
                if (!hold_forward_active) {
                    hold_forward_active = true;
                    register_mods(MOD_MASK_CTRL);
                }
                hold_mod_timer = timer_read();
                keycode == ZOOMIN ? register_code(KC_WH_U) : register_code(KC_WH_D);
            } else {
                keycode == ZOOMIN ? unregister_code(KC_WH_U) : unregister_code(KC_WH_D);
            }
            return false;
    }
    return true;
}

void matrix_scan_encoder(void) {
    // timer for the hold modds
    // will hold modifiers so things like alt-tab work properly using the encoder
    if (hold_forward_active || hold_reverse_active) {
        if (timer_elapsed(hold_mod_timer) > HOLD_MOD_TIMEOUT) {
            unregister_mods(MOD_MASK_CSAG);
            hold_forward_active = false;
            hold_reverse_active = false;
        }
    }
}
