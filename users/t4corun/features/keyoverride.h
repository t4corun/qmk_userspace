#pragma once

#include "t4corun.h"

const key_override_t num1_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_1,    KC_F1,   ~_NUMBER);
const key_override_t num2_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_2,    KC_F2,   ~_NUMBER);
const key_override_t num3_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_3,    KC_F3,   ~_NUMBER);
const key_override_t num4_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_4,    KC_F4,   ~_NUMBER);
const key_override_t num5_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_5,    KC_F5,   ~_NUMBER);
const key_override_t num6_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_6,    KC_F6,   ~_NUMBER);
const key_override_t num7_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_7,    KC_F7,   ~_NUMBER);
const key_override_t num8_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_8,    KC_F8,   ~_NUMBER);
const key_override_t num9_override       = ko_make_with_layers(MOD_MASK_CSA,   KC_9,    KC_F9,   ~_NUMBER);
const key_override_t num_comma_override  = ko_make_with_layers(MOD_MASK_CSA,   KC_COMM, KC_F10,  ~_NUMBER);
const key_override_t num_dot_override    = ko_make_with_layers(MOD_MASK_CSA,   KC_DOT,  KC_F11,  ~_NUMBER);
const key_override_t num_mins_override   = ko_make_with_layers(MOD_MASK_CSA,   KC_MINS, KC_F12,  ~_NUMBER);

const key_override_t base_comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_EXLM, ~FIRST_DEFAULT_LAYER);
const key_override_t base_dot_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_QUES, ~FIRST_DEFAULT_LAYER);


const key_override_t *key_overrides[] = {
    &num1_override,
    &num2_override,
    &num3_override,
    &num4_override,
    &num5_override,
    &num6_override,
    &num7_override,
    &num8_override,
    &num9_override,
    &num_comma_override,
    &num_dot_override,
    &num_mins_override,

    &base_comma_override,
    &base_dot_override
};