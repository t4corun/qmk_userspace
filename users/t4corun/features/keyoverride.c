#include "keyoverride.h"

/* 
Key Override
 Here we will override some shifted versions of keys
 https://docs.qmk.fm/#/feature_key_overrides?id=simple-example

Intentionally did not convert all the override/autoshit tap holds to this format
- Here I could type faster and be able to hold to repeat the keycodes however
- I had tons of same finger bigrams doing trying to get ~ and :
- I didn't feel the need to be able to repeat those symbols
*/

const key_override_t comma_override         = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_QUES, ~(1 << _QWERTY));
const key_override_t dot_override           = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_EXLM, ~(1 << _QWERTY));
const key_override_t graphitecomma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_EXLM, ~(1 << _GRAPHITE));
const key_override_t graphitedot_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_QUES, ~(1 << _GRAPHITE));


const key_override_t *key_overrides[] = {
    &comma_override,
    &dot_override,
    &graphitecomma_override,
    &graphitedot_override
};