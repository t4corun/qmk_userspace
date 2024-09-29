VALID_OLED_SIZE := 128x32 128x64

ifeq ($(strip $(OLED_ENABLE)), yes)
	ifeq ($(filter $(OLED_SIZE),$(VALID_OLED_SIZE)),)
    	$(call CATASTROPHIC_ERROR,Invalid OLED_SIZE,OLED_SIZE="$(OLED_SIZE)" is not a valid OLED screen size)
	else
    	OPT_DEFS += -DOLED_SIZE_$(strip $(shell echo $(OLED_SIZE) | tr '[:lower:]' '[:upper:]'))
	endif
endif
