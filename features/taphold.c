#include "taphold.h"

void insert_brackets(uint16_t left, uint16_t right) {
  tap_code16(left);
  tap_code16(right);
  tap_code16(KC_LEFT);
}


//here we can have the holds be more complex, like sending "" when you hold "
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode) {

  //tap is record->tap.count && record->event.pressed
  //hold is record->event.pressed

  bool isShift = ( (get_mods() & MOD_BIT(KC_LSFT)) || (get_oneshot_mods() & MOD_BIT(KC_LSFT)) );
  uint16_t key = KC_NO;
  uint16_t altkey = KC_NO;

  switch(keycode) {

    //Brackets
    case TR_LBRC:
      key = KC_LBRC;
      altkey = KC_RBRC;
      break;
    case TR_LABK:
      key = KC_LABK;
      altkey = KC_RABK;
      break;

    //Custom
    case TR_LPRN: //this and the below both tap for comma, but this holds for closed parenthesis on the symbol layer
    case TR_COMM: //this hold for a single ( on the base layer. for reducing excel errors
      key = KC_COMM; 
      altkey = KC_LPRN;
      break;
    case TR_PERC: //combining seldom used % and ^ to make room for momentary mouse on symbol layer
      key = KC_PERC; 
      altkey = KC_CIRC;
      break;
    case TR_DOT: 
      key = KC_DOT;
      altkey = KC_RPRN;
      break;
  }


  if (record->tap.count && record->event.pressed) {

    tap_code16(key);
    return false;

  } else if (record->tap.count == 0 && record->event.pressed) {

    switch(keycode) {

      //Brackets
      case TR_LBRC:
      case TR_LABK:
        isShift ? insert_brackets(LSFT(key), LSFT(altkey)) : insert_brackets(key, altkey);
        break;
      
      //custom
      case TR_LPRN:
        insert_brackets(KC_LPRN, KC_RPRN);
        break;
      case TR_PERC:  
      case TR_COMM:
      case TR_DOT:
        tap_code16(altkey);
        break;
    }

    return false;
  }

  return true;  // Continue default handling.
}