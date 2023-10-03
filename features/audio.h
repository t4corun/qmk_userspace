#pragma once
#include "t4corun.h"

float plover_song[][2]     	= SONG(PLOVER_SOUND);
float plover_gb_song[][2]  	= SONG(PLOVER_GOODBYE_SOUND);
float lower_song[][2]  		= SONG(CAPS_LOCK_ON_SOUND);
float raise_song[][2]  		= SONG(NUM_LOCK_ON_SOUND);
float fn_song[][2]  		= SONG(SCROLL_LOCK_ON_SOUND);
float adjust_song[][2]  	= SONG(UNICODE_WINDOWS);
float default_sound[][2]  	= SONG(AG_NORM_SOUND);

layer_state_t layer_state_set_audio(layer_state_t state);
void matrix_scan_muse(void);