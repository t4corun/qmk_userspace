#include "oled_128x64.h"
#include "oled_common.c"

/* render horizonal OLED (Work in progress)
 * 21 cols x 8 rows
 *
 * left side (split)
 *
 * 00  base lyr: current lyr
 * 01  ---------------------
 * 02
 * 03   mod  mod  mod  mod
 * 04   mod  mod  mod  mod
 * 05
 * 06  -------------- xxxxx
 * 07   NCS           xxxxx
 *
 *
 * 00  base lyr: current lyr
 * 01  ---------------------
 * 02  ssssscccccaaaaaggggg
 * 03  ssssscccccaaaaaggggg
 * 04  ssssscccccaaaaaggggg
 * 05
 * 06  -------------- xxxxx
 * 07   NCS           xxxxx
 *
 * right side (main)
 *
 * 00  KLOR Saegewerk
 * 01  ---------------------
 * 02  RGB matrix mode: xxx
 * 03  hue: xxx    sat: xxx
 * 04  val: xxx    spd: xxx
 * 05
 * 06  -------------- xxxxx
 * 07   xx xx xx xx   xxxxx
 *
 */

const uint8_t line_count = 8;

const char PROGMEM scroll_off[]     = {0x8F, 0};
const char PROGMEM scroll_on[]      = {0xCF, 0};
const char PROGMEM num_off[]        = {0xC4, 0};
const char PROGMEM num_on[]         = {0x84, 0};
const char PROGMEM caps_off[]       = {0x87, 0};
const char PROGMEM caps_on[]        = {0x89, 0};

const char PROGMEM rgb_matrix_off[] = {0xA5, 0xA6, 0};
const char PROGMEM rgb_matrix_on[]  = {0x85, 0x86, 0};
const char PROGMEM sound_off[]      = {0xD9, 0xDA, 0};
const char PROGMEM sound_on[]       = {0xD7, 0xD8, 0};
const char PROGMEM haptic_off[]     = {0xD5, 0xD6, 0};
const char PROGMEM haptic_on[]      = {0xD3, 0xD4, 0};
const char PROGMEM combo_off[]      = {0xDD, 0xDE, 0};
const char PROGMEM combo_on[]       = {0xDB, 0xDC, 0};

const char PROGMEM kb_logo_L1[]     = {0x94, 0x95, 0x96, 0x97, 0x98, 0};
const char PROGMEM kb_logo_L2[]     = {0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0};

const char *kb_logo[]               = {kb_logo_L1,  kb_logo_L2};

const char PROGMEM mod_sep[]        = {0xC7, 0xC7, 0};

const char PROGMEM line_off[] =
    {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0};

const char PROGMEM line_sep[] =
    {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};

const char PROGMEM line_sep_short[] =
    {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};


// Coordinate the OLED rendering
bool oled_task_user (void) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();

    if (is_keyboard_master()) {
        clear_lines(0, 0, line_count);
        oled_write_P(PSTR(OLED_KEYBOARD_NAME), false);
        oled_set_cursor(0,1);
        oled_write_P(line_sep, false);
#if defined(RGB_MATRIX_ENABLE)
        render_rgb_status(2,0);
#endif // RGB_MATRIX_ENABLE
        oled_set_cursor(0,6);
        oled_write_P(line_sep_short, false);
        render_feature_status(7,1);
        if ( keymap_config.swap_lctl_lgui ) {
            render_logo(6,15, mac_logo, sizeof(mac_logo) / sizeof(mac_logo[0]));
        } else {
            render_logo(6,15, win_logo, sizeof(win_logo) / sizeof(win_logo[0]));
        }
    } else {
        clear_lines(0, 0, line_count);
        render_default_layer_state(0,0);
        render_layer_state(0,11);
        render_mods(2, 0,  MOD_GUI,   current_mods);
        render_mods(2, 5,  MOD_ALT,   current_mods);
        render_mods(2, 10, MOD_CTRL,  current_mods);
        render_mods(2, 15, MOD_SHIFT, current_mods);
        oled_set_cursor(0,1);
        oled_write_P(line_sep, false);
        oled_set_cursor(0,6);
        oled_write_P(line_sep_short, false);
        render_led_status(7,1);
        render_logo(6,15, kb_logo, sizeof(kb_logo) / sizeof(kb_logo[0]));
    }
    return false;
}

// set orientation for each OLED format
oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    //OLED_ROTATION_180 for KLOR
    return OLED_ROTATION_180;
}

void render_feature_status (uint8_t row, uint8_t col) {
    oled_set_cursor(col, row);
#if defined(RGB_MATRIX_ENABLE)
    oled_write_P(rgb_matrix_is_enabled() ? rgb_matrix_on : rgb_matrix_off, false);
#else
    oled_write_P(rgb_matrix_off, false);
#endif //RGB_MATRIX_ENABLED
    oled_set_cursor(col + 3, row);
#if defined(AUDIO_ENABLE)
    oled_write_P(is_audio_on() ? sound_on : sound_off, false);
#else
    oled_write_P(sound_off, false);
#endif //AUDIO_ENABLE
    oled_set_cursor(col + 6, row);
#if defined(HAPTIC_ENABLE)
    oled_write_P(haptic_get_enable() ? haptic_on : haptic_off, false);
#else
    oled_write_P(haptic_off, false);
#endif //HAPTIC_ENABLE
    oled_set_cursor(col + 9, row);
#if defined(COMBO_ENABLE)
    oled_write_P(is_combo_enabled() ? combo_on : combo_off, false);
#else
    oled_write_P(combo_off, false);
#endif //HAPTIC_ENABLE
}

#if defined(RGB_MATRIX_ENABLE)
typedef struct {
    uint8_t mod;
    const char *label;
    uint8_t (*get_value)(void);
    uint8_t col_offset;
    uint8_t row_offset;
} ModDisplay;

ModDisplay mod_displays[] = {
    {MOD_MASK_RGB_MODE, "rgb matrix mode: ", rgb_matrix_get_mode,  0,  0},
    {MOD_MASK_RGB_HUE,  "hue: ",             rgb_matrix_get_hue,   0,  1},
    {MOD_MASK_RGB_SAT,  "sat: ",             rgb_matrix_get_sat,   12, 1},
    {MOD_MASK_RGB_VAL,  "val: ",             rgb_matrix_get_val,   0,  2},
    {MOD_MASK_RGB_SPD,  "spd: ",             rgb_matrix_get_speed, 12, 2},
};

void render_rgb_status (uint8_t row, uint8_t col) {
    uint8_t current_mods = get_mods() | get_oneshot_mods();
    bool setting_enabled = false;

    oled_set_cursor(col, row);
    if (get_highest_layer(layer_state) == _FUNCTION) {
        for (uint8_t i = 0; i < sizeof(mod_displays) / sizeof(mod_displays[0]); i++) {
            setting_enabled = (current_mods == mod_displays[i].mod);
            oled_set_cursor(col + mod_displays[i].col_offset, row + mod_displays[i].row_offset);
            oled_write_P(PSTR(mod_displays[i].label), false);
            oled_write(get_u8_str(mod_displays[i].get_value(), ' '), setting_enabled);            
        }
    } 
}
#endif // RGB_MATRIX_ENABLE