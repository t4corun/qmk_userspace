/* Copyright 2020 Christopher Courtney (@drashna)
 * Copyright 2021 Quentin LEBASTARD
 * Copyright 2021 Charly Delay (@0xcharly)
 * Copyright 2022 @Yowkees
 * Copyright 2024 t4corun (@t4corun)
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

/**
 * \brief Leverage standard qmk_firmware code for easier maintenance
 *
 * This modernization effort aims to convert Yowkees's Keyball code to use
 * standard qmk_firmware drivers wherever possible
 *
 * Pointer code leverages heavily from BastardKB's implementation
*/

#include "keyball39.h"
#include "transactions.h"
#include <string.h>

#if defined(CONSOLE_ENABLE)
#  include "print.h"
#endif // CONSOLE_ENABLE

#if defined(POINTING_DEVICE_ENABLE)

typedef union {
    uint8_t raw;
    struct {
        uint8_t pointer_default_dpi : 4; // 16 steps available.
        uint8_t pointer_sniping_dpi : 2; // 4 steps available.
        bool    is_dragscroll_enabled : 1;
        bool    is_sniping_enabled : 1;
    } __attribute__((packed));
} keyball_config_t;

static keyball_config_t g_keyball_config = {0};
static float scroll_buffer_h = 0;
static float scroll_buffer_v = 0;

/**
 * \brief Set the value of `config` from EEPROM.
 *
 * Note that `is_dragscroll_enabled` and `is_sniping_enabled` are purposefully
 * ignored since we do not want to persist this state to memory.  In practice,
 * this state is always written to maximize write-performances.  Therefore, we
 * explicitly set them to `false` in this function.
 */
static void read_keyball_config_from_eeprom(keyball_config_t* config) {
    config->raw                   = eeconfig_read_kb() & 0xff;
    config->is_dragscroll_enabled = false;
    config->is_sniping_enabled    = false;
}

/**
 * \brief Save the value of `config` to eeprom.
 *
 * Note that all values are written verbatim, including whether drag-scroll
 * and/or sniper mode are enabled.  `read_keyball_config_from_eeprom(…)`
 * resets these 2 values to `false` since it does not make sense to persist
 * these across reboots of the board.
 */
static void write_keyball_config_to_eeprom(keyball_config_t* config) {
    eeconfig_update_kb(config->raw);
}

/**
 * \brief Return the current value of the pointer's default DPI.
 */
static uint16_t get_pointer_default_dpi(keyball_config_t* config) {
    return (uint16_t)config->pointer_default_dpi * KEYBALL_DEFAULT_DPI_CONFIG_STEP + KEYBALL_MINIMUM_DEFAULT_DPI;
}

/**
 * \brief Return the current value of the pointer's sniper-mode DPI.
 */
static uint16_t get_pointer_sniping_dpi(keyball_config_t* config) {
    return (uint16_t)config->pointer_sniping_dpi * KEYBALL_SNIPING_DPI_CONFIG_STEP + KEYBALL_MINIMUM_SNIPING_DPI;
}

/**
 * \brief Set the appropriate DPI for the input config.
 */
static void maybe_update_pointing_device_cpi(keyball_config_t* config) {
    if (config->is_dragscroll_enabled) {
        pointing_device_set_cpi(KEYBALL_DRAGSCROLL_DPI);
    } else if (config->is_sniping_enabled) {
        pointing_device_set_cpi(get_pointer_sniping_dpi(config));
    } else {
        pointing_device_set_cpi(get_pointer_default_dpi(config));
    }
}

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to KEYBALL_DEFAULT_DPI_CONFIG_STEP.
 */
static void step_pointer_default_dpi(keyball_config_t* config, bool forward) {
    config->pointer_default_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to KEYBALL_SNIPING_DPI_CONFIG_STEP.
 */
static void step_pointer_sniping_dpi(keyball_config_t* config, bool forward) {
    config->pointer_sniping_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

uint16_t keyball_get_pointer_default_dpi(void) {
    return get_pointer_default_dpi(&g_keyball_config);
}

uint16_t keyball_get_pointer_sniping_dpi(void) {
    return get_pointer_sniping_dpi(&g_keyball_config);
}

void keyball_cycle_pointer_default_dpi_noeeprom(bool forward) {
    step_pointer_default_dpi(&g_keyball_config, forward);
}

void keyball_cycle_pointer_default_dpi(bool forward) {
    step_pointer_default_dpi(&g_keyball_config, forward);
    write_keyball_config_to_eeprom(&g_keyball_config);
}

void keyball_cycle_pointer_sniping_dpi_noeeprom(bool forward) {
    step_pointer_sniping_dpi(&g_keyball_config, forward);
}

void keyball_cycle_pointer_sniping_dpi(bool forward) {
    step_pointer_sniping_dpi(&g_keyball_config, forward);
    write_keyball_config_to_eeprom(&g_keyball_config);
}

bool keyball_get_pointer_sniping_enabled(void) {
    return g_keyball_config.is_sniping_enabled;
}

void keyball_set_pointer_sniping_enabled(bool enable) {
    g_keyball_config.is_sniping_enabled = enable;
    maybe_update_pointing_device_cpi(&g_keyball_config);
}

bool keyball_get_pointer_dragscroll_enabled(void) {
    return g_keyball_config.is_dragscroll_enabled;
}

void keyball_set_pointer_dragscroll_enabled(bool enable) {
    g_keyball_config.is_dragscroll_enabled = enable;
    maybe_update_pointing_device_cpi(&g_keyball_config);
}

/**
 * \brief Augment the pointing device behavior.
 *
 * Implement drag-scroll.
 * Replaced Charybdis nano code with ploopy nano to get faster scrolling
 */
static void pointing_device_task_keyball(report_mouse_t* mouse_report) {

    if (g_keyball_config.is_dragscroll_enabled) {

        scroll_buffer_h += (float)mouse_report->x / KEYBALL_DRAGSCROLL_DIVISOR_H;
        scroll_buffer_v += (float)mouse_report->y / KEYBALL_DRAGSCROLL_DIVISOR_V;

#if defined(KEYBALL_DRAGSCROLL_REVERSE_X)
        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report->h = -(int8_t)scroll_buffer_h;
#else
        mouse_report->h = (int8_t)scroll_buffer_h;
#endif // KEYBALL_DRAGSCROLL_REVERSE_X

#if defined(KEYBALL_DRAGSCROLL_REVERSE_Y)
        mouse_report->v = -(int8_t)scroll_buffer_v;
#else
        mouse_report->v = (int8_t)scroll_buffer_v;
#endif // KEYBALL_DRAGSCROLL_REVERSE_Y

        // Update accumulated scroll values by subtracting the integer parts
        scroll_buffer_h -= (int8_t)scroll_buffer_h;
        scroll_buffer_v -= (int8_t)scroll_buffer_v;

        // Clear the X and Y values of the mouse report
        mouse_report->x = 0;
        mouse_report->y = 0;
    }
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (is_keyboard_master()) {
        pointing_device_task_keyball(&mouse_report);
        mouse_report = pointing_device_task_user(mouse_report);
    }
    return mouse_report;
}

#   if defined(POINTING_DEVICE_ENABLE) && !defined(NO_KEYBALL_KEYCODES)
static bool has_shift_mod(void) {
#       if defined(NO_ACTION_ONESHOT)
    return mod_config(get_mods()) & MOD_MASK_SHIFT;
#       else
    return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#       endif //NO_ACTION_ONESHOT
}
#   endif //POINTING_DEVICE_ENABLE && !NO_KEYBALL_KEYCODES

/**
 * \brief Outputs the keyball configuration to console.
 *
 * Prints the in-memory configuration structure to console, for debugging.
 * Includes:
 *   - raw value
 *   - drag-scroll: on/off
 *   - sniping: on/off
 *   - default DPI: internal table index/actual DPI
 *   - sniping DPI: internal table index/actual DPI
 */
static void debug_keyball_config_to_console(keyball_config_t* config) {
#   if defined(CONSOLE_ENABLE)
    dprintf("(keyball) process_record_kb: config = {\n"
            "\traw = 0x%X,\n"
            "\t{\n"
            "\t\tis_dragscroll_enabled=%u\n"
            "\t\tis_sniping_enabled=%u\n"
            "\t\tdefault_dpi=0x%X (%u)\n"
            "\t\tsniping_dpi=0x%X (%u)\n"
            "\t}\n"
            "}\n",
            config->raw, config->is_dragscroll_enabled, config->is_sniping_enabled, config->pointer_default_dpi, get_pointer_default_dpi(config), config->pointer_sniping_dpi, get_pointer_sniping_dpi(config));
#   endif //CONSOLE_ENABLE
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        debug_keyball_config_to_console(&g_keyball_config);
        return false;
    }
#   if defined(POINTING_DEVICE_ENABLE)
#       if !defined(NO_KEYBALL_KEYCODES)
    switch (keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                keyball_cycle_pointer_default_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_DEFAULT_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                keyball_cycle_pointer_default_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                keyball_cycle_pointer_sniping_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                keyball_cycle_pointer_sniping_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case SNIPING_MODE:
            keyball_set_pointer_sniping_enabled(record->event.pressed);
            break;
        case SNIPING_MODE_TOGGLE:
            if (record->event.pressed) {
                keyball_set_pointer_sniping_enabled(!keyball_get_pointer_sniping_enabled());
            }
            break;
        case DRAGSCROLL_MODE:
            keyball_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DRAGSCROLL_MODE_TOGGLE:
            if (record->event.pressed) {
                keyball_set_pointer_dragscroll_enabled(!keyball_get_pointer_dragscroll_enabled());
            }
            break;
    }
#       endif //!NO_KEYBALL_KEYCODES
#   endif     //POINTING_DEVICE_ENABLE
    if (IS_QK_KB(keycode) || IS_MOUSEKEY(keycode)) {
        debug_keyball_config_to_console(&g_keyball_config);
    }
    return true;
}

void eeconfig_init_kb(void) {
    g_keyball_config.raw = 0;
    write_keyball_config_to_eeprom(&g_keyball_config);
    maybe_update_pointing_device_cpi(&g_keyball_config);
    eeconfig_init_user();
}

void matrix_init_kb(void) {
    read_keyball_config_from_eeprom(&g_keyball_config);
    matrix_init_user();
}

#   if defined(KEYBALL_CONFIG_SYNC)
void KEYBALL_CONFIG_SYNC_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(g_keyball_config)) {
        memcpy(&g_keyball_config, initiator2target_buffer, sizeof(g_keyball_config));
    }
}
#   endif

void keyboard_post_init_kb(void) {
    maybe_update_pointing_device_cpi(&g_keyball_config);
#   if defined(KEYBALL_CONFIG_SYNC)
    transaction_register_rpc(RPC_ID_KB_CONFIG_SYNC, KEYBALL_CONFIG_SYNC_handler);
#   endif
    keyboard_post_init_user();
}

#   if defined(KEYBALL_CONFIG_SYNC)
void housekeeping_task_kb(void) {
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave.
        static keyball_config_t last_keyball_config = {0};
        static uint32_t           last_sync             = 0;
        bool                      needs_sync            = false;

        // Check if the state values are different.
        if (memcmp(&g_keyball_config, &last_keyball_config, sizeof(g_keyball_config))) {
            needs_sync = true;
            memcpy(&last_keyball_config, &g_keyball_config, sizeof(g_keyball_config));
        }
        // Send to slave every 500ms regardless of state change.
        if (timer_elapsed32(last_sync) > 500) {
            needs_sync = true;
        }

        // Perform the sync if requested.
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_KB_CONFIG_SYNC, sizeof(g_keyball_config), &g_keyball_config)) {
                last_sync = timer_read32();
            }
        }
    }
    // No need to invoke the user-specific callback, as it's been called
    // already.
}
#   endif //KEYBALL_CONFIG_SYNC
#endif    //POINTING_DEVICE_ENABLE

#if defined(OLED_ENABLE)

static const char PROGMEM qmk_logo[384+1] = { // 128x24
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0xF0, 0xF8, 0xF8, 0xFF, 0x38, 0xFF, 0xF8, 0xF8, 0x3F, 0xF8, 0xF8, 0xFF, 0x38, 0xFF, 0xF8, 0xF8, 0xF0, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x49, 0x49, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xDF, 0xBF, 0xBF, 0x00, 0xBF, 0xBF, 0xDF, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x60, 0x60, 0xE0, 0xBF, 0x1F, 0x00, 0x7F, 0x7F, 0x07, 0x1E, 0x38, 0x1E, 0x07, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x0E, 0x1F, 0x3B, 0x71, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x0C, 0x0C, 0x0C, 0x00, 0x7E, 0x7E, 0x00, 0x7F, 0x7E, 0x03, 0x03, 0x00, 0x7F, 0x7E, 0x03, 0x03, 0x7E, 0x7E, 0x03, 0x03, 0x7F, 0x7E, 0x00, 0x0F, 0x3E, 0x70, 0x3C, 0x06, 0x3C, 0x70, 0x3E, 0x0F, 0x00, 0x32, 0x7B, 0x49, 0x49, 0x3F, 0x7E, 0x00, 0x7F, 0x7E, 0x03, 0x03, 0x00, 0x1E, 0x3F, 0x69, 0x69, 0x6F, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x07, 0x0F, 0x0F, 0x7F, 0x0F, 0x7F, 0x0F, 0x0F, 0x7E, 0x0F, 0x0F, 0x7F, 0x0F, 0x7F, 0x0F, 0x0F, 0x07, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }

    if (is_keyboard_master()) {
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    } else {
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }
    return false;
}

#endif // OLED_ENABLE

bool shutdown_kb(bool jump_to_bootloader) {
    if (!shutdown_user(jump_to_bootloader)) {
        return false;
    }

#if defined(RGB_MATRIX_ENABLE)
    void rgb_matrix_update_pwm_buffers(void);
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif //RGB_MATRIX_ENABLE
    return true;
}
