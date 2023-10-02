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
RGB_MATRIX_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
TAPHOLD_ENABLE ?= yes

#keyboard specific settings to override my defaults or keyboard specific rules.mk
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
#	qmk_firmware\keyboards\bastardkb\charybdis\3x5\v2\splinky_3\rules.mk

	GAMELAYER_ENABLE = yes
	RGB_MATRIX_ENABLE = no


endif


ifeq ($(KEYBOARD), crkbd/rev1)
# 	qmk_firmware\keyboards\crkbd\rev1\rules.mk
# 	qmk_firmware\keyboards\crkbd\rules.mk
# 	qmk_firmware\keyboards\crkbd\info.json

	DYNAMIC_MACRO_ENABLE = no
	RGB_MATRIX_ENABLE = no
	RGBLIGHT_ENABLE = no
endif


ifeq ($(KEYBOARD), planck\rev6)
#	qmk_firmware\keyboards\planck\rev6\rules.mk

	ENCODER_ENABLE = no
	DIP_SWITCH_ENABLE = no
	AUDIO_ENABLE = no
endif


ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += features/autoshift.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/capsword.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += features/rgbmatrix.c
endif


#TAPHOLD_ENABLE is custom
ifeq ($(strip $(TAPHOLD_ENABLE)), yes)
	SRC += features/taphold.c
	OPT_DEFS += -DTAPHOLD_ENABLE
endif