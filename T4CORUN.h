#pragma once
#include QMK_KEYBOARD_H

#if defined(TAPHOLD_ENABLE)
#   include "features/taphold.h"
#endif

//#include "wrappers.h"

//bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode);

/*
design principles
- go back to the base layer when no keys are held
- one shot mods
- caps word
- combos
- auto shift
- mouse emulation
- miryoku inpsiration ("Layers are designed orthogonally with a single purpose per hand and are accessed by holding a thumb key on the opposite hand.")
- 



_QWERTY
_NUMBER
_NAVIGATION
_SYMBOL
_MOUSE
_FUNCTION (one shot layer?)
_CONFIG )

enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,  
  _COLEMAK_DH,
  _GAMING,
  _NUMBER,
  _NAVIGATION,
  _SYMBOL,
  _MOUSE,
  _GAMENUMBER,
  _CONFIG
};

*/

enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,  
  _COLEMAK_DH,
  _GAMING,
  _NAVIGATION,
  _SYMBOL,
  _NUMBER,
  _MOUSE,
  _GAMENUMBER,
  _CONFIG
};

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

#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#define _DEFAULT_LAYER_3 (FIRST_DEFAULT_LAYER + 2)

#define ___x___ KC_NO

//momentary layer
//#define NAVGTIN    MO(_NAVIGATION)
#define NAV        MO(_NAVIGATION)
#define SYM        MO(_SYMBOL)
#define CONFIG     MO(_CONFIG)
#define MOUSE      MO(_MOUSE)
#define GAMENUM    MO(_GAMENUMBER)


//Windows Shortcuts
#define SC_COPY    LCTL(KC_C)
#define SC_CUT     LCTL(KC_X)
#define SC_UNDO    LCTL(KC_Z)
#define SC_PAST    LCTL(KC_V)
#define SC_REDO    LCTL(KC_Y)

/*
We will move all as many preprocessor directives here so the wrapper is easier to follow
- Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
- If the feature is disabled then the key is just the normal key
- Some keycodes are used in certain features, some features will override others
- We will only define things that are used across different layers. Entire layers are turned off in the keymap
*/

#if defined(ONESHOT_ENABLE)
#   define TR_LSFT OSM(MOD_LSFT)
#   define TR_LCTL OSM(MOD_LCTL)
#   define TR_LALT OSM(MOD_LALT)
#   define TR_LGUI OSM(MOD_LGUI)
#else
#   define TR_LSFT KC_LSFT
#   define TR_LCTL KC_LCTL
#   define TR_LALT KC_LALT
#   define TR_LGUI KC_LGUI
#endif //ONESHOT_ENABLE


#if defined(MOUSELAYER_ENABLE)
#   define MOUSE   MO(_MOUSE)
#   define TR_BTN1 KC_BTN1
#   define TR_BTN2 KC_BTN2
#   define TR_BTN3 KC_BTN3
#   define TR_BTN4 KC_BTN4
#   define TR_BTN5 KC_BTN5
#else
#   define MOUSE   ___x___
#   define TR_BTN1 ___x___
#   define TR_BTN2 ___x___
#   define TR_BTN3 ___x___
#   define TR_BTN4 ___x___
#   define TR_BTN5 ___x___
#endif //MOUSELAYER_ENABLE


#if defined(MOUSEKEY_ENABLE)
#   define TR_MOUU KC_MS_U
#   define TR_MOUD KC_MS_D
#   define TR_MOUL KC_MS_L
#   define TR_MOUR KC_MS_R
#   define TR_MWHU KC_WH_U
#   define TR_MWHD KC_WH_D

#else
#   define TR_MOUU ___x___
#   define TR_MOUD ___x___
#   define TR_MOUL ___x___
#   define TR_MOUR ___x___
#   define TR_MWHU ___x___
#   define TR_MWHD ___x___
#endif //MOUSEKEY_ENABLE


//these keycodes come from the cnano
#if defined(POINTING_DEVICE_ENABLE)
#   define TR_SNIP SNIPING
#   define TR_SNIT SNP_TOG
#   define TR_DRGS DRGSCRL
#   define TR_DRGT DRG_TOG
#   define TR_SDPI S_D_MOD
#   define TR_PDPI DPI_MOD
#else
#   define TR_SNIP ___x___
#   define TR_SNIT ___x___
#   define TR_DRGS ___x___
#   define TR_DRGT ___x___
#   define TR_SDPI ___x___
#   define TR_PDPI ___x___
#endif //POINTING_DEVICE_ENABLE


#if defined(GAMELAYER_ENABLE) 
#   define TR_GAME GAMING
#else
#   define TR_GAME ___x___
#endif //GAMELAYER_ENABLE


//For tap hold keys we will override the hold to issue alternate keystrokes rather than enable the layer
#if defined(TAPHOLD_ENABLE)
//Brackets
#   define TR_LBRC  LT(_DEFAULT_LAYER_1, TH_LBRC)
#   define TR_LABK  LT(_DEFAULT_LAYER_1, TH_LABK)
//Custom
#   define TR_LPRN  LT(_DEFAULT_LAYER_1, TH_LPRN)
#   define TR_PERC  LT(_DEFAULT_LAYER_1, TH_PERC)
#   define TR_COMM  LT(_DEFAULT_LAYER_1, TH_COMM)
#   define TR_DOT   LT(_DEFAULT_LAYER_1, TH_DOT)
#else
//Brackets
#   define TR_LBRC  KC_LBRC
#   define TR_LABK  KC_LABK
//Custom
#   define TR_LPRN  KC_LPRN
#   define TR_PERC  KC_PERC //TODO when tap hold is off typing ^ will not be possible
#   define TR_COMM  KC_COMM
#   define TR_DOT   KC_DOT
#endif //TAPHOLD_ENABLE

#if defined(DYNAMIC_MACRO_ENABLE)
#   define TR_DMR1 DM_REC1
#   define TR_DMP1 DM_PLY1
#   define TR_DMR2 DM_REC2
#   define TR_DMP2 DM_PLY2
#else
#   define TR_DMR1 ___x___
#   define TR_DMP1 ___x___
#   define TR_DMR2 ___x___
#   define TR_DMP2 ___x___
#endif //DYNAMIC_MACRO_ENABLE

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#   define TR_RHUI RGB_HUI
#   define TR_RSAI RGB_SAI
#   define TR_RVAI RGB_VAI
#   define TR_RSPI RGB_SPI
#   define TR_RTOG RGB_TOG
#   define TR_RMOD RGB_MOD
#else
#   define TR_RHUI ___x___
#   define TR_RSAI ___x___
#   define TR_RVAI ___x___
#   define TR_RSPI ___x___
#   define TR_RTOG ___x___
#   define TR_RMOD ___x___
#endif //RGB_MATRIX_ENABLE or RGBLIGHT_ENABLE

#if defined(REPEAT_KEY_ENABLE)
#   define TR_REP QK_REP
#else
#   define TR_REP TR_LSFT
#endif //REPEAT_KEY_ENABLE

#if defined(AUTO_SHIFT_ENABLE)
#   define TR_ASDN AS_DOWN
#   define TR_ASUP AS_UP
#   define TR_ASRP AS_RPT
#   define TR_ASTG AS_TOGG
#else
#   define TR_ASDN ___x___
#   define TR_ASUP ___x___
#   define TR_ASRP ___x___
#   define TR_ASTG ___x___
#endif //REPEAT_KEY_ENABLE


/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts


Modeled code after Drashna's Wrappers.
Definitions inspired by Miryoku (https://github.com/manna-harbour/miryoku). 

I added comment maps to better visualize the map. I intended to only 
show the definition once so its less comments to change when I change
a mapping

I prefer to use KC_NO over KC_TRNS so I don't have accidental presses.
*/

#   define __________________NONE_5___________________        ___x___, ___x___, ___x___, ___x___, ___x___
#   define _________________UCCPR_L___________________        SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#   define    _____________GACS_MODS____________              TR_LGUI, TR_LALT, TR_LCTL, TR_LSFT
#   define    _____________SCAG_MODS____________              TR_LSFT, TR_LCTL, TR_LALT, TR_LGUI

#   define         _________BASE_L4_________                  TR_BTN1, SYM,     MOUSE
#   define         _________TRANS_L4________                  ___x___, _______, ___x___

//right side only has two thumb keys
#if defined(KEYBOARD_bastardkb_charybdis_3x5)
#   define         _________BASE_R4_________                  KC_SPC,  NAV
#   define         _________TRANS_R4________                  ___x___, _______
#else
#   define         _________BASE_R4_________                  KC_SPC,  NAV,     ___x___
#   define         _________TRANS_R4________                  ___x___, _______, ___x___
#endif //KEYBOARD_bastardkb_charybdis_3x5



/*
*   ,----------------------------------.    ,----------------------------------.
*   | q    | w    | e    | r    | y    |    | y    | u    | i    | o    | p    |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | a    | s    | d    | f    | g    |    | h    | j    | k    | l    |repeat|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | z    | x    | c    | v    | b    |    | n    | m    | ,    | .    | -    |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 | mb1  | sym  | mou  |    |space | nav  |      |
*                 `------+------+------'    `------+------+------'
*
*/
#   define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#   define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#   define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#   define          ________QWERTY_L4________                 _________BASE_L4_________

#   define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#   define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    TR_REP
#   define _________________QWERTY_R3_________________        KC_N,    KC_M,    TR_COMM, TR_DOT,  KC_MINS
#   define          ________QWERTY_R4________                 _________BASE_R4_________


/*
* swapped O and ' on this keymap to keep repeat key in the same position across most layers
*
*   ,----------------------------------.    ,----------------------------------.
*   | q    | w    | f    | p    | b    |    | j    | l    | u    | y    | o    |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | a    | r    | s    | t    | g    |    | m    | n    | e    | i    |repeat|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | z    | x    | c    | d    | v    |    | k    | h    | ,    | .    | -    |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 | mb1  | sym  | mou  |    |space | nav  |      |
*                 `------+------+------'    `------+------+------'
*/
#   define ________________COLEMAKDH_L1_______________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#   define ________________COLEMAKDH_L2_______________        KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#   define ________________COLEMAKDH_L3_______________        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#   define          _______COLEMAKDH_L4______                 _________BASE_L4_________

#   define ________________COLEMAKDH_R1_______________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_O
#   define ________________COLEMAKDH_R2_______________        KC_M,    KC_N,    KC_E,    KC_I,    TR_REP
#   define ________________COLEMAKDH_R3_______________        KC_K,    KC_H,    TR_COMM, TR_DOT,  KC_MINS
#   define          _______COLEMAKDH_R4______                 _________BASE_R4_________

/*
*   ,----------------------------------.    ,----------------------------------.
*   | esc  | home | up   | end  | pgup |    |      | ins  |      |      |config|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |      | left | down | right| pgdn |    | bksp | shft | ctrl | alt  | gui  |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | undo | cut  | copy |paste | redo |    | del  | app  | vol- | vol+ | mute |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 | tab  | sym  |enter |    |      | nav  |      |
*                 `------+------+------'    `------+------+------'
*/
#   define ___________________NAV_L1__________________        KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP
#   define ___________________NAV_L2__________________        ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#   define ___________________NAV_L3__________________        _________________UCCPR_L___________________
#   define          __________NAV_L4_________                 KC_TAB,  _______, KC_ENT

#   define ___________________NAV_R1__________________        ___x___, KC_INS,  ___x___, ___x___, CONFIG
#   define ___________________NAV_R2__________________        KC_BSPC, _____________SCAG_MODS____________
#   define ___________________NAV_R3__________________        KC_DEL,  KC_APP,  KC_VOLD, KC_VOLU, KC_MUTE
#   define          __________NAV_R4_________                 _________TRANS_R4________


/*
* auto shift takes care of the symbols not found here
* must manually press shift to get { and }
* tap hold % will give ^
*
*   ,----------------------------------.    ,----------------------------------.
*   | esc  | &    | @    | $    | %    |    | =    | #    | <    | >    | "    |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |enter | *    | !    | \    | ;    |    | bksp | /    | [    | ]    |repeat|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | undo | cut  | copy |paste | redo |    | del  | '    | ,    | .    | -    |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 |      | sym  |      |    |space | nav  |      |           
*                 `------+------+------'    `------+------+------'
*/
#   define _________________SYMBOL_L1_________________        KC_ESC,  KC_AMPR, KC_AT,   KC_DLR,  TR_PERC
#   define _________________SYMBOL_L2_________________        KC_ENT,  KC_ASTR, KC_EXLM, KC_BSLS, KC_SCLN
#   define _________________SYMBOL_L3_________________        _________________UCCPR_L___________________
#   define          ________SYMBOL_L4________                 _________TRANS_L4________

#   define _________________SYMBOL_R1_________________        KC_EQL,  KC_HASH, TR_LABK, KC_RABK, KC_GRV
#   define _________________SYMBOL_R2_________________        KC_BSPC, KC_SLSH, TR_LBRC, KC_RBRC, TR_REP
#   define _________________SYMBOL_R3_________________        KC_DEL,  KC_QUOT, TR_LPRN, TR_DOT,  KC_MINS
#   define          ________SYMBOL_R4________                 _________BASE_R4_________

/*
* tri layer: Activate this layer by holding down symbol and navigation
*
*   ,----------------------------------.    ,----------------------------------.
*   | 9    | 5    | 1    | 3    | 7    |    | 6    | 2    | 0    | 4    | 8    |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | gui  | alt  | ctrl | shft | f11  |    | bksp |space |      | f12  |repeat|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | f9   | f5   | f1   | f3   | f7   |    | f6   | f2   | f10  | f4   | f8   |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 |      | sym  |      |    |      | nav  |      |
*                 `------+------+------'    `------+------+------'
*/

#   define _________________NUMBER_L1_________________        KC_9,    KC_5,    KC_1,    KC_3,    KC_7
#   define _________________NUMBER_L2_________________        _____________GACS_MODS____________, KC_F11
#   define _________________NUMBER_L3_________________        KC_F9,   KC_F5,   KC_F1,   KC_F3,   KC_F7
#   define          ________NUMBER_L4________                 _________TRANS_L4________

#   define _________________NUMBER_R1_________________        KC_6,    KC_2,    KC_0,    KC_4,    KC_8
#   define _________________NUMBER_R2_________________        KC_BSPC, KC_SPC,  ___x___, KC_F12,  TR_REP
#   define _________________NUMBER_R3_________________        KC_F6,   KC_F2,   KC_F10,  KC_F4,   KC_F8
#   define          ________NUMBER_R4________                 _________TRANS_R4________


/*
* tri layer: Activate this layer by holding down symbol and mouse
*
*   ,----------------------------------.    ,----------------------------------.
*   |      |      | dmr1 | dmp1 |prnscr|    |      |      | boot |      |config|
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |rgbtog|rgbMod| dmr2 | dmp2 |scrlck|    | caps | shft | ctrl | alt  | gui  |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |rgbh+ |rgbs+ |rgbv+ |rgbsp+|paubrk|    |      |      |      |      |      |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 |gaming|clmkdh|qwerty|    |      | nav  |      |
*                 `------+------+------'    `------+------+------'
*/
#   define _________________CONFIG_L1_________________        ___x___, ___x___, TR_DMR1, TR_DMP1, KC_PSCR
#   define _________________CONFIG_L2_________________        TR_RTOG, TR_RMOD, TR_DMR2, TR_DMP2, KC_SCRL
#   define _________________CONFIG_L3_________________        TR_RHUI, TR_RSAI, TR_RVAI, TR_RSPI, KC_PAUS
#   define          ________CONFIG_L4________                 TR_GAME, CLMAKDH, QWERTY

#   define _________________CONFIG_R1_________________        ___x___, ___x___, QK_BOOT, ___x___, _______
#   define _________________CONFIG_R2_________________        KC_CAPS, _____________SCAG_MODS____________
#   define _________________CONFIG_R3_________________        __________________NONE_5___________________
#   define          ________CONFIG_R4________                 _________TRANS_R4________


/*
*   ,----------------------------------.    ,----------------------------------.
*   |      |      | mouu |      |wheelu|    | sdpi | dpi  |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |      | moul | moud | mour |wheeld|    |      | shft | ctrl | alt  | gui  |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |sniper| mb3  | mb2  | mb1  |drgscr|    |      | mb1  | mb2  | mb3  |      |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 |      |      | mou  |    | mb5  | mb4  |      |
*                 `------+------+------'    `------+------+------'
*/

#   define __________________MOUSE_L1_________________        ___x___, ___x___, TR_MOUU, ___x___, TR_MWHU
#   define __________________MOUSE_L2_________________        ___x___, TR_MOUL, TR_MOUD, TR_MOUR, TR_MWHD
#   define __________________MOUSE_L3_________________        TR_SNIP, TR_BTN3, TR_BTN2, TR_BTN1, TR_DRGS
#   define          _________MOUSE_L4________                 ___x___, ___x___, _______

#   define __________________MOUSE_R1_________________        TR_SDPI, TR_PDPI, ___x___, ___x___, ___x___
#   define __________________MOUSE_R2_________________        ___x___, _____________SCAG_MODS____________
#   define __________________MOUSE_R3_________________        ___x___, TR_BTN1, TR_BTN2, TR_BTN3, ___x___

#if defined(KEYBOARD_bastardkb_charybdis_3x5)
#   define          _________MOUSE_R4________                 TR_BTN5, TR_BTN4
#else
#   define          _________MOUSE_R4________                 TR_BTN5, TR_BTN4, ___x___
#endif

/*
*   ,----------------------------------.    ,----------------------------------.
*   | tab  | q    | w    | e    | r    |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | gnum | a    | s    | d    | f    |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | z    | x    | c    | v    | b    |    |      |      |      |      |      |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 | ctrl | spc  | shft |    |astog | nav  |      |
*                 `------+------+------'    `------+------+------'
*/
#   define _______________GAMING_BASE_L1______________        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R
#   define _______________GAMING_BASE_L2______________        GAMENUM, KC_A,    KC_S,    KC_D,    KC_F
#   define _______________GAMING_BASE_L3______________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#   define          ______GAMING_BASE_L4_____                 KC_LCTL, KC_SPC,  KC_LSFT

#   define _______________GAMING_BASE_R1______________        __________________NONE_5___________________
#   define _______________GAMING_BASE_R2______________        __________________NONE_5___________________
#   define _______________GAMING_BASE_R3______________        __________________NONE_5___________________

# if defined(KEYBOARD_bastardkb_charybdis_3x5) 
#   define          ______GAMING_BASE_R4_____                 TR_ASTG, NAV
# else
#   define          ______GAMING_BASE_R4_____                 TR_ASTG, NAV,     ___x___
# endif //KEYBOARD_bastardkb_charybdis_3x5


/*
*   ,----------------------------------.    ,----------------------------------.
*   |      | esc  | ~    | g    | t    |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   | gnum | 1    | 2    | 3    | 4    |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |      | 5    | 6    | 7    | 8    |    |      |      |      |      |      |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 | alt  |      | ent  |    |      |      |      |
*                 `------+------+------'    `------+------+------'
*/
#   define _______________GAMING_NUM_L1_______________        ___x___, KC_ESC,  KC_TILD, KC_G,    KC_T
#   define _______________GAMING_NUM_L2_______________        _______, KC_1,    KC_2,    KC_3,    KC_4
#   define _______________GAMING_NUM_L3_______________        ___x___, KC_5,    KC_6,    KC_7,    KC_8
#   define          ______GAMING_NUM_L4______                 KC_LALT, ___x___, KC_ENT


/*
*   ,----------------------------------.    ,----------------------------------.
*   |      |      |      |      |      |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |      |      |      |      |      |    |      |      |      |      |      |
*   +------+------+------+------+------|    +------+------+------+------+------+
*   |      |      |      |      |      |    |      |      |      |      |      |
*   `------+------+------+------+------+    +------+------+------+------+------'
*                 |      |      |      |    |      |      |      |
*                 `------+------+------'    `------+------+------'
*/