#include "t4corun.h"

layer_state_t  layer_state_set_user(layer_state_t  state) {
 
#if defined(AUDIO_ENABLE)
  state = layer_state_set_audio( update_tri_layer_state(state, _SYMBOL, _NAVIGATION, _NUMBER) );
#else
  state = update_tri_layer_state(state, _SYMBOL, _NAVIGATION, _NUMBER);
#endif
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

  case QWERTY:
    if (record->event.pressed) { default_layer_set(1UL<<_QWERTY); }
    return false;

  case CLMAKDH:
    if (record->event.pressed) { default_layer_set(1UL<<_COLEMAK_DH); }
    return false;

  case GAMING:
    if (record->event.pressed) { default_layer_set(1UL<<_GAMING); }
    return false;

  //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
  //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
  //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
  case TR_LBRC:
  case TR_LABK:
  case TR_LPRN:
  case TR_PERC:
  case TR_COMM:
  case TR_DOT:
    return process_tap_hold_key(record, keycode);


  }
  return true;
}

void matrix_scan_user(void) {

#if defined(AUDIO_ENABLE)
  matrix_scan_muse();
#endif

}