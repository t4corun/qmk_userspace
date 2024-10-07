#include "t4corun.h"

/*
 * Keymap pattern:
 *
 * - Choose a layout from the keyboard defintions (e.g. keyboard.json) and create an alias
 * - Define which keys from my layers will be used/overriden in the target keyboard
 *     For example: e01 and e02 represent encoder clicks. Those won't be passed to keybards
 *     without encoders
 * - Create an alias for the above translation
 * - Create the keymaps array. Feed in my t4corun.h layers wrappers into the translation alias
 */

#define LAYOUT_planck_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_t4corun_keymap(                                            \
         k00, k01, k02, k03, k04,   k05, k06, k07, k08, k09,              \
         k10, k11, k12, k13, k14,   k15, k16, k17, k18, k19,              \
         k20, k21, k22, k23, k24,   k25, k26, k27, k28, k29,              \
    kb1, kb2, kb3, k32, k33, k34,   k35, k36,           k37,              \
                             e01,   e02                                   \
)                                                                         \
LAYOUT_planck_wrapper (                                                   \
	k00, k01, k02, k03, k04, KC_NO, KC_NO, k05, k06, k07,   k08,   k09,   \
	k10, k11, k12, k13, k14, KC_NO, KC_NO, k15, k16, k17,   k18,   k19,   \
	k20, k21, k22, k23, k24, KC_NO, KC_NO, k25, k26, k27,   k28,   k29,   \
	kb1, kb2, kb3, k32, k33, k34,   k35,   k36, k37, KC_NO, KC_NO, KC_ESC \
)

#define KEYBOARD(...) LAYOUT_t4corun_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]     = KEYBOARD(LAYER_QWERTY),
  [_COLEMAK_DH] = KEYBOARD(LAYER_COLEMAK_DH),
  [_GAME]       = KEYBOARD(LAYER_GAME),
  [_NAVIGATION] = KEYBOARD(LAYER_NAVIGATION),
  [_NUMBER]     = KEYBOARD(LAYER_NUMBER),
  [_SYMBOL]     = KEYBOARD(LAYER_SYMBOL),
  [_MOUSE]      = KEYBOARD(LAYER_MOUSE),
  [_FUNCTION]   = KEYBOARD(LAYER_FUNCTION)
};
