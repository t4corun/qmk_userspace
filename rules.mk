SRC += T4CORUN.c
SRC += $(USER_PATH)/features/tapping.c

INTROSPECTION_KEYMAP_C = T4CORUN.c

SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no
DYNAMIC_MACRO_ENABLE ?= yes
LTO_ENABLE ?= yes
MAGIC_ENABLE ?= no
REPEAT_KEY_ENABLE ?= yes


AUTO_SHIFT_ENABLE ?= yes
ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += $(USER_PATH)/features/autoshift.c
endif

CAPS_WORD_ENABLE ?= yes
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += $(USER_PATH)/features/capsword.c
endif

OLED_ENABLE ?= no
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += $(USER_PATH)/features/oled.c
endif


COMBO_ENABLE ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
#	SRC += $(USER_PATH)/combo.c
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/features/combo.c
endif

#TAPHOLD_ENABLE is custom
TAPHOLD_ENABLE ?= yes
ifeq ($(strip $(TAPHOLD_ENABLE)), yes)
	SRC += $(USER_PATH)/features/taphold.c
	OPT_DEFS += -DTAPHOLD_ENABLE
endif

#AUTOMOUSE_ENABLE is custom
POINTING_DEVICE_ENABLE ?= no
AUTOMOUSE_ENABLE ?= no
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/mouse.c
	OPT_DEFS += -DMOUSELAYER_ENABLE
	ifeq ($(strip $(AUTOMOUSE_ENABLED)), yes)
	  OPT_DEFS += -DAUTOMOUSE_ENABLE
	endif
endif

MOUSEKEY_ENABLE ?= no
ifeq ($(strip $(MOUSEKEY_ENABLE)), yes)
	OPT_DEFS += -DMOUSELAYER_ENABLE
endif

RGB_MATRIX_ENABLE ?= no
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += $(USER_PATH)/features/rgbmatrix.c
endif

#GAMING_ENABLED is custom
GAMELAYER_ENABLE ?= no
ifeq ($(strip $(GAMELAYER_ENABLE)), yes)
	OPT_DEFS += -DGAMELAYER_ENABLE
endif

#ONESHOT_ENABLED is custom
ONESHOT_ENABLE ?= yes
ifeq ($(strip $(ONESHOT_ENABLE)), yes)
	OPT_DEFS += -DONESHOT_ENABLE
endif
