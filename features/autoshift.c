#include "autoshift.h"

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        default:
            return AUTO_SHIFT_TIMEOUT;
    }
}