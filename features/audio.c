#include "audio.h"
#include "muse.h"

layer_state_t layer_state_set_audio(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _NUMBER:
      stop_all_notes();
      PLAY_SONG(lower_song);
      break;
    case _NAVIGATION:
      stop_all_notes();
      PLAY_SONG(default_sound);
      break;
    case _SYMBOL:
      stop_all_notes();
      PLAY_SONG(fn_song);
      break;
    case _MOUSE:
      stop_all_notes();
      PLAY_SONG(default_sound);
      break;
    case _CONFIG:
      stop_all_notes();
      PLAY_SONG(adjust_song);
      break;
    default:
      stop_all_notes();
      PLAY_SONG(default_sound);
      break;
    }
  return state;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    //add all the keys that would be on your base layer that are not defaults. If we don't do this then the sounds do not play
    //Layer Taps do add delays to sounds. Probably the mod Taps too
    case NAV:
    case SYM:
    case MOUSE:
    case TR_REP:
    case TR_COMM:
    case TR_DOT:
    case TR_BTN1:
      return false;
    default:
      return true;
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_muse(void) {
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
}