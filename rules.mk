SRC += \
	t4corun.c \
	features/tapping.c

# default settings across all keyboards
# ?= means set the value if its not defined elsewhere
# this way we can build firmware for new keyboards

LTO_ENABLE ?= yes
MAGIC_ENABLE ?= no
CONSOLE_ENABLE ?= no
UNICODE_ENABLE ?= no
SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no

DYNAMIC_MACRO_ENABLE ?= yes
REPEAT_KEY_ENABLE ?= yes
ONESHOT_ENABLE ?= yes
AUTO_SHIFT_ENABLE ?= yes
CAPS_WORD_ENABLE ?= yes
OLED_ENABLE ?= no
COMBO_ENABLE ?= yes
TAPHOLD_ENABLE ?= yes	
POINTING_DEVICE_ENABLE ?= no 
AUTOMOUSE_ENABLE ?= no
MOUSEKEY_ENABLE ?= no
RGB_MATRIX_ENABLE ?= no
GAMELAYER_ENABLE ?= no

#keyboard specific settings to override my defaults or keyboard specific rules.mk
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
	GAMELAYER_ENABLE = yes
	RGB_MATRIX_ENABLE = no

# qmk_firmware\keyboards\bastardkb\charybdis\3x5\v2\splinky_3\rules.mk
endif

ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += features/autoshift.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/capsword.c
endif