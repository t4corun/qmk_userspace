#include "taphold.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //alt tap hold
        case OSM_ALT:
        case HOME_L:
        case HOME_R:
        case HOME_I:
        case HOME_S:
            return TAPPING_TERM + 100;
        
        //gui
        case HOME_A:
        case HOME_QT:
        case HOME_O:
        case OSM_GUI:
            return TAPPING_TERM + 100;
            
        default:
            return TAPPING_TERM;
    }
}

void double_tap( uint16_t key, uint32_t ms) {
    tap_code16(key);
    wait_ms(ms);
    tap_code16(key);
}

void insert_brackets (uint16_t left, uint16_t right, uint32_t ms) {
    tap_code16(left);
    wait_ms(ms);
    tap_code16(right);
    wait_ms(ms);
    tap_code16(KC_LEFT);
}

bool process_tap_hold (keyrecord_t* record, uint16_t tap_keycode, uint16_t hold_keycode, int mode) {
    if (record->tap.count > 0) { // Key is being tapped
        // register on press, unregister on release
        record->event.pressed ? register_code16(tap_keycode) : unregister_code16(tap_keycode);
    } else { // Key is being hel
        switch (mode) {
            case HOLD_BRACKETS:
                record->event.pressed ? insert_brackets(tap_keycode, hold_keycode, TAP_CODE_DELAY) : 0;
                break;
            case HOLD_DOUBLETP:
                record->event.pressed ? double_tap(tap_keycode, TAP_CODE_DELAY) : 0;
                break;
            default:
                record->event.pressed ? register_code16(hold_keycode) : unregister_code16(hold_keycode);
                break;
        }
    }
    return false;
}

bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
        //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
        //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
        // Brackets: open and close brackets and put the cursor inside
        case BK_LCBR:
            return process_tap_hold(record, KC_LCBR, KC_RCBR, HOLD_BRACKETS);
        case BK_LABK:
            return process_tap_hold(record, KC_LABK, KC_RABK, HOLD_BRACKETS);
        case BK_LBRC:
            return process_tap_hold(record, KC_LBRC, KC_RBRC, HOLD_BRACKETS);
        case BK_LPRN:
            return process_tap_hold(record, KC_LPRN, KC_RPRN, HOLD_BRACKETS);
        case BK_DQUO:
            return process_tap_hold(record, KC_DQUO, KC_DQUO, HOLD_BRACKETS);
        case BK_SQUO:
            return process_tap_hold(record, KC_QUOT, KC_QUOT, HOLD_BRACKETS);
        // double tap
        case DT_BSLS:
            return process_tap_hold(record, KC_BSLS, KC_BSLS, HOLD_DOUBLETP);
        case DT_SLSH:
            return process_tap_hold(record, KC_SLSH, KC_SLSH, HOLD_DOUBLETP);
        case DT_PIPE:
            return process_tap_hold(record, KC_PIPE, KC_PIPE, HOLD_DOUBLETP);
        case DT_EQL:
            return process_tap_hold(record, KC_EQL,  KC_EQL,  HOLD_DOUBLETP);
        case DT_PLUS:
            return process_tap_hold(record, KC_PLUS, KC_PLUS, HOLD_DOUBLETP);
        // Custom override without holding shift
        case OR_COMM:
            return process_tap_hold(record, KC_COMM, KC_LPRN, HOLD_SINGLETP);
        case OR_DOT:
            return process_tap_hold(record, KC_DOT,  KC_RPRN, HOLD_SINGLETP);
        case OR_PERC:
            return process_tap_hold(record, KC_PERC, KC_CIRC, HOLD_SINGLETP);
        // auto shift
        case AS_MINS:
            return process_tap_hold(record, KC_MINS, KC_UNDS, HOLD_SINGLETP);
        case AS_GRV:
            return process_tap_hold(record, KC_GRV,  KC_TILD, HOLD_SINGLETP);
        case AS_SCLN:
            return process_tap_hold(record, KC_SCLN, KC_COLN, HOLD_SINGLETP);
        case AS_QUOT:
            return process_tap_hold(record, KC_QUOT, KC_DQUO, HOLD_SINGLETP);
    }
    return true;
}
