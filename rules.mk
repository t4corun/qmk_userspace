SRC += \
	t4corun.c \
	features/tapping.c

#common settings across all keyboards
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
LTO_ENABLE = yes
MAGIC_ENABLE = no
REPEAT_KEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE = yes
TAPHOLD_ENABLE = yes


#keyboard specific settings
ifeq ($(KEYBOARD), bastardkb/charybdis/3x5/v2/splinky_3)
endif

ifeq ($(KEYBOARD), crkbd/rev1)
endif





ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += features/autoshift.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/capsword.c
endif