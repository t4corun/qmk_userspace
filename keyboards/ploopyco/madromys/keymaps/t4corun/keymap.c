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

#define _BASE  0
#define _UPPER 1

#define UPPER MO(_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ___x___, ___x___, ___x___, ___x___

    [BASE] = LAYOUT( 
        MS_BTN4, MS_BTN4, MS_BTN1, MS_BTN2, 
        UPPER,                     MS_BTN3 ),

    [RAISED] = LAYOUT( 
        MS_BTN4, MS_BTN5, MS_BTN3, MS_BTN4, 
        _______,                   DPI_CONFIG )
};


// ================================================

static bool drag_scroll_state = false;

layer_state_t layer_state_set_keymap(layer_state_t state) {

    switch (get_highest_layer(state)) {
        case _UPPER:
            if ( drag_scroll_state == false ) {
                toggle_drag_scroll();
                drag_scroll_state == true;
            }
            break;
        default:
            if ( drag_scroll_state == true ) {
                toggle_drag_scroll();
                drag_scroll_state == false;
            }
            break;  
    }
    return state;
}
