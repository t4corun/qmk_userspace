#include "oled.h"
#include "oled_common.c"

/* render vertical OLED
 * 16 rows x 5 cols
 *
 * Left side (split)
 * - spacing is weird because of where the image is in the font
 * - this side won't show anything unless mods or host state are active
 *
 * 00  sssss
 * 01  *sft*
 * 02  sssss
 * 03
 * 04  ccccc
 * 05  *ctl*
 * 06  ccccc
 * 07  aaaaa
 * 08  *alt*
 * 09  aaaaa
 * 10
 * 11  ggggg
 * 12  *gui*
 * 13  ggggg
 * 14
 * 15   NCS
 *
 *
 * Right side (main)
 * - this will show data all the time
 *
 * 00  bslyr
 * 01   nav
 * 02   num
 * 03   sym
 * 04   fun
 * 05
 * 06  -cpi-
 * 07  xxxxx
 * 08
 * 09  -rgb-  
 * 10    on 
 * 11
 * 12  
 * 13   mod
 * 14   mod
 * 15
 *
 * 00  bslyr
 * 01   nav
 * 02   num
 * 03   sym
 * 04   fun
 * 05
 * 06  -rgb-
 * 07  m 999
 * 08  h 999
 * 09  s 999
 * 10  v 999
 * 11  s 999
 * 12  
 * 13   mod
 * 14   mod
 * 15
 *
 */

const uint8_t line_count = 16;

//allows RGB settings to overwrite the pointer CPI due to screen height restrictions, otherwise rgb will
// immediately follow OS status to not leave a gap if pointer is not found
#if defined(POINTING_DEVICE_ENABLE)
const uint8_t shift_up = 3;
#else
const uint8_t shift_up = 0;
#endif //POINTING_DEVICE_ENABLE

const char PROGMEM scroll_on[]   = {0x8F, 0};
const char PROGMEM scroll_off[]  = {0x80, 0};
const char PROGMEM num_on[]      = {0xC4, 0};
const char PROGMEM num_off[]     = {0x80, 0};
const char PROGMEM caps_on[]     = {0x87, 0};
const char PROGMEM caps_off[]    = {0x80, 0};

const char PROGMEM line_off[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0};

// Render each screen
bool oled_task_user (void) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    //process_record_user is only processed on master side
    //split side OLED does not respond to key presses custom behaviors
    if (is_keyboard_master()) {
        clear_lines(0, 0, line_count);
        render_default_layer_state(0, 0);
        render_layer_state_list(1, 0);
#if defined(POINTING_DEVICE_ENABLE)
        render_pointercpi_keymap(6, 0);
#endif // POINTING_DEVICE_ENABLE
#if defined(RGB_MATRIX_ENABLE)
#   if defined(POINTING_DEVICE_ENABLE)
        render_rgb_status(9, 0);
#   else
        render_rgb_status(6, 0);
#   endif //POINTING_DEVICE_ENABLE
#endif // RGB_MATRIX_ENABLE
        if ( keymap_config.swap_lctl_lgui ) {
            render_logo(13, 0, mac_logo, sizeof(mac_logo) / sizeof(mac_logo[0]));
        } else {
            render_logo(13, 0, win_logo, sizeof(win_logo) / sizeof(win_logo[0]));
        }
    } else {

        //can't adjust the split side as keymap_config is sync to split side
        clear_lines(0,  0, line_count);
        render_mods(0,  0, MOD_SHIFT, current_mods);
        render_mods(4,  0, MOD_CTRL,  current_mods);
        render_mods(7,  0, MOD_ALT,   current_mods);
        render_mods(11, 0, MOD_GUI,   current_mods);
        render_led_status(15, 1);
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_270 for Rollow/Corne/Swoop
    return OLED_ROTATION_270;
}

#if defined(RGB_MATRIX_ENABLE)
typedef struct {
    uint8_t mod;
    const char *label;
    uint8_t (*get_value)(void);
} ModDisplay;

ModDisplay mod_displays[] = {
    {MOD_MASK_RGB_MODE, "m ", rgb_matrix_get_mode},
    {MOD_MASK_RGB_HUE,  "h ", rgb_matrix_get_hue},
    {MOD_MASK_RGB_SAT,  "s ", rgb_matrix_get_sat},
    {MOD_MASK_RGB_VAL,  "v ", rgb_matrix_get_val},
    {MOD_MASK_RGB_SPD,  "s ", rgb_matrix_get_speed},
};

void render_rgb_status (uint8_t row, uint8_t col) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    bool setting_enabled = false;

    if (get_highest_layer(layer_state) == _FUNCTION) {
        oled_set_cursor(col, row - shift_up);
        oled_write_P(PSTR("-rgb-"), false);
        for (uint8_t i = 0; i < sizeof(mod_displays) / sizeof(mod_displays[0]); i++) {
            oled_set_cursor(col, row - shift_up + 1 + i);
            setting_enabled = (current_mods == mod_displays[i].mod);
            oled_write_P(PSTR(mod_displays[i].label), false);
            oled_write(get_u8_str(mod_displays[i].get_value(), ' '), setting_enabled);            
        }
    } else {
        oled_set_cursor(col, row);
        oled_write_P(PSTR("-rgb-"), false);
        rgb_matrix_is_enabled() ? oled_write_P(PSTR("  on "), false) : oled_write_P(PSTR(" off "), false);
    }
}
#endif // RGB_MATRIX_ENABLE

#if defined(POINTING_DEVICE_ENABLE)
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
__attribute__((weak)) void render_pointercpi_keymap(uint8_t row, uint8_t col) {
}
#endif // POINTING_DEVICE_ENABLE
