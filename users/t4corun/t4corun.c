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
        switch(keycode){
            // keypress/encoder turns while holding mod combinations adjust features
            // e.g. RGB settings, haptic frequency, click frequency, base layer
            case FWD_CFG:
            case REV_CFG:
                switch (current_mods) {
#if defined(RGB_MATRIX_ENABLE)
                    case MOD_MASK_RGB_HUE:
                    case MOD_MASK_RGB_SAT:
                    case MOD_MASK_RGB_VAL:
                    case MOD_MASK_RGB_SPD:
                    case MOD_MASK_RGB_MODE:
                        handle_rgbmatrix(keycode, current_mods);
                        break;
#endif // RGB_MATRIX_ENABLE
#if defined(AUDIO_ENABLE)
                    case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
                        handle_audio(keycode);
                        break;
#endif // AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
                    case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
                        handle_haptic(keycode);
                        break;
#endif // HAPTIC_ENABLE
                    default:
                        break;
                }
                return false;

            // press key while holding mod combinations to toggle features or enter bootloader
            case TOG_CFG:
                toggle_features(keycode, current_mods);
                return false;
        }
    }

    if(!process_record_user_taphold(keycode, record)) { return false; }

    if(!process_achordion(keycode, record)) { return false; }

#if defined(ENCODER_ENABLE)
    if(!process_record_user_encoder(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

#if defined(PLOOPYNANO_ENABLE)
    if(!process_record_user_ploopynano(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

    // let QMK process the normal behavior if not handled above
    return true;
}

void toggle_features(uint16_t keycode, uint8_t current_mods) {
    switch (current_mods) {
        //enter bootloader
        case MOD_BIT(KC_LSFT):
            reset_keyboard();
            break;
        case MOD_BIT(KC_LCTL):
            eeconfig_init();
            break;
#if defined(PLOOPYNANO_ENABLE)
        case MOD_BIT(KC_LALT):
            reset_ploopynano();
            break;
#endif // PLOOPYNANO_ENABLE
#if defined(RGB_MATRIX_ENABLE)
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL):
            rgb_matrix_toggle();
            break;
#endif // RGB_MATRIX_ENABLE
#if defined(COMBO_ENABLE)
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT):
            combo_toggle();
            break;
#endif // COMBO_ENABLE
#if defined(AUDIO_ENABLE)
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI):
            is_audio_on() ? audio_off(): audio_on();
            break;
        case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
            clicky_toggle();
            break;
#endif // AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
            haptic_toggle();
            break;
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI):
            haptic_reset();
            break;
        case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
            haptic_feedback_toggle();
            break;
        case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
            haptic_toggle_continuous();
            break;
#endif // HAPTIC_ENABLE
        default:
            set_default_layer(true);
            break;
    }
}

#if defined(RGB_MATRIX_ENABLE)
void handle_rgbmatrix(uint16_t keycode, uint8_t current_mods) {
    switch (current_mods) {
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
    }
}
#endif // RGB_MATRIX_ENABLE

#if defined(AUDIO_ENABLE)
void handle_audio(uint16_t keycode) {
    keycode == FWD_CFG ? clicky_freq_up() : clicky_freq_down();
}
#endif // AUDIO_ENABLE

#if defined(HAPTIC_ENABLE)
void handle_haptic(uint16_t keycode) {
    keycode == FWD_CFG ? haptic_mode_increase() : haptic_mode_decrease();
}
#endif // HAPTIC_ENABLE

void matrix_scan_user(void) {
    achordion_task();

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

/*
 *  Achordion customizations
 */

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case BK_LCBR:
        case BK_LABK:
        case BK_LBRC:
        case BK_LPRN:
        case BK_DQUO:
        case BK_SQUO:
        case DT_BSLS:
        case DT_SLSH:
        case DT_PIPE:
        case DT_EQL:
        case DT_PLUS:
        case OR_COMM:
        case OR_DOT:
        case OR_PERC:
        case AS_MINS:
        case AS_GRV:
        case AS_SCLN:
        case AS_QUOT:
            return 0; // disable achordion for my other tap holds

        default:
            return 800; // 800 ms
    }
}

// By default, use the BILATERAL_COMBINATIONS rule to consider the tap-hold key
// "held" only when it and the other key are on opposite hands.
bool achordion_chord(uint16_t tap_hold_keycode,
                        keyrecord_t* tap_hold_record,
                        uint16_t other_keycode,
                        keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        // Prevent Windows + L from firing when roll typing all
        case HOME_A:
            if (other_keycode == HOME_L) {
                return false;
            }
            break;

        // Exceptionally allow Win + L as a same-hand chord.
        case HOME_QT:
            if (other_keycode == HOME_L) {
                return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    if ( keymap_config.swap_lctl_lgui ) {
        // If in MAC mode, Shift and GUI mods are eager, and Alt and GUI are not.
        return (mod & (MOD_LALT | MOD_LCTL)) == 0;
    }
    // Windows is the default, Shift and Ctrl mods are eager, and Alt and GUI are not.
    return (mod & (MOD_LALT | MOD_LGUI)) == 0;
}