/*
This file exists because you cannot have multiple INTROSPECTION_KEYMAP_C in rules.mk

This approach is better than having a decision tree in the make file that may balloon with more features

*/

#if defined(COMBO_ENABLE)
    #include "combo.c"
#endif //COMBO_ENABLE

#if defined(KEY_OVERRIDE_ENABLE)
    #include "keyoverride.c"
#endif //KEY_OVERRIDE_ENABLE