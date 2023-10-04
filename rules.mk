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
COMBO_ENABLE ?= yes
REPEAT_KEY_ENABLE ?= yes
DYNAMIC_MACRO_ENABLE ?= yes
RGB_MATRIX_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
MOUSEKEY_ENABLE ?= no
POINTING_DEVICE_ENABLE ?= no
OLED_ENABLE ?= no
AUDIO_ENABLE ?= no

ONESHOT_ENABLE ?= yes
TAPHOLD_ENABLE ?= yes
AUTOMOUSE_ENABLE ?= no
GAMELAYER_ENABLE ?= no

#keyboard specific settings to override my defaults or keyboard specific rules.mk
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
#	qmk_firmware\keyboards\bastardkb\charybdis\3x5\v2\splinky_3\rules.mk

	GAMELAYER_ENABLE = yes
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

	GAMELAYER_ENABLE = yes
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = yes
	ENCODER_ENABLE = no
	DIP_SWITCH_ENABLE = no
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

ifeq ($(strip $(MOUSEKEY_ENABLE)), yes)
	OPT_DEFS += -DMOUSELAYER_ENABLE
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += features/oled.c
endif

ifeq ($(strip $(AUDIO_ENABLE)), yes)
	SRC += features/audio.c
	SRC += muse.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += features/combo.c
endif

# ONESHOT_ENABLE is custom
ifeq ($(strip $(ONESHOT_ENABLE)), yes)
	OPT_DEFS += -DONESHOT_ENABLE
endif

# TAPHOLD_ENABLE is custom
ifeq ($(strip $(TAPHOLD_ENABLE)), yes)
	SRC += features/taphold.c
	OPT_DEFS += -DTAPHOLD_ENABLE
endif

# AUTOMOUSE_ENABLE is custom
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	SRC += features/mouse.c
	OPT_DEFS += -DMOUSELAYER_ENABLE
	ifeq ($(strip $(AUTOMOUSE_ENABLED)), yes)
	  OPT_DEFS += -DAUTOMOUSE_ENABLE
	endif
endif

# GAMELAYER_ENABLE is custom
ifeq ($(strip $(GAMELAYER_ENABLE)), yes)
	OPT_DEFS += -DGAMELAYER_ENABLE
endif