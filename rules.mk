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


AUTO_SHIFT_ENABLE ?= yes
CAPS_WORD_ENABLE ?= yes

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