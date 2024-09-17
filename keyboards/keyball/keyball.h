/*
Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
Copyright 2022 @Yowkees
Copyright 2024 t4corun (@t4corun)

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

#pragma once

#include "quantum.h"

#if defined(POINTING_DEVICE_ENABLE)
#   undef KEYBALL_MINIMUM_DEFAULT_DPI
#   undef KEYBALL_DEFAULT_DPI_CONFIG_STEP
#   undef KEYBALL_MINIMUM_SNIPING_DPI
#   undef KEYBALL_SNIPING_DPI_CONFIG_STEP
#   undef KEYBALL_DRAGSCROLL_DPI
#   undef KEYBALL_DRAGSCROLL_BUFFER_SIZE

#   define KEYBALL_MINIMUM_DEFAULT_DPI 400
#   define KEYBALL_DEFAULT_DPI_CONFIG_STEP 200
#   define KEYBALL_MINIMUM_SNIPING_DPI 200
#   define KEYBALL_SNIPING_DPI_CONFIG_STEP 100
#   define KEYBALL_DRAGSCROLL_DPI 100
#   define KEYBALL_DRAGSCROLL_BUFFER_SIZE 6

#   if !defined(NO_KEYBALL_KEYCODES)
enum charybdis_keycodes {
    POINTER_DEFAULT_DPI_FORWARD = QK_KB_0,
    POINTER_DEFAULT_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD,
    POINTER_SNIPING_DPI_REVERSE,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
};

#       define DPI_MOD  POINTER_DEFAULT_DPI_FORWARD
#       define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#       define S_D_MOD  POINTER_SNIPING_DPI_FORWARD
#       define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#       define SNIPING  SNIPING_MODE
#       define SNP_TOG  SNIPING_MODE_TOGGLE
#       define DRGSCRL  DRAGSCROLL_MODE
#       define DRG_TOG  DRAGSCROLL_MODE_TOGGLE
#   endif // !NO_KEYBALL_KEYCODES
#endif //POINTING_DEVICE_ENABLE
