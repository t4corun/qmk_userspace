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
#   undef  CAPS_WORD_IDLE_TIMEOUT

#   define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#   define CAPS_WORD_IDLE_TIMEOUT 2000
#endif //CAPS_WORD_ENABLE

/* Split keyboard
 * https://docs.qmk.fm/features/split_keyboard
 */
#if defined(SPLIT_KEYBOARD)
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
#   define OLED_TIMEOUT 60000                    //1 min
#   define OLED_FONT_H "./features/oled/font.c"
#endif //OLED_ENABLE

/* Audio
 * https://docs.qmk.fm/features/audio
 * https://docs.qmk.fm/squeezing_avr#audio-settings
 */
#if defined(AUDIO_ENABLE)
#   undef DEFAULT_LAYER_SONGS

#   define NO_MUSIC_MODE
#   define AUDIO_CLICKY
#   define DEFAULT_LAYER_SONGS { \
        SONG(QWERTY_SOUND)      \
        ,SONG(COLEMAK_SOUND)    \
        ,SONG(GUITAR_SOUND)     \
        }
#endif // AUDIO_ENABLE

/* Haptic Feedback
 * https://docs.qmk.fm/features/haptic_feedback
 */
#if defined(HAPTIC_ENABLE) && defined(HAPTIC_DRV2605L)
#   undef DRV2605L_GREETING
#   undef DRV2605L_DEFAULT_MODE

#   define DRV2605L_GREETING     DRV2605L_EFFECT_750_MS_ALERT_100
#   define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_STRONG_CLICK_1_100
#endif // HAPTIC_ENABLE && HAPTIC_DRV2605L

/* RGB Matrix
*  https://docs.qmk.fm/features/rgb_matrix
*/
#if defined(RGB_MATRIX_ENABLE)
#   undef RGB_MATRIX_TIMEOUT
#   undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   undef RGB_MATRIX_DEFAULT_HUE
#   undef RGB_MATRIX_DEFAULT_SAT
#   undef RGB_MATRIX_DEFAULT_VAL
#   undef RGB_MATRIX_DEFAULT_SPD
#   undef RGB_MATRIX_DEFAULT_MODE

#   define RGB_MATRIX_SLEEP
#   define RGB_MATRIX_TIMEOUT 60000 //1 min

#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#   define RGB_MATRIX_DEFAULT_HUE 4
#   define RGB_MATRIX_DEFAULT_SAT 79
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_DEFAULT_SPD 127

#   define ENABLE_RGB_MATRIX_RIVERFLOW
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
#endif //RGB_MATRIX_ENABLE
