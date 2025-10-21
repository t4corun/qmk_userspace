/*
 * Set build options for
 * - consistent configuration across all keyboards
 * - enable features specific to certain board (e.g. encoders, rgb, oled)
 * - a way to save memory on MCU
 *
 * Pattern
 * - This will hold config for features we force to be on
 * - bring in additional configuration for features that can be enabled/disabled
 */

#pragma once

//Turn off settings we won't use to save memory
#undef  LOCKING_SUPPORT_ENABLE
#undef  LOCKING_RESYNC_ENABLE

//Set common configuration for all keyboards
#define USB_POLLING_INTERVAL_MS 1

/* Tapping, Oneshot
 * https://docs.qmk.fm/tap_hold
 * https://docs.qmk.fm/one_shot_keys
 */
#undef  TAPPING_TERM
#undef  QUICK_TAP_TERM
#undef  ONESHOT_TAP_TOGGLE
#undef  ONESHOT_TIMEOUT
#undef  TAP_CODE_DELAY

#define TAPPING_TERM       165
#define QUICK_TAP_TERM     115
#define TAPPING_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT    2000
#define TAP_CODE_DELAY     5


/* Caps Word
 * https://docs.qmk.fm/features/caps_word
 *
 * Explore these
 * #undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
 * #undef CAPS_WORD_INVERT_ON_SHIFT
 */
#if defined(CAPS_WORD_ENABLE)
#   undef  DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#   undef  BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#   undef  CAPS_WORD_IDLE_TIMEOUT

#   define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#   define CAPS_WORD_IDLE_TIMEOUT 2000
#endif //CAPS_WORD_ENABLE

/* Split keyboard
 * https://docs.qmk.fm/features/split_keyboard
 */
#if defined(SPLIT_KEYBOARD)
#   undef  SPLIT_TRANSPORT_MIRROR
#   undef  SPLIT_LAYER_STATE_ENABLE
#   undef  SPLIT_LED_STATE_ENABLE
#   undef  SPLIT_MODS_ENABLE
#   undef  SPLIT_OLED_ENABLE
#   undef  SPLIT_ACTIVITY_ENABLE
#   undef  SPLIT_WPM_ENABLE
#   undef  MASTER_LEFT
#   undef  MASTER_RIGHT

#   define SPLIT_TRANSPORT_MIRROR
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#   define SPLIT_ACTIVITY_ENABLE
#   define MASTER_RIGHT
#   if defined(OLED_DISPLAY_128X64)
#       define SPLIT_LAYER_STATE_ENABLE
#   endif // OLED_DISPLAY_128X64
#endif // SPLIT_KEYBOARD

/* OLED
 * https://docs.qmk.fm/features/oled_driver
 */
#if defined(OLED_ENABLE)
#   undef  OLED_TIMEOUT
#   undef  OLED_FONT_H

#   define OLED_TIMEOUT 60000 //1 min
#   define OLED_FONT_H "./features/oled/font.c"
#endif //OLED_ENABLE

/* Haptic Feedback
 * https://docs.qmk.fm/features/haptic_feedback
 */
#if defined(HAPTIC_ENABLE) && defined(HAPTIC_DRV2605L)
#   undef  DRV2605L_GREETING
#   undef  DRV2605L_DEFAULT_MODE

#   define DRV2605L_GREETING     DRV2605L_EFFECT_750_MS_ALERT_100
#   define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_STRONG_CLICK_1_100
#endif // HAPTIC_ENABLE && HAPTIC_DRV2605L

/* Audio
 * https://docs.qmk.fm/features/audio
 * https://docs.qmk.fm/squeezing_avr#audio-settings
 */
#if defined(AUDIO_ENABLE)
#   undef  NO_MUSIC_MODE
#   undef  AUDIO_CLICKY
#   undef  DEFAULT_LAYER_SONGS

#   define NO_MUSIC_MODE
#   define AUDIO_CLICKY
#   define DEFAULT_LAYER_SONGS { \
        SONG(QWERTY_SOUND)      \
        ,SONG(COLEMAK_SOUND)    \
        ,SONG(GUITAR_SOUND)     \
        }
#endif // AUDIO_ENABLE

/* RGB Matrix
*  https://docs.qmk.fm/features/rgb_matrix
*/
#if defined(RGB_MATRIX_ENABLE)
#   undef  RGB_MATRIX_SLEEP
#   undef  RGB_MATRIX_TIMEOUT

#   undef  RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   undef  RGB_MATRIX_DEFAULT_HUE
#   undef  RGB_MATRIX_DEFAULT_SAT
#   undef  RGB_MATRIX_DEFAULT_VAL
#   undef  RGB_MATRIX_DEFAULT_SPD
#   undef  RGB_MATRIX_DEFAULT_MODE

#   undef  RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#   undef  RGB_MATRIX_TYPING_HEATMAP_SPREAD
#   undef  RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
#   undef  RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP

#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
#   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#   undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   undef ENABLE_RGB_MATRIX_HUE_BREATHING
#   undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#   undef ENABLE_RGB_MATRIX_HUE_WAVE
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#   undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#   undef ENABLE_RGB_MATRIX_STARLIGHT
#   undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#   undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#   undef ENABLE_RGB_MATRIX_RIVERFLOW
#   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef ENABLE_RGB_MATRIX_SPLASH
#   undef ENABLE_RGB_MATRIX_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#   define RGB_MATRIX_SLEEP
#   define RGB_MATRIX_TIMEOUT 60000 //1 min

#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#   define RGB_MATRIX_DEFAULT_HUE 4
#   define RGB_MATRIX_DEFAULT_SAT 79
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_DEFAULT_SPD 127

#   if defined(KEYBOARD_bastardkb_charybdis_3x5)        \
        || defined(KEYBOARD_dztech_dz60rgb_v2_1)        \
        || defined(KEYBOARD_bluebell_swoop)             \
        || defined(KEYBOARD_non_tree_klor_saegewerk)    \
        || defined(KEYBOARD_non_tree_keyball39)

#       define ENABLE_RGB_MATRIX_BREATHING
#       define ENABLE_RGB_MATRIX_BAND_VAL
#       define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#       define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#       define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#       define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#       define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#       define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#       define ENABLE_RGB_MATRIX_SPLASH
#       define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#       define ENABLE_RGB_MATRIX_RIVERFLOW

#       define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW

   //enable minimal effects to save memory
#   else
#       define ENABLE_RGB_MATRIX_BAND_VAL
#       define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#       define ENABLE_RGB_MATRIX_RIVERFLOW
#       define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
#   endif //KEYBOARD_bastardkb_charybdis_3x5...

   //heatmap specific settings
#   if defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
#       define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 9     //default 25
#       define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40               //40
#       define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16           //16
#       define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 20        //32
#   endif //ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif //RGB_MATRIX_ENABLE
