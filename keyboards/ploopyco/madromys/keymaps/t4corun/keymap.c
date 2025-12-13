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

#define _BASE        0
#define _SNIPER      1
#define _DRAG_SCROLL 2

#define DRAGSCR MO(_DRAG_SCROLL)
#define SNIPER  MO(_SNIPER)

#define NEXTTAB LCTL(KC_W)
#define PREVTAB LCS(KC_W)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ___x___, ___x___, ___x___, ___x___

    [_BASE] = LAYOUT( 
        PREVTAB, NEXTTAB, DRAGSCR, MS_BTN2, 
        MS_BTN1,                   SNIPER ),

    [_SNIPER] = LAYOUT(
        ___x___, ___x___, ___x___, MS_BTN2, 
        MS_BTN1,                   _______ ),

    [_DRAG_SCROLL] = LAYOUT( 
        QK_BOOT, DPI_CONFIG, _______, MS_BTN4, 
        MS_BTN3,                      MS_BTN5 )

};


// ================================================

static bool is_drag_scroll_enabled = false;
static bool is_sniper_enabled      = false;

void set_mode_enabled(bool *mode_flag, bool enable, uint8_t dpi_index) {
    if (*mode_flag != enable) {
        pointing_device_set_cpi(enable ? dpi_array[dpi_index] : dpi_array[keyboard_config.dpi_config]);
        *mode_flag = enable;
    }
}

void set_sniper_enabled(bool enable) {
    set_mode_enabled(&is_sniper_enabled, enable, PLOOPY_SPECIAL_DPI);
}

void set_dragscroll_enabled(bool enable) {
    if ( is_drag_scroll_enabled != enable ) {
        toggle_drag_scroll();
    }
    set_mode_enabled(&is_drag_scroll_enabled, enable, PLOOPY_SPECIAL_DPI);
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    set_dragscroll_enabled(false);
    set_sniper_enabled(false);

    switch (get_highest_layer(state)) {
        case _DRAG_SCROLL:
            set_dragscroll_enabled( true );
            break;
        case _SNIPER:
            set_sniper_enabled( true);
            break;
        default:
            pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
            break;
    }
    return state;
}