#pragma once

#include "quantum/quantum_keycodes.h"

enum keycodes {
  QWERTY = SAFE_RANGE,
  CLMAKDH,
  GAMING,

  //These are only here to make the case statements unique in taphold.c
  TH_LBRC,
  TH_LABK,
  TH_SQUO,
  TH_DQUO,
  TH_LPRN,
  TH_PERC,
  TH_COMM,
  TH_DOT  
};

#define ___x___ KC_NO