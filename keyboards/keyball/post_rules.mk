VALID_KEYBALL_CONFIG := right_ball left_ball dual_ball no_ball

ifeq ($(filter $(KEYBALL_CONFIG),$(VALID_KEYBALL_CONFIG)),)
    $(call CATASTROPHIC_ERROR,Invalid KEYBALL_LAYOUT,KEYBALL_LAYOUT="$(KEYBALL_CONFIG)" is not a valid KEYBALL Layout)
else
    OPT_DEFS += -DKLOR_$(strip $(shell echo $(KEYBALL_CONFIG) | tr '[:lower:]' '[:upper:]'))
endif
