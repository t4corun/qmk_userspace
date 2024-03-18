SRC += \
	t4corun.c \
	features/tapping.c \
	features/capsword.c \
	features/taphold.c 

# default settings across all keyboards
# ?= means set the value if its not defined elsewhere
# this way we can build firmware for new keyboards

LTO_ENABLE ?= yes
MAGIC_ENABLE ?= no
CONSOLE_ENABLE ?= no
UNICODE_ENABLE ?= no
SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no

# qmk features we will force
AUDIO_ENABLE = no
CAPS_WORD_ENABLE = yes

COMBO_ENABLE ?= yes
DYNAMIC_MACRO_ENABLE ?= yes
RGB_MATRIX_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
MOUSEKEY_ENABLE ?= no
POINTING_DEVICE_ENABLE ?= no
OLED_ENABLE ?= no

#keyboard specific settings to override my defaults or keyboard specific rules.mk
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
#	qmk_firmware\keyboards\bastardkb\charybdis\3x5\v2\splinky_3\rules.mk
endif


ifeq ($(KEYBOARD), crkbd/rev1)
# 	qmk_firmware\keyboards\crkbd\rev1\rules.mk
# 	qmk_firmware\keyboards\crkbd\rules.mk
# 	qmk_firmware\keyboards\crkbd\info.json
	OLED_DRIVER = ssd1306

	OLED_ENABLE = yes
	MOUSEKEY_ENABLE = yes

	DYNAMIC_MACRO_ENABLE = no
	COMBO_ENABLE = no
	RGB_MATRIX_ENABLE = no
	RGBLIGHT_ENABLE = no
endif


ifeq ($(KEYBOARD), planck/rev6)
#	qmk_firmware\keyboards\planck\rev6\rules.mk
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = no
	ENCODER_ENABLE = no
	DIP_SWITCH_ENABLE = no
endif

ifeq ($(KEYBOARD), ploopyco/trackball_nano)
#	qmk_firmware\keyboards\ploopyco\trackball_nano\rules.mk
	CAPS_WORD_ENABLE = no
	DYNAMIC_MACRO_ENABLE = no
	COMBO_ENABLE = no
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

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += features/combo.c
endif

# AUTOMOUSE_ENABLE is custom
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	SRC += features/mouse.c
	OPT_DEFS += -DMOUSELAYER_ENABLE
endif