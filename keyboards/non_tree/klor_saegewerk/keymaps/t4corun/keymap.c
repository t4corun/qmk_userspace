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

#define LAYOUT_klor_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap(                                      \
         k00, k01, k02, k03, k04,   k05, k06, k07, k08, k09,      \
         k10, k11, k12, k13, k14,   k15, k16, k17, k18, k19,      \
         k20, k21, k22, k23, k24,   k25, k26, k27, k28, k29,      \
    kb1, kb2, kb3, k32, k33, k34,   k35, k36, k37,                \
                             e01,   e02                           \
)                                                                 \
LAYOUT_klor_wrapper (                                             \
    k00, k01, k02, k03, k04,             k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14,             k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, e01,   e02, k25, k26, k27, k28, k29, \
              k32, k33, k34,             k35, k36, kb1            \
)

#define KLOR(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]     = KLOR(LAYER_QWERTY),
  [_COLEMAK_DH] = KLOR(LAYER_COLEMAK_DH),
  [_GAME]       = KLOR(LAYER_GAME),
  [_NAVIGATION] = KLOR(LAYER_NAVIGATION),
  [_NUMBER]     = KLOR(LAYER_NUMBER),
  [_SYMBOL]     = KLOR(LAYER_SYMBOL),
  [_MOUSE]      = KLOR(LAYER_MOUSE),
  [_FUNCTION]   = KLOR(LAYER_FUNCTION)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY]     = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_COLEMAK_DH] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_GAME]       = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_NAVIGATION] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(___x___, ___x___) },
  [_NUMBER]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(REV_TAB, FWD_TAB) },
  [_SYMBOL]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___) },
  [_MOUSE]      = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(ZOOMOUT, ZOOMIN)  },
  [_FUNCTION]   = { ENCODER_CCW_CW(REV_CFG, FWD_CFG), ENCODER_CCW_CW(REV_CFG, FWD_CFG) }
};
#endif // ENCODER_MAP_ENABLE
