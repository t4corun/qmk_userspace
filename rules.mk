SRC += \
	t4corun.c \
	features/tapping.c

# default settings across all keyboards
# ?= means set the value if its not defined elsewhere
# writen this way so we can use this in a local build environment 
# build firmware for other keyboards
SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no
DYNAMIC_MACRO_ENABLE ?= yes
LTO_ENABLE ?= yes
MAGIC_ENABLE ?= no
REPEAT_KEY_ENABLE ?= yes

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
ONESHOT_ENABLE ?= yes



#keyboard specific settings to override my defaults or keyboard specific rules.mk
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
	GAMELAYER_ENABLE = yes

# qmk_firmware\keyboards\bastardkb\charybdis\3x5\v2\splinky_3\rules.mk
endif


ifeq ($(KEYBOARD), crkbd/rev1)
	DYNAMIC_MACRO_ENABLE = no
	RGB_MATRIX_ENABLE = no
	RGBLIGHT_ENABLE = no


# qmk_firmware\keyboards\crkbd\rev1\rules.mk
# qmk_firmware\keyboards\crkbd\rules.mk
# qmk_firmware\keyboards\crkbd\info.json

endif


ifeq ($(KEYBOARD), planck\rev6)
	COMMAND_ENABLE = no
	ENCODER_ENABLE = no
	DIP_SWITCH_ENABLE = no
	AUDIO_ENABLE = no

# qmk_firmware\keyboards\planck\rev6\rules.mk
endif




ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += features/autoshift.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/capsword.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += features/oled.c
endif

#might need to be INTROSPECTION_KEYMAP_C = $(USER_PATH)/features/combo.c
ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C = features/combo.c
endif

ifeq ($(strip $(ONESHOT_ENABLE)), yes)
	OPT_DEFS += -DONESHOT_ENABLE
endif

#TAPHOLD_ENABLE is custom
ifeq ($(strip $(TAPHOLD_ENABLE)), yes)
	SRC += features/taphold.c
	OPT_DEFS += -DTAPHOLD_ENABLE
endif

#AUTOMOUSE_ENABLE is custom
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	SRC += features/mouse.c
	OPT_DEFS += -DMOUSELAYER_ENABLE
	ifeq ($(strip $(AUTOMOUSE_ENABLED)), yes)
	  OPT_DEFS += -DAUTOMOUSE_ENABLE
	endif
endif

ifeq ($(strip $(MOUSEKEY_ENABLE)), yes)
	OPT_DEFS += -DMOUSELAYER_ENABLE
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += features/rgbmatrix.c
endif

ifeq ($(strip $(GAMELAYER_ENABLE)), yes)
	OPT_DEFS += -DGAMELAYER_ENABLE
endif