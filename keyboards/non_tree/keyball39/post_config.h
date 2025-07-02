/* Copyright 2012 Jun Wako <wakojun@gmail.com>
 * Copyright 2015 Jack Humbert
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2024 t4corun
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

// Enable syncing of charybdis config
#if defined(KEYBALL_CONFIG_SYNC)
#   define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
#endif

/* Mouse scroll config. */

#ifndef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 15
#endif // !MOUSEKEY_WHEEL_DELAY

#ifndef MOUSEKEY_WHEEL_DELTA
#    define MOUSEKEY_WHEEL_DELTA 1
#endif // !MOUSEKEY_WHEEL_DELTA

#ifndef MOUSEKEY_WHEEL_INTERVAL
#    define MOUSEKEY_WHEEL_INTERVAL 50
#endif // !MOUSEKEY_WHEEL_INTERVAL

#ifndef MOUSEKEY_WHEEL_MAX_SPEED
#    define MOUSEKEY_WHEEL_MAX_SPEED 8
#endif // !MOUSEKEY_WHEEL_MAX_SPEED

#ifndef MOUSEKEY_WHEEL_TIME_TO_MAX
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 80
#endif // !MOUSEKEY_WHEEL_TIME_TO_MAX

#ifndef MOUSEKEY_WHEEL_INITIAL_MOVEMENTS
#    define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 8
#endif // !MOUSEKEY_WHEEL_INITIAL_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_BASE_MOVEMENTS
#    define MOUSEKEY_WHEEL_BASE_MOVEMENTS 48
#endif // !MOUSEKEY_WHEEL_BASE_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS
#    define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#endif // !MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS

#ifndef MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS
#    define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#endif // !MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS