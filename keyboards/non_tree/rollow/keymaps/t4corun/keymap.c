/* Copyright 2024 @t4corun
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

#define LAYOUT_rollow_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_t4corun_keymap(                               \
         k00, k01, k02, k03, k04,   k05, k06, k07, k08, k09, \
         k10, k11, k12, k13, k14,   k15, k16, k17, k18, k19, \
         k20, k21, k22, k23, k24,   k25, k26, k27, k28, k29, \
    kb1, kb2, kb3, k32, k33, k34,   k35, k36,           k37, \
                             e01,   e02                      \
)                                                            \
LAYOUT_rollow_wrapper (                                      \
    k00, k01, k02, k03, k04,   k05, k06, k07, k08, k09,      \
    k10, k11, k12, k13, k14,   k15, k16, k17, k18, k19,      \
    k20, k21, k22, k23, k24,   k25, k26, k27, k28, k29,      \
              e01, k33, k34,   k35, k36, e02                 \
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

#if defined(ENCODER_MAP_ENABLE)
/* These are horizontal encoders. Found I have to make it opposite the rotary encoders for it to feel intuitive*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY]     = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_COLEMAK_DH] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_GAME]       = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_NAVIGATION] = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT), ENCODER_CCW_CW(___x___, ___x___) },
  [_NUMBER]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(FWD_TAB, REV_TAB) },
  [_SYMBOL]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___) },
  [_MOUSE]      = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT) },
  [_FUNCTION]   = { ENCODER_CCW_CW(FWD_CFG, REV_CFG), ENCODER_CCW_CW(FWD_CFG, REV_CFG) }
};
#endif //ENCODER_MAP_ENABLE
