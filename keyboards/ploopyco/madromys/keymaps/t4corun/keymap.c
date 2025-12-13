/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "t4corun.h"

#define _BASE        0
#define _SNIPER      1
#define _DRAG_SCROLL 2

#define DRAGSCR MO(_DRAG_SCROLL)
#define SNIPER  MO(_SNIPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ___x___, ___x___, ___x___, ___x___

    [_BASE] = LAYOUT( 
        MS_BTN5, MS_BTN4, DRAGSCR, MS_BTN2, 
        MS_BTN1,                   SNIPER ),

    [_SNIPER] = LAYOUT(
        MS_BTN5, MS_BTN4, ___x___, MS_BTN2, 
        MS_BTN1,                   _______ ),

    [_DRAG_SCROLL] = LAYOUT( 
        QK_BOOT, ___x___, _______, MS_BTN4, 
        MS_BTN3,                   DPI_CONFIG )

};


// ================================================

static bool drag_scroll_state = false;
static bool sniper_state      = false;

layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _DRAG_SCROLL:
            if ( sniper_state == true ) {
                sniper_state = !sniper_state;
            }
            pointing_device_set_cpi(dpi_array[PLOOPY_DRAGSCROLL_DPI]);
            toggle_drag_scroll();
            drag_scroll_state = !drag_scroll_state;
            break;
        case _SNIPER:
            if ( drag_scroll_state == true ) {
                toggle_drag_scroll();
                drag_scroll_state = !drag_scroll_state;
            }
            pointing_device_set_cpi(dpi_array[PLOOPY_DRAGSCROLL_DPI]);
            sniper_state = !sniper_state;
            break;
        default:
            if ( sniper_state == true ) {
                sniper_state = !sniper_state;
            }
            if ( drag_scroll_state == true ) {
                toggle_drag_scroll();
                drag_scroll_state = !drag_scroll_state;
            }
            pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
            break;
    }
    return state;
}