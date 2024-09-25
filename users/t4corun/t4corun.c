#include "t4corun.h"

// Keeps track of base layer so only one key is needed
// to cycle through them vs making three individual ones
static uint8_t current_base_layer = FIRST_DEFAULT_LAYER;

// keep track of current mods to override existing keys
static uint8_t current_mods;

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
        (current_base_layer - 1) % NUM_DEFAULT_LAYERS;
    set_single_persistent_default_layer(current_base_layer);
}

// Customize behavior for existing keycodes or create new ones
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    current_mods = get_mods() | get_oneshot_mods();

    switch(keycode){
        // keypress/encoder turns while holding mod combinations adjust features
        // e.g. RGB settings, haptic frequency, click frequency, base layer
        case FWD_CFG:
        case REV_CFG:
            if (record->event.pressed) {
                switch (current_mods) {
#if defined(RGB_MATRIX_ENABLE)
                    case MOD_BIT(KC_LSFT):
                        keycode == FWD_CFG ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
                        break;
                    case MOD_BIT(KC_LCTL):
                        keycode == FWD_CFG ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
                        break;
                    case MOD_BIT(KC_LALT):
                        keycode == FWD_CFG ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
                        break;
                    case MOD_BIT(KC_LGUI):
                        keycode == FWD_CFG ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
                        break;
                    case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL):
                        keycode == FWD_CFG ? rgb_matrix_step() : rgb_matrix_step_reverse();
                        break;
#endif // RGB_MATRIX_ENABLE
#if defined(AUDIO_ENABLE)
                    case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
                        keycode == FWD_CFG ? clicky_freq_up() : clicky_freq_down();
                        break;
#endif // AUDIO_ENABLE
#if defined(HAPTIC_ENABLE)
                    case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
                        keycode == FWD_CFG ? haptic_mode_increase() : haptic_mode_decrease();
                        break;
#endif // HAPTIC_ENABLE
                    default:
                        break;
                }
            }
            return false;
        // press key while holding mod combinations to toggle features or enter bootloader
        case TOG_CFG:
            if (record->event.pressed) {
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
                    case MOD_BIT(KC_LSFT) | case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI):
                        haptic_reset();
                        break;
                    case MOD_BIT(KC_LSFT) | case MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
                        haptic_feedback_toggle();
                        break;
                    case MOD_BIT(KC_LCTL) | case MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
                        haptic_toggle_continuous();
                        break;
#endif // HAPTIC_ENABLE
                    default:
                        set_default_layer(true);
                        break;
                }
            }
            unregister_mods(MOD_MASK_CSAG);
            return false;
    }

    if(!process_record_user_taphold(keycode, record)) { return false; }

#if defined(ENCODER_ENABLE)
    if(!process_record_user_encoder(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

#if defined(OLED_ENABLE) && defined(WPM_ENABLE)
    if(!process_record_user_lunapet(keycode, record)) { return false; }
#endif // OLED_ENABLE && WPM_ENABLE

#if defined(PLOOPYNANO_ENABLE)
    if(!process_record_user_ploopynano(keycode, record)) { return false; }
#endif // PLOOPYNANO_ENABLE

    // let QMK process the normal behavior if not handled above
    return true;
}
