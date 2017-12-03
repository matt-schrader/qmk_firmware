#include "levinson.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


enum haxix_layers {
	QWERTY_LAYER,
	LOWER_LAYER,
	RAISE_LAYER,
	NAV_LAYER,
	ADJUST_LAYER
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
	NAV,
	SEND_VERSION
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------.
 * | `      |   Q    |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P      | Bksp    |
 * |--------+--------+------+------+------+-------------+------+------+------+----------+---------|
 * | Tab    |   A    |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;      | Enter   |
 * |--------+--------+------+------+------+------|------+------+------+------+----------+---------|
 * | Shift (|   Z    |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /      | Shift ) |
 * |--------+--------+------+------+------+------+------+------+------+------+----------+---------|
 * | {      | Ctrl [ | Alt  | GUI  |Space |Lower |Raise |Space | GUI  | Alt  |  Ctrl ]  | }       |
 * `----------------------------------------------------------------------------------------------'
 */
[QWERTY_LAYER] = KEYMAP( \
  KC_GRV,   KC_Q,                 KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                 KC_BSPC, \
  KC_TAB,   KC_A,                 KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,              KC_ENT,  \
  KC_LSPO,  KC_Z,                 KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,              KC_RSPC, \
  KC_LCBR,  MT(MOD_LCTL,KC_LBRC), KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_SPC,  KC_RGUI, KC_RALT, MT(MOD_LCTL,KC_RBRC), KC_RCBR  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   \  |   |  | Del  |
 * |      |  1   |  2   |  3   |  4   |  5   |   _  |   "  |      |      |      |      |
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |      |
 * |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER_LAYER] = KEYMAP( \
	KC_ESC,  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE , KC_DEL, \
	_______, KC_1,    KC_2 , KC_3,    KC_4,    KC_5,    KC_UNDS, KC_QUOT, _______, _______, _______, _______, \
	KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, _______, \
	KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  _______,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  UP  |      |      |      |  /   |  7   |  8   |  9   |  *   |      |
 * |      | LEFT | DOWN | RGHT |      |      |  -   |  4   |  5   |  6   |  +   |      |
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |  =   |      |
 * |      |      |      |      |      |      |      |      |  0   |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE_LAYER] = KEYMAP( \
	_______, _______, KC_UP  , _______, _______, _______, KC_PSLS, KC_7,    KC_8,   KC_9,    KC_PAST, _______,  \
	_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_PMNS, KC_4,    KC_5,   KC_6,    KC_PPLS, _______,  \
	_______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,   KC_3,    KC_PEQL, _______,  \
	_______, _______, _______, _______, _______, _______, _______, _______, KC_0,   KC_DOT, _______, _______   \
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NAV_LAYER] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST_LAYER] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<QWERTY_LAYER);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      } else {
        layer_off(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      } else {
        layer_off(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      }
      return false;
      break;
		case NAV:
			if (record->event.pressed) {
				layer_on(NAV_LAYER);
			} else {
				layer_off(NAV_LAYER);
			}
    case ADJUST:
      if (record->event.pressed) {
        layer_on(ADJUST_LAYER);
      } else {
        layer_off(ADJUST_LAYER);
      }
      return false;
      break;
  }
  return true;
}
