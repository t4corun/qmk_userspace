#pragma once
#include "t4corun.h"

extern const float lower_song[][2]  		= SONG(CAPS_LOCK_ON_SOUND);
extern const float default_sound[][2]  	= SONG(AG_NORM_SOUND);
extern const float fn_song[][2]  		    = SONG(SCROLL_LOCK_ON_SOUND);
extern const float adjust_song[][2]  	  = SONG(UNICODE_WINDOWS);

layer_state_t layer_state_set_audio(layer_state_t state);
void matrix_scan_muse(void);