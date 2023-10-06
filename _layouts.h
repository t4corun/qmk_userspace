#pragma once

#define CNANO(k) L3x5_to_CharybdisNano(k)
#define L3x5_to_CharybdisNano( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36

#define PLANCK(k) L3x5_to_Planck4x12(k)
#define L3x5_to_Planck4x12( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
	k00,     k01,   k02,   k03, k04, KC_NO, KC_NO, k05, k06, k07,   k08,   k09, \
	k10,     k11,   k12,   k13, k14, KC_NO, KC_NO, k15, k16, k17,   k18,   k19, \
	k20,     k21,   k22,   k23, k24, KC_NO, KC_NO, k25, k26, k27,   k28,   k29, \
	TR_ATOG, KC_NO, KC_NO, k32, k33, k34,   k35,   k36, k37, KC_NO, KC_NO, KC_ESC

#define CRKBD(k) L3x5_to_Corne3x6(k)
#define L3x5_to_Corne3x6( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
	KC_NO, k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, KC_NO, \
	KC_NO, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, KC_NO, \
	KC_NO, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, KC_NO, \
	                 k32, k33, k34, k35, k36, k37                   \


#define LAYOUT_planck_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_cnano_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
#define LAYOUT_crkbd_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

