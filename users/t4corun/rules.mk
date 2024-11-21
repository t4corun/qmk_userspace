# Set build options for
# - consistent configuration across all keyboards
# - enable features specific to certain board (e.g. encoders, rgb, oled)
# - a way to save memory on MCU

# ---------------------------------------------------------
# set defaults on these qmk features if not defined
# in the individual keyboard rules.mk
#
# ?= means set the value if its not defined elsewhere


# optional features
# use these values if not defined at the keyboard level
BOOTMAGIC_ENABLE       ?= yes
CAPS_WORD_ENABLE       ?= yes
COMBO_ENABLE           ?= no
DYNAMIC_MACRO_ENABLE   ?= yes
EXTRAKEY_ENABLE         = yes

AUDIO_ENABLE           ?= no
CONSOLE_ENABLE         ?= no
COMMAND_ENABLE         ?= no
ENCODER_ENABLE         ?= no
ENCODER_MAP_ENABLE     ?= no
GRAVE_ESC_ENABLE       ?= no
HAPTIC_ENABLE          ?= no
MOUSEKEY_ENABLE        ?= no
OLED_ENABLE            ?= no
POINTING_DEVICE_ENABLE ?= no
RGB_MATRIX_ENABLE      ?= no
RGBLIGHT_ENABLE        ?= no
SPACE_CADET_ENABLE     ?= no
UNICODE_ENABLE         ?= no

# custom definitions
OLED_SIZE              ?= 128x32
PLOOPYNANO_ENABLE      ?= no

# ---------------------------------------------------------
# include my code that will be common across all my keyboards

SRC +=                   \
    t4corun.c            \
    features/achordion.c \
    features/taphold.c   \


# ---------------------------------------------------------
# include additional code for enabled features for each keyboard

ifeq ($(strip $(COMBO_ENABLE)), yes)
    INTROSPECTION_KEYMAP_C += features/combo.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += features/capsword.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    ifeq ($(strip $(OLED_SIZE)), 128x64)
        SRC += features/oled/oled_128x64.c
    else
        SRC += features/oled/oled.c
    endif
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += features/encoder.c
endif

ifeq ($(strip $(PLOOPYNANO_ENABLE)), yes)
    OPT_DEFS        += -DPLOOPYNANO_ENABLE
    SRC             += features/ploopynano.c
    MOUSEKEY_ENABLE  = yes
endif

