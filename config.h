#pragma once

//Turn off settings we won't use to save memory
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

//Clear variables we plan to use that might be set elsewhere
#undef USB_POLLING_INTERVAL_MS

//Set common configuration for all keyboards
#define USB_POLLING_INTERVAL_MS 1

#if !defined(__ASSEMBLER__)
#   include "_layers.h"
#   include "_keycodes.h"
#endif

#include "_layouts.h"
#include "config/tapping_config.h"
#include "config/capsword_config.h"

#if defined(RGB_MATRIX_ENABLE)
#   include "config/rgbmatrix_config.h"
#endif

#if defined(MOUSELAYER_ENABLE)
#   include "config/mouse_config.h"
#endif

#if defined(COMBO_ENABLE)
#   include "config/combo_config.h"
#endif

#if defined(SPLIT_KEYBOARD)
#	include "config/split_config.h"
#endif

#if defined(KEYBOARD_bastardkb_charybdis_3x5)
#   define CHARYBDIS_CONFIG_SYNC
#endif