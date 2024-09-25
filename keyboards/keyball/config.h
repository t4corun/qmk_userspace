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

#define MASTER_RIGHT

#if defined(POINTING_DEVICE_ENABLE)
// SPI & PMW3360 settings
#   define SPI_DRIVER SPID0
#   define SPI_SCK_PIN GP22
#   define SPI_MISO_PIN GP20
#   define SPI_MOSI_PIN GP23
#   define PMW3360_CS_PIN GP21
// pointer settings
#   define SPLIT_POINTING_ENABLE
#   define POINTING_DEVICE_RIGHT
// These two configuration changes allow intuitive
// pointer movement given the sensor placement
#   define ROTATIONAL_TRANSFORM_ANGLE -90
// I wonder if this will work
///#    define POINTING_DEVICE_ROTATION_270
#   define POINTING_DEVICE_INVERT_X
// allow intuitive drag scroll movement
#   define KEYBALL_DRAGSCROLL_REVERSE_Y
#endif //POINTING_DEVICE_ENABLE
