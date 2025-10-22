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

#pragma once

#if defined(OLED_ENABLE)
#   define OLED_KEYBOARD_NAME "KLOR Saegewerk"
#endif // OLED_ENABLE

#if defined(HAPTIC_ENABLE) && defined(HAPTIC_DRV2605L)
#   define DRV2605L_GREETING     DRV2605L_EFFECT_750_MS_ALERT_100
#   define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_STRONG_CLICK_1_100
#endif // HAPTIC_ENABLE && HAPTIC_DRV2605L