#include "t4corun.h"

// Keeps track of base layer so only one key is needed
// to cycle through them vs making three individual ones
static uint8_t current_base_layer = FIRST_DEFAULT_LAYER;

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Hold Navigation and Number to get Symbol
    state = update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL);
    state = layer_state_set_keymap(state);
    return state;
}

// helper function to adjust default layer
void set_default_layer(bool forward) {
    current_base_layer = forward ?
        (current_base_layer + 1) % NUM_DEFAULT_LAYERS :
        (current_base_layer + NUM_DEFAULT_LAYERS - 1) % NUM_DEFAULT_LAYERS;
    set_single_persistent_default_layer(current_base_layer);
}

// Customize behavior for existing keycodes or create new ones
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    if (record->event.pressed) {
#if defined(CONSOLE_ENABLE)
        uprintf("Key pressed at row: %u, col: %u\n", record->event.key.row, record->event.key.col);
        uprintf("Key pressed is: %c\n", chordal_hold_handedness(record->event.key));
        //uprintf("Tapping term: %u\n", get_tapping_term(keycode, record));
#endif //CONSOLE_ENABLE

        switch(keycode){
            // keypress/encoder turns while holding mod combinations adjust features
            // e.g. RGB settings, haptic frequency, click frequency, base layer
            case FWD_CFG:
            case REV_CFG:
                switch (current_mods) {
#if defined(RGB_MATRIX_ENABLE)
                    case MOD_MASK_RGB_HUE:
                        keycode == FWD_CFG ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
                        break;
                    case MOD_MASK_RGB_SAT:
                        keycode == FWD_CFG ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
                        break;
                    case MOD_MASK_RGB_VAL:
                        keycode == FWD_CFG ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
                        break;
                    case MOD_MASK_RGB_SPD:
                        keycode == FWD_CFG ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
                        break;
                    case MOD_MASK_RGB_MODE:
                        keycode == FWD_CFG ? rgb_matrix_step() : rgb_matrix_step_reverse();
                        break;
#endif // RGB_MATRIX_ENABLE
#if defined(AUDIO_ENABLE)
                    case MOD_MASK_CLICKY_ADJUST:
                        keycode == FWD_CFG ? clicky_freq_up() : clicky_freq_down();
                        break;
#endif // AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
                    case MOD_MASK_HAPTIC_MODE:
                        keycode == FWD_CFG ? haptic_mode_increase() : haptic_mode_decrease();
                        break;
#endif // HAPTIC_ENABLE
                    default:
                        break;
                }
                return false;

            // press key while holding mod combinations to toggle features or enter bootloader
            case TOG_CFG:
                switch (current_mods) {
                    //enter bootloader
                    case MOD_MASK_RESET:
                        reset_keyboard();
                        break;
                    case MOD_MAST_EECONFIG_INIT:
                        eeconfig_init();
                        break;
#if defined(PLOOPYNANO_ENABLE)
                    case MOD_MASK_PLOOPY_RESET:
                        reset_ploopynano();
                        break;
#endif // PLOOPYNANO_ENABLE
#if defined(RGB_MATRIX_ENABLE)
                    case MOD_MASK_RGB_TOGGLE:
                        rgb_matrix_toggle();
                        break;
#endif // RGB_MATRIX_ENABLE
#if defined(COMBO_ENABLE)
                    case MOD_MASK_COMBO_TOGGLE:
                        combo_toggle();
                        break;
#endif // COMBO_ENABLE
#if defined(AUDIO_ENABLE)
                    case MOD_MASK_AUDIO_TOGGLE:
                        is_audio_on() ? audio_off(): audio_on();
                        break;
                    case MOD_MASK_CLICKY_TOGGLE:
                        clicky_toggle();
                        break;
#endif // AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
                    case MOD_MASK_HAPTIC_TOGGLE:
                        haptic_toggle();
                        break;
                    case MOD_MASK_HAPTIC_RESET:
                        haptic_reset();
                        break;
                    case MOD_MASK_FEEDBACK_TOGGLE:
                        haptic_feedback_toggle();
                        break;
                    case MOD_MASK_CONTINUOUS_TOGGLE:
                        haptic_toggle_continuous();
                        break;
#endif // HAPTIC_ENABLE
                    default:
                        set_default_layer(true);
                        break;
                }
                return false;
        } 

    }
    
    if(!process_record_user_taphold(keycode, record)) { return false; }

#if defined(ENCODER_ENABLE)
    if(!process_record_user_encoder(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

#if defined(PLOOPYNANO_ENABLE)
    if(!process_record_user_ploopynano(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

    // let QMK process the normal behavior if not handled above
    return true;
}

void matrix_scan_user(void) {
#if defined(ENCODER_ENABLE)
    matrix_scan_encoder();
#endif //ENCODER_ENABLE
}

bool shutdown_user(bool jump_to_bootloader) {
#if defined(RGB_MATRIX_ENABLE)
    void rgb_matrix_update_pwm_buffers(void);
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif //RGB_MATRIX_ENABLE
    return false;
}

#if defined(CHORDAL_HOLD)
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {

        //I want the left hand not to work, except maybe for win+space
        case HOME_A:
            switch (other_keycode) {
                case KC_SPC:
                    return true;
                default:
                    return false;
            }
            break;
        //only want the UCCP shortcuts to work
        case HOME_E:
        case HOME_K:
            switch (other_keycode) {
                case KC_Z:
                case KC_X:
                case KC_C:
                case KC_V:
                    return true;
                default:
                    return false;
            }
            break;
        //QWERTY
        case HOME_S:
        case HOME_D:
        case HOME_F:
        case HOME_L:
        case HOME_QT:

        //COLEMAK DH
        case HOME_R:
        case HOME_SC:
        case HOME_T:
        case HOME_I:
        case HOME_O:
            return false;
        default:
            break;
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif //CHORDAL_HOLD