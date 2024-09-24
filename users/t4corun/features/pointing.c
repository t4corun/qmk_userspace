#include "pointing.h"

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_keyball)
        case TR_SNIP:
        case TR_DRGS:
            return true;
#endif // KEYBOARD_bastardkb_charybdis_3x5 && KEYBOARD_keyball
        default:
            return false;
    }
}
